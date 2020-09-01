/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 19 August 2020						*/
/************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SCB_interface.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidEnableInterrupt(u8 Cpy_u8IntNumber) {
	if (Cpy_u8IntNumber <= 31) {
		NVIC_ISER0 = (0x01 << Cpy_u8IntNumber);
	} else if (Cpy_u8IntNumber <= 59) {
		NVIC_ISER1 = (0x01 << (Cpy_u8IntNumber - 32));
	} else {
		/* Return Error */
	}
}

void MNVIC_voidDisableInterrupt(u8 Cpy_u8IntNumber) {
	if (Cpy_u8IntNumber <= 31) {
		NVIC_ICER0 = (0x01 << Cpy_u8IntNumber);
	} else if (Cpy_u8IntNumber <= 59) {
		NVIC_ICER1 = (0x01 << (Cpy_u8IntNumber - 32));
	} else {
		/* Return Error */
	}
}

void MNVIC_voidSetPendingInterrupt(u8 Cpy_u8IntNumber) {
	if (Cpy_u8IntNumber <= 31) {
		NVIC_ISPR0 = (0x01 << Cpy_u8IntNumber);
	} else if (Cpy_u8IntNumber <= 59) {
		NVIC_ISPR1 = (0x01 << (Cpy_u8IntNumber - 32));
	} else {
		/* Return Error */
	}
}

void MNVIC_voidClearPendingInterrupt(u8 Cpy_u8IntNumber) {
	if (Cpy_u8IntNumber <= 31) {
		NVIC_ICPR0 = (0x01 << Cpy_u8IntNumber);
	} else if (Cpy_u8IntNumber <= 59) {
		NVIC_ICPR1 = (0x01 << (Cpy_u8IntNumber - 32));
	} else {
		/* Return Error */
	}
}

u8 MNVIC_u8ActiveInterrupt(u8 Cpy_u8IntNumber) {
	u8 Loc_u8InterruptState = 0;
	if (Cpy_u8IntNumber <= 31) {
		Loc_u8InterruptState = (NVIC_IABR0, Cpy_u8IntNumber);
	} else if (Cpy_u8IntNumber <= 59) {
		Loc_u8InterruptState = (NVIC_IABR1, (Cpy_u8IntNumber - 32));
	} else {
		/* Return Error */
	}
	return Loc_u8InterruptState;
}

void MNVIC_voidSetPriorityValue(u8 Cpy_u8IntNumber, u8 Cpy_u8GrpPrVal,
		u8 Cpy_u8SubPrVal) {

	if (Cpy_u8IntNumber < 60) {

		u8* IprReg = NVIC_IPR;
		if(MNVIC_u8ReturnConfig() == MNVIC_GS_CONFIG_4_0){
			if (Cpy_u8GrpPrVal <= 15){
				IprReg[Cpy_u8IntNumber] = (Cpy_u8GrpPrVal << 4);
			}
		}
		else if(MNVIC_u8ReturnConfig() == MNVIC_GS_CONFIG_3_1){
			if ((Cpy_u8GrpPrVal <= 7) && (Cpy_u8SubPrVal <= 1)){
				IprReg[Cpy_u8IntNumber] = ((Cpy_u8GrpPrVal << 5) | (Cpy_u8SubPrVal << 4));
			}
		}
		else if(MNVIC_u8ReturnConfig() == MNVIC_GS_CONFIG_2_2){
			if ((Cpy_u8GrpPrVal <= 3) && (Cpy_u8SubPrVal <= 3)){
				IprReg[Cpy_u8IntNumber] = ((Cpy_u8GrpPrVal << 6) | (Cpy_u8SubPrVal << 4));
			}
		}
		else if(MNVIC_u8ReturnConfig() == MNVIC_GS_CONFIG_1_3){
			if ((Cpy_u8GrpPrVal <= 1) && (Cpy_u8SubPrVal <= 7)){
				IprReg[Cpy_u8IntNumber] = ((Cpy_u8GrpPrVal << 7) | (Cpy_u8SubPrVal << 4));
			}
		}
		else if(MNVIC_u8ReturnConfig() == MNVIC_GS_CONFIG_0_4){
			if (Cpy_u8SubPrVal <= 15){
				IprReg[Cpy_u8IntNumber] = (Cpy_u8SubPrVal << 4);
			}
		}

	} else {
		/* Report error */
	}

}

void MNVIC_voidEXTIEnControl(u8 Cpy_u8Line, u8 Cpy_u8EnorDis){
	
	switch(Cpy_u8EnorDis)
	{
		
	case MNVIC_U8_ENABLE:
	if(Cpy_u8Line < 5){
		MNVIC_voidEnableInterrupt(Cpy_u8Line + 6);
	}else if(Cpy_u8Line < 10){
		MNVIC_voidEnableInterrupt(23);
	}else if(Cpy_u8Line < 16){
		MNVIC_voidEnableInterrupt(40);
	}else{
		/* Return error */
	}
	break;
	
	case MNVIC_U8_DISABLE:
	if(Cpy_u8Line < 5){
		MNVIC_voidDisableInterrupt(Cpy_u8Line + 6);
	}else if(Cpy_u8Line < 10){
		MNVIC_voidDisableInterrupt(23);
	}else if(Cpy_u8Line < 16){
		MNVIC_voidDisableInterrupt(40);
	}else{
		/* Return error */
	}
	break;
	
	}
	
}