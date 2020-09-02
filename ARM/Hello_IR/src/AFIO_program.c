/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 22 August 2020						*/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"


void MAFIO_voidSetEXTIConfig(u8 Cpy_u8Line, u8 Cpy_u8Port){
	
	u8 Loc_u8RegNo = Cpy_u8Line / 4;
	u8 Loc_u8RegIndex = Cpy_u8Line % 4;	
	
	AFIO -> EXTICR[Loc_u8RegNo] &= ~(15 			<< (Loc_u8RegIndex * 4) );
	AFIO -> EXTICR[Loc_u8RegNo] |=  (Cpy_u8Port 	<< (Loc_u8RegIndex * 4) );
	
}
