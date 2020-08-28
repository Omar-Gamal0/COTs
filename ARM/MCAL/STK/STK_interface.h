/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 27 August 2020						*/
/************************************************/


#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H





/* STK Macros definitions */

/* STK control and status register Macros */

/* STK_CTRL Bits Macros */

#define STK_U8_COUNTFLAG_BIT 			16		/* Returns 1 if timer counted to 0 since last time this was read */
#define STK_U8_CLKSOURCE_BIT			2		/* Clock source selection */
#define STK_U8_TICKINT_BIT				1		/* STK exception request enable */
#define STK_U8_COUNTER_EN_BIT			0		/* Counter enable */

/************************/

/* STK_CTRL Other Macros */

/* Clock source selection related Macros */

#define STK_U8_CLKSOURCE_AHB_8			0		/* Selects the clock source as AHB/8 					*/
#define STK_U8_CLKSOURCE_AHB			1		/* Selects the clock source as AHB (Processor clock) 	*/

/*****************************************/

/* STK exception request enabling related Macros */

#define STK_U8_TICKINT_DIS				0		/* Counting down to zero does not assert the STK exception request 	*/
#define STK_U8_TICKINT_EN				1		/* Counting down to zero to asserts the STK exception request 		*/

/*************************************************/

/* Counter enabling related Macros */

#define STK_U8_COUNTER_DIS				0		/* Counter disabled */
#define STK_U8_COUNTER_EN				1		/* Counter enabled  */

/***********************************/

/*************************/

/*****************************************/

/* Wait value type Macros */
#define STK_U8_TICKS 					0		
#define STK_U8_MILLIS 					1
#define STK_U8_MICROS 					2
#define STK_U8_SECONDS 					3
/**************************/

/* Wait value divider Macros */
#define STK_U8_MILLIS_DIVIDER			1000	/* Value used to calculate Load value in the wait functions when the wait value is in milliseconds */
#define STK_U8_MICROS_DIVIDER			1000000	/* Value used to calculate Load value in the wait functions when the wait value is in microseconds */
/*****************************/

/* Interval Macros definitions */
#define STK_U8_SINGLE_INTERVAL			0
#define STK_U8_PERIODIC_INTERVAL		1
/*******************************/

/**************************/

/* Global functions */


/* Normal functions */

/* STK_voidSTKInit --> Selects Clock source for STK counter 	*/
/* I/P: void 													*/
/* O/P: void 													*/
void MSTK_voidSTKInit(void);
/****************************************************************/

/* MSTK_voidTICKInterrupt --> Enables or disables STK interrupt request	*/
/* I/P: Cpy_u8EnOrDis: Available options:-
 * 											STK_U8_TICKINT_DIS
 * 											STK_U8_TICKINT_EN	 		*/
/* O/P: void 															*/
void MSTK_voidTICKInterrupt(u8 Cpy_u8EnOrDis);
/************************************************************************/

/* MSTK_voidCounterEnDis --> Enables or disables STK counter	*/
/* I/P: Cpy_u8EnOrDis: Available options:-
 * 											STK_U8_COUNTER_DIS
 * 											STK_U8_COUNTER_EN	*/
/* O/P: void 													*/
void MSTK_voidCounterEnDis(u8 Cpy_u8EnOrDis);
/****************************************************************/

/* MSTK_voidLoadVal --> Reloads STK counter value 	*/
/* I/P: Cpy_u32LoadVal : Value to be reloaded 		*/
/* O/P: void 										*/

void MSTK_voidLoadVal(u32 Cpy_u32LoadVal);
/****************************************************/

/* MSTK_u32CurrentVal --> Returns Current value of STK counter  */
/* I/P: void													*/
/* O/P: Current value of STK counter (Type: u32) 				*/
u32 MSTK_u32CurrentVal(void);
/****************************************************************/



/* MSTK_voidSetBusyWait: Starts a busy wait for a certain time determined by the arguments before calling the callback function	*/
/* I/P: - 	Cpy_u32DelayVal:	* Value of delay needed to be done
								* Type: u32
								* Available options: 1 : (2^32)
			
			Cpy_u8ValueType: 	* Type of delay value 
								* Type: u8
								* Available options: 
														- STK_U8_TICKS
														- STK_U8_MILLIS
														- STK_U8_MICROS
														- STK_U8_SECONDS
			(*func)(void): 		* Function to be which is to be called back after the busy wait
								* Return type: void
								* Available functions:
								* 				- Functions that have (void return type && void parameters)
																							*/
/* O/P: void 																				*/
void MSTK_voidSetBusyWait(u32 Cpy_u32DelayVal, u8 Cpy_u8ValueType, void (*func)(void));
/********************************************************************************************/

/* MSTK_voidSetSingleInterval: Starts a single interval for a certain time determined by the arguments before calling the callback function */
/* I/P: - 	Cpy_u32DelayVal:	* Value of delay needed to be done
								* Type: u32
								* Available options: 1 : (2^32)

			Cpy_u8ValueType: 	* Type of delay value
								* Type: u8
								* Available options:
														- STK_U8_TICKS
														- STK_U8_MILLIS
														- STK_U8_MICROS
														- STK_U8_SECONDS
			(*func)(void): 		* Function to be which is to be called back after the busy wait
								* Return type: void
								* Available functions:
								* 				- Functions that have (void return type && void parameters)
																							*/
/* O/P: void 																				*/
void MSTK_voidSetSingleInterval(u32 Cpy_u32DelayVal, u8 Cpy_u8ValueType, void (*func)(void));
/********************************************************************************************/

/* MSTK_voidSetPeriodicInterval: Starts a periodic interval for a certain time determined by the arguments before calling the callback function */
/* I/P: - 	Cpy_u32DelayVal:	* Value of delay needed to be done
								* Type: u32
								* Available options: 1 : (2^32)

			Cpy_u8ValueType: 	* Type of delay value
								* Type: u8
								* Available options:
														- STK_U8_TICKS
														- STK_U8_MILLIS
														- STK_U8_MICROS
														- STK_U8_SECONDS
			(*func)(void): 		* Function to be which is to be called back after the busy wait
								* Return type: void
								* Available functions:
								* 				- Functions that have (void return type && void parameters)
																							*/
/* O/P: void 																				*/
void MSTK_voidSetPeriodicInterval(u32 Cpy_u32DelayVal, u8 Cpy_u8ValueType, void (*func)(void));
/********************************************************************************************/

/* MSTK_voidStopTimer:- Disables the STK timer which stops the periodic interval 	*/
/* I/P: void 																		*/
/* O/P: void 																		*/
void MSTK_voidStopTimer(void);
/************************************************************************************/

/* MSTK_u32GetElapsedTime: Returns Elapsed time since start of current interval */
/* I/P: - 	Cpy_u8ValueType: 	* Type of return value of time
								* Type: u8
								* Available options:
														- STK_U8_TICKS
														- STK_U8_MILLIS
														- STK_U8_MICROS
														- STK_U8_SECONDS
																				*/
/* O/P: void 																	*/
u32 MSTK_u32GetElapsedTime(u8 Cpy_u8TimeType);
/********************************************************************************/

/* MSTK_u32GetRemainingTime: Returns remaining time of current interval		*/
/* I/P: - 	Cpy_u8ValueType: 	* Type of return value of time
								* Type: u8
								* Available options:
														- STK_U8_TICKS
														- STK_U8_MILLIS
														- STK_U8_MICROS
														- STK_U8_SECONDS
																			*/
/* O/P: void 																*/
u32 MSTK_u32GetRemainingTime(u8 Cpy_u8TimeType);
/****************************************************************************/

/********************/

/********************/




#endif
