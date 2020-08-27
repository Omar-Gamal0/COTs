/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 25 August 2020						*/
/************************************************/

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

/* Defining Systick register definition structure data type */
typedef struct {
	__V	u32 CTRL; /* SysTick control and status register */
	__V	u32 LOAD; /* SysTick reload value register */
	__V	u32 VAL; /* SysTick current value register */
	__V	u32 CALIB; /* SysTick calibration value register */
} Systic_RegDef_t;

/* Systick Macros definitions */

/* SysTick control and status register Macros */

/* STK_CTRL Bits Macros */

#define SYSTICK_U8_COUNTFLAG_BIT 			16		/* Returns 1 if timer counted to 0 since last time this was read */
#define SYSTICK_U8_CLKSOURCE_BIT			2		/* Clock source selection */
#define SYSTICK_U8_TICKINT_BIT				1		/* SysTick exception request enable */
#define SYSTICK_U8_COUNTER_EN_BIT			0		/* Counter enable */

/************************/

/* STK_CTRL Other Macros */

/* Clock source selection related Macros */

#define SYSTICK_U8_CLKSOURCE_AHB_8			0		/* Selects the clock source as AHB/8 					*/
#define SYSTICK_U8_CLKSOURCE_AHB				1		/* Selects the clock source as AHB (Processor clock) 	*/

/*****************************************/

/* SysTick exception request enabling related Macros */

#define SYSTICK_U8_TICKINT_DIS				0		/* Counting down to zero does not assert the SysTick exception request 	*/
#define SYSTICK_U8_TICKINT_EN				1		/* Counting down to zero to asserts the SysTick exception request 		*/

/*****************************************************/

/* Counter enabling related Macros */

#define SYSTICK_U8_COUNTER_DIS				0		/* Counter disabled */
#define SYSTICK_U8_COUNTER_EN				1		/* Counter enabled  */

/***********************************/

/*************************/

/**********************************************/

/*****************************/

/* Global functions */


/* Macro like functions */

/* Msystick_voidTICKINT --> Selects Clock source for Systick counter 	*/
/* I/P: Cpy_u8EnOrDis: Available options:-
 * 											SYSTICK_U8_CLKSOURCE_AHB_8
 * 											SYSTICK_U8_CLKSOURCE_AHB 	*/
/* O/P: void 															*/

#define Msystick_voidCLKSOURCE(Cpy_u8ClkSource)	do{	( SYSTICK -> CTRL &= ~(0x01 << SYSTICK_U8_CLKSOURCE_BIT) );\
													( SYSTICK -> CTRL |= (Cpy_u8ClkSource << SYSTICK_U8_CLKSOURCE_BIT) );\
												}while(0)
/************************************************************************/

/* Msystick_voidTICKINT --> Enables or disables SysTick exception request	*/
/* I/P: Cpy_u8EnOrDis: Available options:-
 * 											SYSTICK_U8_TICKINT_DIS
 * 											SYSTICK_U8_TICKINT_EN	 		*/
/* O/P: void 																*/

#define Msystick_voidTICKINT(Cpy_u8EnOrDis)	do{	( SYSTICK -> CTRL &= ~(0x01 << SYSTICK_U8_TICKINT_BIT) );\
												( SYSTICK -> CTRL |= (Cpy_u8EnOrDis << SYSTICK_U8_TICKINT_BIT) );\
												}while(0)
/****************************************************************************/

/* Msystick_voidCounter_En_Dis --> Enables or disables SysTick counter	*/
/* I/P: Cpy_u8EnOrDis: Available options:-
 * 											SYSTICK_U8_COUNTER_DIS
 * 											SYSTICK_U8_COUNTER_EN	 	*/
/* O/P: void 															*/
#define Msystick_voidCounter_En_Dis(Cpy_u8EnOrDis)	do{	( SYSTICK -> CTRL &= ~(0x01 << SYSTICK_U8_COUNTER_EN_BIT) );\
													( SYSTICK -> CTRL |= (Cpy_u8EnOrDis << SYSTICK_U8_COUNTER_EN_BIT) );\
												}while(0)
/************************************************************************/

/* MSystick_voidLoadVal --> Reloads SysTick counter	value 	*/
/* I/P: Cpy_u32LoadVal : Value to be reloaded 				*/
/* O/P: void 												*/

#define MSystick_voidLoadVal(Cpy_u32LoadVal)	SYSTICK -> LOAD = Cpy_u32LoadVal
/************************************************************/

/************************/

/* Normal functions */

/* MSystic_voidInit --> Initializes Systick with:- 	Selected Clock source &
 * 													Selected SysTick exception request enabling state
 * 													Selected Counter enable  							*/
/* I/P: void 																							*/
/* O/P: void 																							*/
void MSystick_voidInit(void);
/********************************************************************************************************/

/* MSystick_u32CurrentVal --> Returns Current value of SysTick counter   		*/
/* I/P: void															 		*/
/* O/P: Loc_u32SysTickCounterVal:- Current value of SysTick counter (Type: u32) */
u32 MSystick_u32CurrentVal(void);
/********************************************************************************/

/* MSystick_voidDelay --> Stops the processor for a certain amount of time 	*/
/* I/P:- Cpy_u32DelayVal: The time for which the processor is to be stopped	*/
/* O/P:- void																*/
void MSystick_voidDelay(u32 Cpy_u32DelayVal);
/****************************************************************************/

/********************/

/********************/
#endif /* SYSTICK_INTERFACE_H_ */
