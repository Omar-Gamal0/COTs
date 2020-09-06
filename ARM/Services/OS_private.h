/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 05 September 2020						*/
/************************************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H


typedef struct{
	u16 Priodicity;
	void (*Fptr)(void);
	u8 State;
	u16 InitialDelay;
}Task;


#define NULL		((void *)(0))

#endif
