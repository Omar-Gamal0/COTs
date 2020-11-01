/* FILENAME: ADC_private  
*  Author:  Omar Gamal
*  Version:  V1.0
*  DATE:   Thu 09/24/2020
*/
#ifndef _ADC_PRIVATE_H
#define _ADC_PRIVATE_H
/* Defining ADC Type strict */
typedef struct{
	__V u32 SR;
	__V u32 CR1;
	__V u32 CR2;
	__V u32 SMPR[2];
	__V u32 JOFR[4];
	__V u32 HTR;
	__V u32 LTR;
	__V u32 SQR[3];
	__V u32 JDR[4];
	__V u32 JSQR;
	__V u32 DR;
}ADC_Def_t;
/****************************/


#define 	ADC1 		((ADC_Def_t *) 0x40012400)

void (*ADC1_voidAWDCallBack) (void);
void (*ADC1_voidEOCCallBack) (void);

/* Defining register bits Macros 																	*/
/* SR Bits Macros */
#define AWD		0			/* Analog watchdog flag 												*/
#define EOC		1			/* End of conversion 													*/
#define JEOC	2			/* Injected channel end of conversion 									*/
#define JSTR	3			/* Injected channel Start flag 											*/
#define STRT	4			/* Regular channel Start flag 											*/
/******************/

/* CR1 Bits Macros */
#define AWDCH		0		/* Start bit of Analog watchdog channel select bits [0:4] 				*/
#define EOCIE		5		/* Interrupt enable for EOC 											*/
#define AWDIE		6		/* Analog watchdog interrupt enable 									*/
#define JEOCIE		7		/* Interrupt enable for injected channels 								*/
#define SCAN		8		/* Scan mode 															*/
#define AWDSGL		9		/* Enable the watchdog on a single channel in scan mode 				*/
#define JAUTO		10		/* Automatic Injected Group conversion 									*/
#define DISCEN		11		/* Discontinuous mode on regular channels 								*/
#define JDISCEN		12		/* Discontinuous mode on injected channels 								*/
#define DISCNUM		13		/* Start bit of Discontinuous mode channel count bits [13:15] 			*/
#define DUALMOD		16		/* Start bit of Dual mode selection bits [16:19] 						*/
#define JAWDEN		22		/* Analog watchdog enable on injected channels 							*/
#define AWDEN		23		/* Analog watchdog enable on regular channels 							*/
/*******************/

/* CR2 Bits Macros */
#define ADON		0		/* A/D converter ON/OFF 												*/
#define CONT		1		/* Continuous conversion 												*/
#define CAL			2		/* A/D Calibration 														*/
#define RSTCAL		3		/* Reset calibration 													*/
#define DMA			8		/* Direct memory access mode 											*/
#define ALIGN		11		/* Data alignment 														*/
#define JEXTSEL		12		/* Start bit of External event select for injected group bits [12:14] 	*/
#define JEXTTRIG	15		/* External trigger conversion mode for injected channels 				*/
#define EXTSEL		17		/* Start bit of External event select for regular group bits [17:19] 	*/
#define EXTTRIG		20		/* External trigger conversion mode for regular channels 				*/
#define JSWSTART	21		/* Start conversion of injected channels 								*/
#define SWSTART		22		/* Start conversion of regular channels 								*/
#define TSVREFE		23		/* Temperature sensor and V_REFINT enable 								*/
/*******************/

/* SMPR1 Bits Macros */
#define SMP10		0		/* Start bit of Channel 17 Sample time selection bits    [0 : 2]        */
#define SMP11		3		/* Start bit of Channel 17 Sample time selection bits    [3 : 5]        */
#define SMP12		6		/* Start bit of Channel 17 Sample time selection bits    [6 : 8]        */
#define SMP13		9		/* Start bit of Channel 17 Sample time selection bits    [9 :11]        */
#define SMP14		12		/* Start bit of Channel 17 Sample time selection bits    [12:14]        */
#define SMP15		15		/* Start bit of Channel 17 Sample time selection bits    [15:17]        */
#define SMP16		18		/* Start bit of Channel 17 Sample time selection bits    [18:20]        */
#define SMP17		21		/* Start bit of Channel 17 Sample time selection bits    [21:23]        */
/*********************/

