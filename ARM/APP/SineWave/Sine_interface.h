/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 09 Sept 2020							*/
/************************************************/

#ifndef SINE_INTERFACE_H
#define SINE_INTERFACE_H

/* Factorials Value macros */
#define SINE_U32_FACT_2				2
#define SINE_U32_FACT_3				6
#define SINE_U32_FACT_4				24
#define SINE_U32_FACT_5				120
#define SINE_U32_FACT_6				720
#define SINE_U32_FACT_7				5040
#define SINE_U32_FACT_8				40320
#define SINE_U32_FACT_9				362880
/***************************/

/* PI constant value*/
#define SINE_F32_PI					3.1415
/********************/

/*
Equations: - 
Sin(x)=(((x-0))^1⁡)/1!-(((x-0))^3)/3!+(((x-0))^5)/5!-(((x-0))^7)/7!+(((x-0))^9)/9!           	a=0
Sin(x)=1-(((x-π/2))^2)/2!+(((x-π/2))^4)/4!-(((x-π/2))^6)/6!+(((x-π/2))^8)/8!                    a=π/2
Sin(x)=(-(((x-π)))^1⁡)/1!+(((x-π))^3)/3!-(((x-π))^5/5!+((x-π))^7)/7!-(((x-π))^9)/9!             a=π
Sin(x)=-1+(((x-3π/2))^2)/2!-(((x-3π/2))^4)/4!+(((x-3π/2))^6)/6!-(((x-3π/2))^8)/8!               a=3π/2
*/

/* Sine_f32GetSineRes --> Returns Value of the function: sin(x) 		*/
/* I/P: Cpy_f32Angle: Angle that we want to find sine for (Type: f32) 	*/
/* Return type: f32 													*/
f32 Sine_f32GetSineRes(f32 Cpy_f32Angle);
/************************************************************************/




#endif
	












