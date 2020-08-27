/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 25 August 2020						*/
/************************************************/

#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_

/* Selecting the clock source
 * Available options:-
 * 						SYSTICK_U8_CLKSOURCE_AHB_8
 * 						SYSTICK_U8_CLKSOURCE_AHB			 */
#define SYSTICK_U8_CLKSOURCE				SYSTICK_U8_CLKSOURCE_AHB_8

/* SysTick exception request enabling
 * Available options:-
 * 						SYSTICK_U8_TICKINT_EN
 * 						SYSTICK_U8_TICKINT_DIS			 */
#define SYSTICK_U8_TICKINT				SYSTICK_U8_TICKINT_DIS

/* Counter enabling
 * Available options:-
 * 						SYSTICK_U8_COUNTER_EN
 * 						SYSTICK_U8_COUNTER_DIS			 */
#define SYSTICK_U8_COUNTER_ENABLE		SYSTICK_U8_COUNTER_EN


#endif /* SYSTICK_CONFIG_H_ */
