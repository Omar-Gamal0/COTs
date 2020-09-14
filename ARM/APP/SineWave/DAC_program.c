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
	GPIO_voidSetPinVal(DAC_U8_BIT0_PORT, DAC_U8_BIT0_PIN,GET_BIT(Call_Of_Silence_raw[i],0));
	GPIO_voidSetPinVal(DAC_U8_BIT1_PORT, DAC_U8_BIT1_PIN,GET_BIT(Call_Of_Silence_raw[i],1));
	GPIO_voidSetPinVal(DAC_U8_BIT2_PORT, DAC_U8_BIT2_PIN,GET_BIT(Call_Of_Silence_raw[i],2));
	GPIO_voidSetPinVal(DAC_U8_BIT3_PORT, DAC_U8_BIT3_PIN,GET_BIT(Call_Of_Silence_raw[i],3));
	GPIO_voidSetPinVal(DAC_U8_BIT4_PORT, DAC_U8_BIT4_PIN,GET_BIT(Call_Of_Silence_raw[i],4));
	GPIO_voidSetPinVal(DAC_U8_BIT5_PORT, DAC_U8_BIT5_PIN,GET_BIT(Call_Of_Silence_raw[i],5));
	GPIO_voidSetPinVal(DAC_U8_BIT6_PORT, DAC_U8_BIT6_PIN,GET_BIT(Call_Of_Silence_raw[i],6));
	GPIO_voidSetPinVal(DAC_U8_BIT7_PORT, DAC_U8_BIT7_PIN,GET_BIT(Call_Of_Silence_raw[i],7));

	if(i<DAC_U32_NO_OF_INPUT_SAMPLES){
		i++;
	}else{
		i=0;
	}
}

void voidSetDAC(void){
		//MGPIO_PORTA->ODR = Call_Of_Silence_raw[i];
		GPIO_voidSetPinVal(GPIO_U8_PORTA, GPIO_U8_PIN0,GET_BIT(Call_Of_Silence_raw[i],0));
		GPIO_voidSetPinVal(GPIO_U8_PORTA, GPIO_U8_PIN1,GET_BIT(Call_Of_Silence_raw[i],1));
		GPIO_voidSetPinVal(GPIO_U8_PORTA, GPIO_U8_PIN2,GET_BIT(Call_Of_Silence_raw[i],2));
		GPIO_voidSetPinVal(GPIO_U8_PORTA, GPIO_U8_PIN3,GET_BIT(Call_Of_Silence_raw[i],3));
		GPIO_voidSetPinVal(GPIO_U8_PORTA, GPIO_U8_PIN4,GET_BIT(Call_Of_Silence_raw[i],4));
		GPIO_voidSetPinVal(GPIO_U8_PORTA, GPIO_U8_PIN5,GET_BIT(Call_Of_Silence_raw[i],5));
		GPIO_voidSetPinVal(GPIO_U8_PORTA, GPIO_U8_PIN6,GET_BIT(Call_Of_Silence_raw[i],6));
		GPIO_voidSetPinVal(GPIO_U8_PORTA, GPIO_U8_PIN7,GET_BIT(Call_Of_Silence_raw[i],7));

		if(i<39999){
			i++;
		}else{
			i=0;
		}
}

void DAC_voidSetFuncDAC(void){
	f32 Loc_f32angle=0;
	f32 Loc_f32Val = 0;
	f32 Loc_f32TempAnalogVal = 0;
	u8 Loc_u8AnalogVal = 0;
	u8 x = 0;
	if(i<DAC_U32_NO_OF_INPUT_SAMPLES){
		Loc_f32angle = i*DAC_f32InputStepSize;
		Loc_f32Val = 1 + Sine_f32GetSineRes(Loc_f32angle);
		Loc_f32TempAnalogVal = (Loc_f32Val/DAC_U32_OUTPUT_STEP_SIZE);

		if(Loc_f32TempAnalogVal < DAC_U32_NO_OF_OUTPUT_SAMPLES){
			Loc_u8AnalogVal = Loc_f32TempAnalogVal;
		}else{
			Loc_u8AnalogVal = DAC_U32_NO_OF_OUTPUT_SAMPLES - 1;
		}

		if(Loc_u8AnalogVal == 0 ){
			x = Loc_f32Val;
			GPIO_voidSetPinVal(GPIO_U8_PORTB, DAC_U8_BIT0_PIN,GET_BIT(Loc_u8AnalogVal,0));
			x = Loc_f32Val;
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
	switch(Cpy_u8DataType){
	case DAC_U8_ARRAY: MSTK_voidSetPeriodicInterval(DAC_U32_TIME_INTERVAL,STK_U8_MICROS,DAC_voidSetArrDAC); break;
	//case DAC_U8_ARRAY: MSTK_voidSetPeriodicInterval(DAC_U32_TIME_INTERVAL,STK_U8_MICROS,voidSetDAC); break;

	case DAC_U8_FUNC: MSTK_voidSetPeriodicInterval(DAC_U32_TIME_INTERVAL,STK_U8_MICROS,DAC_voidSetFuncDAC); break;
	}

}

