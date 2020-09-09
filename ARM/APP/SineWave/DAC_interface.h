/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 09 Sept 2020							*/
/************************************************/

#ifndef DAC_INTERFACE_H_
#define DAC_INTERFACE_H_

#define DAC_U8_ARRAY		0
#define DAC_U8_FUNC			1

void DAC_voidSetArrDAC(void);

void DAC_voidSetFuncDAC(void);

void DAC_voidInit(void);

void DAC_voidStart(u8 Cpy_u8DataType);

#endif /* DAC_INTERFACE_H_ */
