/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 09 Sept 2020							*/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"

#include "Silence.h"

volatile u16 i;

void DAC_voidSetDAC(void){
	if(i<DAC_U32_NO_OF_SAMPLES){
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

void DAC_voidInit(void){

	GPIO_voidSetPinMode(DAC_U8_BIT0_PORT, DAC_U8_BIT0_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT1_PORT, DAC_U8_BIT1_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT2_PORT, DAC_U8_BIT2_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT3_PORT, DAC_U8_BIT3_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT4_PORT, DAC_U8_BIT4_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT5_PORT, DAC_U8_BIT5_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT6_PORT, DAC_U8_BIT6_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */
	GPIO_voidSetPinMode(DAC_U8_BIT7_PORT, DAC_U8_BIT7_PIN, GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);												/* Sets Pin1 of PortA as output with maximum frequency of 10 MHZ and General purpose Push-pull */

}
