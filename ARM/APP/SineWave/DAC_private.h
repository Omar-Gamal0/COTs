/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 09 Sept 2020							*/
/************************************************/

#ifndef DAC_PRIVATE_H_
#define DAC_PRIVATE_H_

typedef struct{

	u8 DAC_Bit0_Port;
	u8 DAC_Bit0_Pin;
	u8 DAC_Bit1_Port;
	u8 DAC_Bit1_Pin;
	u8 DAC_Bit2_Port;
	u8 DAC_Bit2_Pin;
	u8 DAC_Bit3_Port;
	u8 DAC_Bit3_Pin;
	u8 DAC_Bit4_Port;
	u8 DAC_Bit4_Pin;
	u8 DAC_Bit5_Port;
	u8 DAC_Bit5_Pin;
	u8 DAC_Bit6_Port;
	u8 DAC_Bit6_Pin;
	u8 DAC_Bit7_Port;
	u8 DAC_Bit7_Pin;

}DAC_def_t;

f32 DAC_f32InputStepSize;

#endif /* DAC_PRIVATE_H_ */
