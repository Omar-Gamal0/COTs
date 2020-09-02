/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 22 August 2020						*/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


void MEXTI_voidInit(u8 Cpy_u8Port, u8 Cpy_u8Line, u8 Cpy_u8TriggerSel)
{
	MNVIC_voidEXTIEnControl(Cpy_u8Line, MNVIC_U8_ENABLE);	/* Enables External interrupt for EXTI */
	MEXTI_voidLineEnorDis(Cpy_u8Line, MEXTI_U8_ENABLE);		/* Unmask Interrupt request from selected EXTI line(Cpy_u8Line) */
	MEXTI_voidTriggerSel(Cpy_u8Line, Cpy_u8TriggerSel);		/* Selects triggering type */
	MAFIO_voidSetEXTIConfig(Cpy_u8Line, Cpy_u8Port); 		/* Selects the source input for EXTI Line */

}

void MEXTI_voidLineEnorDis(u8 Cpy_u8Line, u8 Cpy_u8EnorDis)
{
	switch(Cpy_u8EnorDis)
	{
		case MEXTI_U8_ENABLE:
			SET_BIT((EXTI -> IMR) , Cpy_u8Line);			
		break;
		
		case MEXTI_U8_DISABLE:
			CLR_BIT((EXTI -> IMR) , Cpy_u8Line);
		break;
	}
}

void MEXTI_voidTriggerSel(u8 Cpy_u8Line, u8 Cpy_u8TriggerSel)
{
	switch (Cpy_u8TriggerSel)
	{
		case MEXTI_U8_RISING_EDGE_TRIGGER:
			SET_BIT((EXTI -> RTSR) , Cpy_u8Line);
			CLR_BIT((EXTI -> FTSR) , Cpy_u8Line);
		break;
		
		case MEXTI_U8_FALLING_EDGE_TRIGGER:
			CLR_BIT((EXTI -> RTSR) , Cpy_u8Line);
			SET_BIT((EXTI -> FTSR) , Cpy_u8Line);
		break;
		
		case MEXTI_U8_BOTH_EDGES_TRIGGER:
			SET_BIT((EXTI -> RTSR) , Cpy_u8Line);
			SET_BIT((EXTI -> FTSR) , Cpy_u8Line);
		break;
	}
}


void MEXTI_voidSetSWInt(u8 Cpy_u8Line)
{
	SET_BIT((EXTI -> SWIER) , Cpy_u8Line);
}

u8 MEXTI_u8GetPR(u8 Cpy_u8Line)
{
	return (GET_BIT((EXTI -> PR) , Cpy_u8Line));
}

void MEXTI_voidClrPR(u8 Cpy_u8Line)
{
	SET_BIT((EXTI -> PR) , Cpy_u8Line);
}

void MEXTI_voidSetCallBack(void (*ptr_Func)(void), u8 Cpy_u8Line){
	CallBack[Cpy_u8Line] = ptr_Func;
}

void EXTI0_IRQHandler(void){
	MEXTI_voidClrPR(0);
	CallBack[0]();
}

