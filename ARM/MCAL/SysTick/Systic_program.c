/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 25 August 2020						*/
/************************************************/

/* Library layer includes */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**************************/

/* Systic header files Includes */

#include "Systick_interface.h"
#include "Systick_private.h"
#include "Systick_config.h"

/***********************/


/* Global functions */

void MSystick_voidInit(void){
	Msystick_voidCLKSOURCE(SYSTICK_U8_CLKSOURCE);
	Msystick_voidTICKINT(SYSTICK_U8_TICKINT);
	Msystick_voidCounter_En_Dis(SYSTICK_U8_COUNTER_ENABLE);
}

u32 MSystick_u32CurrentVal(void){
	u32 Loc_u32SysTickCounterVal;
	Loc_u32SysTickCounterVal = ((u32)(SYSTICK->VAL));
	return Loc_u32SysTickCounterVal;
}

void MSystick_voidDelay(u32 Cpy_u32DelayVal){
	MSystick_u8TmrUnderFlowFlg = 0;
	Cpy_u32DelayVal *= 1000;
	MSystick_voidLoadVal(Cpy_u32DelayVal);
	SYSTICK->VAL = 0x00;
	Msystick_voidCounter_En_Dis(SYSTICK_U8_COUNTER_EN);
	u32 Loc_u32SysTickCounterVal = MSystick_u32CurrentVal();
	while((GET_BIT(SYSTICK->CTRL, SYSTICK_U8_COUNTFLAG_BIT)) == 0);
	Msystick_voidCounter_En_Dis(SYSTICK_U8_COUNTER_DIS);

}


void SysTick_Handler(void){
	MSystick_u8TmrUnderFlowFlg = 1;
	Msystick_voidCounter_En_Dis(SYSTICK_U8_COUNTER_DIS);
}

/********************/
