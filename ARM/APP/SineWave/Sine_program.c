/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 09 Sept 2020							*/
/************************************************/

#include "STD_TYPES.h"
#include "Sine_interface.h"

f32 Sine_f32GetSineRes(f32 Cpy_f32Angle){
	
	f32 Loc_f32SineRes = 0;
	
	if ((Cpy_f32Angle >= 0) && (Cpy_f32Angle < (SINE_F32_PI/2))){
		Loc_f32SineRes = (f32)((Cpy_f32Angle) - ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_3) + ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_5) - ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_7) + ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_9) );
	}else if((Cpy_f32Angle >= (SINE_F32_PI/2)) && (Cpy_f32Angle < (SINE_F32_PI))){
		Cpy_f32Angle -= (SINE_F32_PI/2);
		Loc_f32SineRes = (f32)((1) - ((Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_2) + ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_4) - ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_6) + ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_8) );
	}else if((Cpy_f32Angle >= (SINE_F32_PI)) && (Cpy_f32Angle < (1.5*SINE_F32_PI))){
		Cpy_f32Angle -= (SINE_F32_PI);
		Loc_f32SineRes = (f32)((-Cpy_f32Angle) + ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_3) - ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_5) + ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_7) - ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_9) );
	}else if((Cpy_f32Angle >= (1.5*SINE_F32_PI)) && (Cpy_f32Angle <= (2*SINE_F32_PI))){
		Cpy_f32Angle -= (1.5*SINE_F32_PI);
		Loc_f32SineRes = (f32)((-1) + ((Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_2) - ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_4) + ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_6) - ((Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle*Cpy_f32Angle)/SINE_U32_FACT_8) );
	}else{
		/* Return error: Enter value between 0:2*Pi */
	}
	
	return Loc_f32SineRes;
}