/* SMPR2 Bits Macros */
#define SMP0		0		/* Start bit of Channel 17 Sample time selection bits    [0 : 2]        */
#define SMP1		3		/* Start bit of Channel 17 Sample time selection bits    [3 : 5]        */
#define SMP2		6		/* Start bit of Channel 17 Sample time selection bits    [6 : 8]        */
#define SMP3		9		/* Start bit of Channel 17 Sample time selection bits    [9 :11]        */
#define SMP4		12		/* Start bit of Channel 17 Sample time selection bits    [12:14]        */
#define SMP5		15		/* Start bit of Channel 17 Sample time selection bits    [15:17]        */
#define SMP6		18		/* Start bit of Channel 17 Sample time selection bits    [18:20]        */
#define SMP7		21		/* Start bit of Channel 17 Sample time selection bits    [21:23]        */
#define SMP8		24		/* Start bit of Channel 17 Sample time selection bits    [24:26]        */
#define SMP9		27		/* Start bit of Channel 17 Sample time selection bits    [27:29]        */
/*********************/

/* SQR1 Bits Macros */
#define SQ13		0		/* Start bit of 13th conversion in regular sequence bits [0 : 4]        */
#define SQ14		5		/* Start bit of 14th conversion in regular sequence bits [5 : 9]        */
#define SQ15		10		/* Start bit of 15th conversion in regular sequence bits [10:14]        */
#define SQ16		15		/* Start bit of 16th conversion in regular sequence bits [15:19]        */
#define L			20		/* Start bit of Regular channel sequence length bits 	 [20:22]        */
/*********************/

/* SQR2 Bits Macros */
#define SQ7			0		/* Start bit of 7th conversion in regular sequence bits  [0 : 4]        */
#define SQ8			5		/* Start bit of 8th conversion in regular sequence bits  [5 : 9]        */
#define SQ9			10		/* Start bit of 9th conversion in regular sequence bits  [10:14]        */
#define SQ10		15		/* Start bit of 10th conversion in regular sequence bits [15:19]        */
#define SQ11		20		/* Start bit of 11th conversion in regular sequence bits [20:24]        */
#define SQ12		25		/* Start bit of 12th conversion in regular sequence bits [25:29]        */
/*********************/

/* SQR3 Bits Macros */
#define SQ1			0		/* Start bit of 1st conversion in regular sequence bits  [0 : 4]        */
#define SQ2			5		/* Start bit of 2nd conversion in regular sequence bits  [5 : 9]        */
#define SQ3			10		/* Start bit of 3rd conversion in regular sequence bits  [10:14]        */
#define SQ4			15		/* Start bit of 4th conversion in regular sequence bits  [15:19]        */
#define SQ5			20		/* Start bit of 5th conversion in regular sequence bits  [20:24]        */
#define SQ6			25		/* Start bit of 6th conversion in regular sequence bits  [25:29]        */
/*********************/

/* JSQR Bits Macros */
#define JSQ1		0		/* Start bit of 1st conversion in regular sequence bits  [0 : 4]        */
#define JSQ1		5		/* Start bit of 2nd conversion in regular sequence bits  [5 : 9]        */
#define JSQ3		10		/* Start bit of 3rd conversion in regular sequence bits  [10:14]        */
#define JSQ4		15		/* Start bit of 4th conversion in regular sequence bits  [15:19]        */
#define JL			20		/* Start bit of Injected sequence length bits 	 		 [20:22]        */
/*********************/
/****************************************************************************************************/
#endif //_ADC_PRIVATE_H
