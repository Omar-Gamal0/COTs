/* FILENAME: ADC_program 
*  Author:  Omar Gamal
*  Version:  V1.0
*  DATE:   Thu 09/24/2020
*/

/*
	The total conversion time is calculated as follows:
	Tconv(cycles) = Sampling time (cycles) + 12.5
*/

/* LIB layer includes*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************/

/* ADC includes */
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
/****************/

void ADC1_voidInit(void)
{
	/* Configuring CR1 */
	ADC1 -> CR1 = 0;
	SET_BITS_VAL((ADC1 -> CR1), AWDCH   , ADC_U8_AWDCH				);	/* Selecting Analog watchdog channel 										*/
	SET_BITS_VAL((ADC1 -> CR1), EOCIE   , ADC_U8_EOCIE				);	/* Setting value of Interrupt enable for EOC 								*/
	SET_BITS_VAL((ADC1 -> CR1), AWDIE   , ADC_U8_AWDIE				);	/* Setting value of Analog watchdog interrupt enable 						*/
	SET_BITS_VAL((ADC1 -> CR1), JEOCIE  , ADC_U8_JEOCIE				);	/* Setting value of Interrupt enable for injected channels 					*/
	SET_BITS_VAL((ADC1 -> CR1), SCAN    , ADC_U8_SCAN				);	/* Setting Scan mode 														*/
	SET_BITS_VAL((ADC1 -> CR1), AWDSGL  , ADC_U8_AWDSGL   			);	/* Enable/Disable the watchdog on a single channel in scan mode 			*/
	SET_BITS_VAL((ADC1 -> CR1), JAUTO   , ADC_U8_JAUTO				);	/* Setting value of Automatic Injected Group conversion enable 				*/
	SET_BITS_VAL((ADC1 -> CR1), DISCEN  , ADC_U8_DISCEN	    		);	/* Setting value of Discontinuous mode on regular channels 					*/
	SET_BITS_VAL((ADC1 -> CR1), JDISCEN , ADC_U8_JDISCEN			);	/* Setting value of Discontinuous mode on injected channels 				*/
	SET_BITS_VAL((ADC1 -> CR1), DISCNUM , ADC_U8_DISCNUM			);	/* Setting value of Discontinuous mode channel count 						*/
	SET_BITS_VAL((ADC1 -> CR1), DUALMOD , ADC_U8_DUALMOD			);	/* Setting value of Dual mode selection 									*/
	SET_BITS_VAL((ADC1 -> CR1), AWDEN   , ADC_U8_AWDEN				);	/* Setting value of Analog watchdog enable on regular channels				*/
	SET_BITS_VAL((ADC1 -> CR1), JAWDEN  , ADC_U8_JAWDEN 			);	/* Setting value of Analog watchdog enable on injected channels 			*/
	/*******************/

	/* Configuring CR2 */
	ADC1 -> CR2 = 0;
	SET_BITS_VAL((ADC1 -> CR2), CONT    , ADC_U8_CONT				);	/* Setting value of Continuous conversion 									*/
	SET_BITS_VAL((ADC1 -> CR2), CAL     , ADC_U8_CAL				);	/* Setting value of A/D Calibration 										*/
	SET_BITS_VAL((ADC1 -> CR2), RSTCAL  , ADC_U8_RSTCAL				);	/* Setting value of Reset calibration 										*/
	SET_BITS_VAL((ADC1 -> CR2), DMA     , ADC_U8_DMA				);	/* Setting value of Direct memory access mode 								*/
	SET_BITS_VAL((ADC1 -> CR2), ALIGN   , ADC_U8_ALIGN				);	/* Setting value of Data alignment			 								*/
	SET_BITS_VAL((ADC1 -> CR2), JEXTSEL , ADC_U8_JEXTSEL			);	/* Setting value of External event select for injected group				*/
	SET_BITS_VAL((ADC1 -> CR2), JEXTTRIG, ADC_U8_JEXTTRIG			);	/* Setting value of External trigger conversion mode for injected channels	*/
	SET_BITS_VAL((ADC1 -> CR2), EXTSEL 	, ADC_U8_EXTSEL				);	/* Setting value of External event select for regular group					*/
	SET_BITS_VAL((ADC1 -> CR2), EXTTRIG , ADC_U8_EXTTRIG			);	/* Setting value of External trigger conversion mode for regular channels	*/
	SET_BITS_VAL((ADC1 -> CR2), TSVREFE , ADC_U8_TSVREFE			);	/* Setting value of Temperature sensor and V_REFINT enable					*/
	/*******************/

	/* Configuring SMPR2 */
	ADC1 -> SMPR[1] = 0;
	SET_BITS_VAL((ADC1 -> SMPR[1]), SMP0, ADC_U8_SMP0				);	/* Setting value of Channel 0 Sample time selection							*/
	/*********************/

	/* Configuring SQR1 */
	ADC1 -> SQR[0] = 0;
	SET_BITS_VAL((ADC1 -> SQR[0]), 0, ADC_U8_REGULAR_SEQUENCE_LENGTH);	/* Setting value of Regular Squence length									*/
	/*********************/

	/* Configuring SQR3 */
	ADC1 -> SQR[2] = 0;
	SET_BITS_VAL((ADC1 -> SQR[2]), SQ1  , ADC_U8_CH0				);	/* Setting value of first conversion in regular sequence					*/
	/*********************/

	SET_BITS_VAL((ADC1 -> CR2), ADON 	, ADC_U8_ENABLE				);	/* Turning ON ADC1															*/

}

void ADC1_voidStartConv(void)
{
	SET_BITS_VAL((ADC1 -> CR2), ADON 	, ADC_U8_ENABLE				);	/* Turning ON ADC1															*/
}

void ADC1_voidSetThresholds(u16 Cpy_u16LowThreshold, u16 Cpy_u16HighThreshold)
{
	ADC1 -> HTR = Cpy_u16HighThreshold;
	ADC1 -> LTR = Cpy_u16LowThreshold;
}

u16 ADC1_u16GetRegularVal(void)
{
	u16 Loc_u16RegularVal = ADC1 -> DR;
	return Loc_u16RegularVal;
}

void ADC1_SetAWDCallBack(void (*CallBack) (void))
{
	ADC1_voidAWDCallBack = CallBack;
}

void ADC1_SetEOCCallBack(void (*CallBack) (void))
{
	ADC1_voidEOCCallBack = CallBack;
}

void ADC1_2_IRQHandler(void)
{
	if ((GET_BIT((ADC1 -> SR), AWD)) == 1)
	{
		CLR_BIT((ADC1 -> SR), AWD);
		ADC1_voidAWDCallBack();
	}else if((GET_BIT((ADC1 -> SR), EOC)) == 1)
	{
		CLR_BIT((ADC1 -> SR), EOC);
		ADC1_voidEOCCallBack();
	}
}


