/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 09 Sept 2020							*/
/************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Sine_interface.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "Silence.h"

#include "DAC_config.h"
#include "DAC_interface.h"
#include "DAC_private.h"

volatile u16 i;

void DAC_voidSetArrDAC(void){
	if(i<DAC_U32_NO_OF_INPUT_SAMPLES){
		GPIO_voidSetPinVal(DAC_U8_BIT0_PORT, DAC_U8_BIT0_PIN,GET_BIT(Call_Of_Silence_raw[i],0));
		GPIO_voidSetPinVal(DAC_U8_BIT1_PORT, DAC_U8_BIT1_PIN,GET_BIT(Call_Of_Silence_raw[i],1));
		GPIO_voidSetPinVal(DAC_U8_BIT2_PORT, DAC_U8_BIT2_PIN,GET_BIT(Call_Of_Silence_raw[i],2));
		GPIO_voidSetPinVal(DAC_U8_BIT3_PORT, DAC_U8_BIT3_PIN,GET_BIT(Call_Of_Silence_raw[i],3));
		GPIO_voidSetPinVal(DAC_U8_BIT4_PORT, DAC_U8_BIT4_PIN,GET_BIT(Call_Of_Silence_raw[i],4));
		GPIO_voidSetPinVal(DAC_U8_BIT5_PORT, DAC_U8_BIT5_PIN,GET_BIT(Call_Of_Silence_raw[i],5));
		GPIO_voidSetPinVal(DAC_U8_BIT6_PORT, DAC_U8_BIT6_PIN,GET_BIT(Call_Of_Silence_raw[i],6));
		GPIO_voidSetPinVal(DAC_U8_BIT7_PORT, DAC_U8_BIT7_PIN,GET_BIT(Call_Of_Silence_raw[i],7));

		i++;
		}else{
			i=0;
		}
}
void DAC_voidSetFuncDAC(void){
	static f32 Loc_f32angle=0;
	f32 Loc_f32Val = 0;
	u8 Loc_u8AnalogVal = 0;

	if(i<DAC_U32_NO_OF_INPUT_SAMPLES){
		Loc_f32angle = i*DAC_f32InputStepSize;
		Loc_f32Val = 1 + Sine_f32GetSineRes(Loc_f32angle);
		if((Loc_f32Val/DAC_U32_OUTPUT_STEP_SIZE) < DAC_U32_NO_OF_OUTPUT_SAMPLES){
			Loc_u8AnalogVal = (Loc_f32Val/DAC_U32_OUTPUT_STEP_SIZE);
		}else{
			Loc_u8AnalogVal = DAC_f32InputStepSize - 1;
		}

		GPIO_voidSetPinVal(DAC_U8_BIT0_PORT, DAC_U8_BIT0_PIN,GET_BIT(Loc_u8AnalogVal,0));
		GPIO_voidSetPinVal(DAC_U8_BIT1_PORT, DAC_U8_BIT1_PIN,GET_BIT(Loc_u8AnalogVal,1));
		GPIO_voidSetPinVal(DAC_U8_BIT2_PORT, DAC_U8_BIT2_PIN,GET_BIT(Loc_u8AnalogVal,2));
		GPIO_voidSetPinVal(DAC_U8_BIT3_PORT, DAC_U8_BIT3_PIN,GET_BIT(Loc_u8AnalogVal,3));
		GPIO_voidSetPinVal(DAC_U8_BIT4_PORT, DAC_U8_BIT4_PIN,GET_BIT(Loc_u8AnalogVal,4));
		GPIO_voidSetPinVal(DAC_U8_BIT5_PORT, DAC_U8_BIT5_PIN,GET_BIT(Loc_u8AnalogVal,5));
		GPIO_voidSetPinVal(DAC_U8_BIT6_PORT, DAC_U8_BIT6_PIN,GET_BIT(Loc_u8AnalogVal,6));
		GPIO_voidSetPinVal(DAC_U8_BIT7_PORT, DAC_U8_BIT7_PIN,GET_BIT(Loc_u8AnalogVal,7));

		i++;
		}else{
			i=0;
		}
}

void DAC_voidInit(void){

	GPIO_voidSetPinMode(DAC_U8_BIT0_PORT, DAC_U8_BIT0_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX10MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT1_PORT, DAC_U8_BIT1_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX10MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT2_PORT, DAC_U8_BIT2_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX10MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT3_PORT, DAC_U8_BIT3_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX10MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT4_PORT, DAC_U8_BIT4_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX10MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT5_PORT, DAC_U8_BIT5_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX10MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT6_PORT, DAC_U8_BIT6_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX10MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT7_PORT, DAC_U8_BIT7_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX10MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */

	DAC_f32InputStepSize = 2*SINE_F32_PI/DAC_U32_NO_OF_INPUT_SAMPLES;

}

void DAC_voidStart(u8 Cpy_u8DataType){
	i=0;
	switch(Cpy_u8DataType){
	case DAC_U8_ARRAY: MSTK_voidSetPeriodicInterval(DAC_U32_TIME_INTERVAL,STK_U8_MICROS,DAC_voidSetArrDAC); break;
	case DAC_U8_FUNC: MSTK_voidSetPeriodicInterval(DAC_U32_TIME_INTERVAL,STK_U8_MICROS,DAC_voidSetFuncDAC); break;
	}

}

