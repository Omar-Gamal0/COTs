/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 05 September 2020						*/
/************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

#define TASK_READY				1
#define TASK_SUSPENDED			0


void SOS_voidCreatTask(u8 Cpy_u8TaskID, u16 Cpy_u16priodicity, u16 Cpy_u16InitialDelay, void (*ptr)(void));
void SOS_voidStart(void);



#endif
