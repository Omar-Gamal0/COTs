/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 25 August 2020						*/
/************************************************/

#ifndef SYSTIC_PRIVATE_H_
#define SYSTIC_PRIVATE_H_

#define SYSTICK ((Systic_RegDef_t*)(0xE000E010))

u8 MSystick_u8TmrUnderFlowFlg = 0;

#endif /* SYSTIC_PRIVATE_H_ */
