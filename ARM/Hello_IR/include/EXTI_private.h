/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 22 August 2020						*/
/************************************************/


#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H

typedef struct{
	
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;	
	
	
}EXTI_t;

#define EXTI 				((volatile EXTI_t*) 0x40010400)

void (*CallBack[16])(void);

#endif
