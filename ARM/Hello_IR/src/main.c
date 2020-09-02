/*
 * main.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Omar Gamal
 */

/* Library layer includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**************************/

/* MCAL layer includes */
#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "SCB_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "IR_interface.h"
/***********************/

#define RED_PIN							GPIO_U8_PIN1
#define GREEN_PIN						GPIO_U8_PIN2
#define BLUE_PIN						GPIO_U8_PIN3


void GetFrame(void){

	GPIO_voidTogPinVal(GPIO_U8_PORTA,GREEN_PIN);

}


void main(void){
	/* RCC Initialization */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,0);					/* AFIO clock enable */
	/**********************/

	/* NVIC Initialization */
	MNVIC_voidInit();
	MNVIC_voidSetPriorityValue(6,1,0);
	/***********************/

	/* EXTI Initialization */
	MEXTI_voidSetCallBack(GetFrame,0);
	MNVIC_voidEXTIEnControl(6, MNVIC_U8_ENABLE);	/* Enables External interrupt for EXTI */
	/***********************/


	GPIO_voidAllPortsInit();								/* PORTA clock enable */
	/* IO pins Initialization */
	/* A0 Pin: Input */
	GPIO_voidSetPinMode(GPIO_U8_PORTA,GPIO_U8_PIN0,GPIO_U8_INPUT_MODE_PULLING_ENABLED,GPIO_U8_PIN_MODE_INPUT);
	GPIO_voidSetPinPullingState(GPIO_U8_PORTA,GPIO_U8_PIN0,GPIO_U8_PULL_UP);
	/* A1 Pin: Output */
	GPIO_voidSetPinMode(GPIO_U8_PORTA,RED_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	/* A2 Pin: Output */
	GPIO_voidSetPinMode(GPIO_U8_PORTA,GREEN_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	/* A3 Pin: Output */
	GPIO_voidSetPinMode(GPIO_U8_PORTA,BLUE_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	/*************************/

	MEXTI_voidInit(GPIO_U8_PORTA,0,MEXTI_U8_FALLING_EDGE_TRIGGER);

	/* STK Initialization */
	MSTK_voidSTKInit();
	/**********************/


	while(1){

	}

}















