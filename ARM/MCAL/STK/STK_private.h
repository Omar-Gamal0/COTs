/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 27 August 2020						*/
/************************************************/


#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/* Defining Systick register definition structure data type */
typedef struct {
	__V	u32 CTRL; 	/* SysTick control and status register */
	__V	u32 LOAD; 	/* SysTick reload value register */
	__V	u32 VAL; 	/* SysTick current value register */
	__V	u32 CALIB; 	/* SysTick calibration value register */
} STK_RegDef_t;
/************************************************************/

/* Defining Macro that would be used to access STK Registers */
#define STK ((STK_RegDef_t*)(0xE000E010))
/*************************************************************/

/* PRIVATE variables */
u8 STK_u8PvtIntervalState = 0;
/*********************/

void (* CallBack)(void);				/* Pointer to function to be used as call back function */

/************************/



#endif
