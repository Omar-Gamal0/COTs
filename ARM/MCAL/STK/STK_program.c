/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 27 August 2020						*/
/************************************************/

/* Library layer includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**************************/

/* STK files includes */
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"
/**********************/

/* Global functions */

void MSTK_voidSTKInit(void){
	STK -> CTRL &= ~(0x01 << STK_U8_CLKSOURCE_BIT);
	STK -> CTRL |= (STK_U8_CLKSOURCE << STK_U8_CLKSOURCE_BIT);
	
	#if(STK_U8_CLKSOURCE == STK_U8_CLKSOURCE_AHB_8)
			#define STK_CLK			(STK_AHB_CLK/8)
	#elif (STK_U8_CLKSOURCE == STK_U8_CLKSOURCE_AHB)
			#define STK_CLK			(STK_AHB_CLK)
	#endif
}

void MSTK_voidTICKInterrupt(u8 Cpy_u8EnOrDis){
	STK -> CTRL &= ~(0x01 << STK_U8_TICKINT_BIT);
	STK -> CTRL |= (Cpy_u8EnOrDis << STK_U8_TICKINT_BIT);
}

void MSTK_voidLoadVal(u32 Cpy_u32LoadVal){
	STK -> LOAD = Cpy_u32LoadVal ;
}

u32 MSTK_u32CurrentVal(void){
	return ((u32)(STK->VAL));
}

void MSTK_voidCounterEnDis(u8 Cpy_u8EnOrDis){
	STK -> CTRL &= ~(0x01 << STK_U8_COUNTER_EN_BIT);
	STK -> CTRL |= (Cpy_u8EnOrDis << STK_U8_COUNTER_EN_BIT);
}

void MSTK_voidSetBusyWait(u32 Cpy_u32DelayVal, u8 Cpy_u8ValueType, void (*func)(void)){
	
	switch(Cpy_u8ValueType){
		case STK_U8_TICKS:																	break;		
		case STK_U8_MICROS:		Cpy_u32DelayVal *= (STK_CLK/STK_U8_MICROS_DIVIDER);			break;		
		case STK_U8_MILLIS:		Cpy_u32DelayVal *= (STK_CLK/STK_U8_MILLIS_DIVIDER);			break;
		case STK_U8_SECONDS:	Cpy_u32DelayVal *= (STK_CLK);								break;
	}
		MSTK_voidTICKInterrupt(STK_U8_TICKINT_DIS);
		STK->VAL = 0x00;
		MSTK_voidLoadVal(Cpy_u32DelayVal);
		MSTK_voidCounterEnDis(STK_U8_COUNTER_EN);
		while((GET_BIT(STK->CTRL, STK_U8_COUNTFLAG_BIT)) == 0);
		MSTK_voidCounterEnDis(STK_U8_COUNTER_DIS);
			
	func();

}


void SysTick_Handler(void){
	MSTK_voidCounterEnDis(STK_U8_COUNTER_DIS);
}

/********************/
