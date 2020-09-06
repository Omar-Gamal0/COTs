/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 05 September 2020						*/
/************************************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H


typedef struct{
	u16 Periodicity;						// Periodicity of the task
	void (*Fptr)(void);						// Address of the function of the task
	u8 State;								// Current state of the task (Suspended or ready)
	u16 InitialDelay;						// InitialDelay of the task
}Task;										// defining Task struct data type


#define NULL		((void *)(0))			// Defining the NULL macro

#endif
