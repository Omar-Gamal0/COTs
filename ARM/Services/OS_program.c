/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 05 September 2020						*/
/************************************************/

#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

/* MCAL includes */
#include "STK_interface.h"
/*****************/

#include 	"OS_interface.h"
#include 	"OS_private.h"
#include 	"OS_config.h"



/* Array of tasks		"Array of structs" */
static Task OS_Tasks[OS_U8_NUMBER_OF_TASKS] = {NULL};

__V u16 OS_u16TickCount = 0;

/*void Schedular(void){
	for(u8 i = 0; i < OS_U8_NUMBER_OF_TASKS; i++){
		if((OS_u16TickCount % OS_Tasks[i].Priodicity) == 0){
			OS_Tasks[i].Fptr();
		}
	}
	OS_u16TickCount++;
}*/

void Schedular(void){
	for(u8 i = 0; i < OS_U8_NUMBER_OF_TASKS; i++){
		if((OS_Tasks[i].State == TASK_READY) && (OS_Tasks[i].Fptr != NULL)){
			if((OS_Tasks[i].InitialDelay) == 0){
				OS_Tasks[i].InitialDelay = OS_Tasks[i].Priodicity;
				OS_Tasks[i].Fptr();
			}else{
				OS_Tasks[i].InitialDelay--;
			}
		}
	}
	OS_u16TickCount++;
}

void SOS_voidCreatTask(u8 Cpy_u8TaskID, u16 Cpy_u16priodicity, u16 Cpy_u16InitialDelay, void (*ptr)(void)){
	OS_Tasks[Cpy_u8TaskID].Priodicity = Cpy_u16priodicity;
	OS_Tasks[Cpy_u8TaskID].Fptr = ptr;
	OS_Tasks[Cpy_u8TaskID].State = TASK_READY;
	OS_Tasks[Cpy_u8TaskID].InitialDelay = Cpy_u16InitialDelay;
}

void SOS_voidStart(void){
	/* Initialization */
	MSTK_voidSTKInit();
	/* Tick Each 1msec */
	/* HSE/8 */
	MSTK_voidSetPeriodicInterval(1,STK_U8_MILLIS,Schedular);
}
