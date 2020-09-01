/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 26 August 2020						*/
/************************************************/

/* Library layer includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**************************/

/* MCAL layer includes */
#include "RCC_interface.h"
#include "STK_interface.h"
#include "SCB_interface.h"
#include "NVIC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "EXTI_interface.h"
/***********************/

void callTog(){
	GPIO_voidTogPinVal(GPIO_U8_PORTA, GPIO_U8_PIN1);
}

void main(void){

	/* Initializing used peripherals */
	RCC_voidInitSysClock();												/* Initializes SYSCLK, Enabling and selecting the needed SYSCLK source and selecting the value of PLL if used */
	MSTK_voidSTKInit();													/* Initializes Systick */
	MNVIC_voidInit();													/* Initializes NVIC by Setting Bits options to control group and sub priority distribution */
	MNVIC_voidEXTIEnControl(0, MNVIC_U8_ENABLE);						/* Enables External interrupt for EXTI0 */
	MNVIC_voidSetPriorityValue(6,1,0);									/* Sets interrupt group & sub priorities */
	GPIO_voidPORTA_Init();												/* Enables clock for PortA, sets all pins' outputs of PortA to low */

	/*********************************/

	/* Initializing GPIO used pins */
	/* Input pins */
	GPIO_voidSetPinMode(GPIO_U8_PORTA,GPIO_U8_PIN0,GPIO_U8_INPUT_MODE_PULLING_ENABLED,GPIO_U8_PIN_MODE_INPUT);
	GPIO_voidSetPinPullingState(GPIO_U8_PORTA, GPIO_U8_PIN0,GPIO_U8_PULL_UP);
	/**************/

	/* Output pins */
	GPIO_voidSetPinMode(GPIO_U8_PORTA,GPIO_U8_PIN1,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidPortLock(GPIO_U8_PORTA);
	/***************/

	/*******************************/

	//MEXTI_voidInit(GPIO_U8_PORTA,0,MEXTI_U8_FALLING_EDGE_TRIGGER);		/* Initializes EXTI0 */


	MSTK_voidSetPeriodicInterval(1000000,STK_U8_MICROS,callTog);
	MSTK_voidSetPeriodicInterval(5,STK_U8_SECONDS,MSTK_voidStopTimer);
	while(1){

	}

}


void EXTI0_IRQHandler(void){

	GPIO_voidSetPinMode(GPIO_U8_PORTA,GPIO_U8_PIN1,GPIO_U8_INPUT_MODE_FLOATING,GPIO_U8_PIN_MODE_INPUT);
	MEXTI_voidClrPR(0);
	GPIO_voidTogPinVal(GPIO_U8_PORTA, GPIO_U8_PIN1);

}
