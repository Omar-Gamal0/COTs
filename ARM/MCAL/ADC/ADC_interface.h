/* FILENAME: ADC_interface  
*  Author:  Omar Gamal
*  Version:  V1.0
*  DATE:   Thu 09/24/2020
*/
#ifndef _ADC_INTERFACE_H
#define _ADC_INTERFACE_H

/* General Macros 															*/
/* Enable/Disable Macros */
#define ADC_U8_ENABLE			1
#define ADC_U8_DISABLE			0
/*************************/

/* Channel Number Macros */
#define ADC_U8_CH0				0
#define ADC_U8_CH1				1
#define ADC_U8_CH2				2
#define ADC_U8_CH3				3
#define ADC_U8_CH4				4
#define ADC_U8_CH5				5
#define ADC_U8_CH6				6
#define ADC_U8_CH7				7
#define ADC_U8_CH8				8
#define ADC_U8_CH9				9
#define ADC_U8_CH10				10
#define ADC_U8_CH11				11
#define ADC_U8_CH12				12
#define ADC_U8_CH13				13
#define ADC_U8_CH14				14
#define ADC_U8_CH15				15
#define ADC_U8_CH16				16
#define ADC_U8_CH17				17
/*************************/
/****************************************************************************/

/* CR1 Option Macros 														*/
/* Analog watchdog channel select
 * Same as: Channel Number Macros */

/* Discontinuous mode channel count */
#define ADC_U8_1_Channel				0
#define ADC_U8_2_Channels				1
#define ADC_U8_3_Channels				2
#define ADC_U8_4_Channels				3
#define ADC_U8_5_Channels				4
#define ADC_U8_6_Channels				5
#define ADC_U8_7_Channels				6
#define ADC_U8_8_Channels				7
/************************************/

/* Dual mode selection Macros */
// These bits are reserved in ADC2 and ADC3
#define ADC_U8_INDEPENDENT_MODE											0
#define ADC_U8_REGULAR_SIMULTANEOS_INJECTED_SIMULTANEOS_MODE			1
#define ADC_U8_REGULAR_SIMULTANEOS_ALTERNATE_TRIGGER_MODE				2
#define ADC_U8_INJECTED_SIMULTANEOS_FAST_INTERLEAVED_MODE				3
#define ADC_U8_INJECTED_SIMULTANEOS_SLOW_INTERLEAVED_MODE				4
#define ADC_U8_INJECTED_SIMULTANEOS_ONLY_MODE							5
#define ADC_U8_REGULAR_SIMULTANEOS_ONLY_MODE							6
#define ADC_U8_FAST_INTERLEAVED_SIMULTANEOS_ONLY_MODE					7
#define ADC_U8_SLOW_INTERLEAVED_SIMULTANEOS_ONLY_MODE					8
#define ADC_U8_ALTERNATE_TRIGGER_ONLY_MODE								9
/******************************/
/****************************************************************************/

/* CR2 Option Macros 														*/
/* Data Alignment */
#define ADC_U8_RIGHT_ALIGNMENT											0
#define ADC_U8_LEFT_ALIGNMENT											1
/******************/

/* External event select for injected group */
#define ADC_U8_TIMER1_TRGO_EVENT										0
#define ADC_U8_TIMER1_CC4_EVENT											1
#define ADC_U8_TIMER2_TRGO_EVENT										2
#define ADC_U8_TIMER2_CC4_EVENT											3
#define ADC_U8_TIMER3_CC4_EVENT											4
#define ADC_U8_TIMER4_TRGO_EVENT										5
#define ADC_U8_EXTI_LINE15_EVENT										6
#define ADC_U8_JSWSTART													7
/**********************************/

/* External event select for regular group */
#define ADC_U8_TIMER1_CC1_EVENT											0
#define ADC_U8_TIMER1_CC2_EVENT											1
#define ADC_U8_TIMER1_CC3_EVENT											2
#define ADC_U8_TIMER2_CC2_EVENT											3
#define ADC_U8_TIMER3_TRGO_EVENT										4
#define ADC_U8_TIMER4_CC4_EVENT											5
#define ADC_U8_EXTI_LINE11_EVENT										6
#define ADC_U8_SWSTART													7
/**********************************/
/****************************************************************************/

/* SMPR1 & SMPR2 Option Macros 												*/
/* Channel x Sample time selection */
#define ADC_U8_1_5_CYCLES												0
#define ADC_U8_7_5_CYCLES												1
#define ADC_U8_13_5_CYCLES												2
#define ADC_U8_28_5_CYCLES												3
#define ADC_U8_41_5_CYCLES												4
#define ADC_U8_55_5_CYCLES												5
#define ADC_U8_71_5_CYCLES												6
#define ADC_U8_239_5_CYCLES												7
/**********************************/
/****************************************************************************/

/* SQR1, SQR2 & SQR3 Option Macros 											*/
/* Regular channel sequence length */
#define ADC_U8_1_CONVERSION												0
#define ADC_U8_2_CONVERSIONS											1
#define ADC_U8_3_CONVERSIONS											2
#define ADC_U8_4_CONVERSIONS											3
#define ADC_U8_5_CONVERSIONS											4
#define ADC_U8_6_CONVERSIONS											5
#define ADC_U8_7_CONVERSIONS											6
#define ADC_U8_8_CONVERSIONS											7
#define ADC_U8_9_CONVERSIONS											8
#define ADC_U8_10_CONVERSIONS											9
#define ADC_U8_11_CONVERSIONS											10
#define ADC_U8_12_CONVERSIONS											11
#define ADC_U8_13_CONVERSIONS											12
#define ADC_U8_14_CONVERSIONS											13
#define ADC_U8_15_CONVERSIONS											14
#define ADC_U8_16_CONVERSIONS											15
/**********************************/

/* Xth conversion in regular sequence
 * Same as: Channel Number Macros  */
/****************************************************************************/

/* JSQR Option Macros 														*/
/* JSQx
 * Same as: Channel Number Macros  */

/* Injected sequence length
 * CR2: Regular channel sequence length [from: ADC_U8_1_CONVERSION, to: ADC_U8_4_CONVERSIONS] */

/*
Note:-
JSQ1[4:0] >> JSQ2[4:0] >> JSQ3[4:0] >> JSQ4[4:0]
When JL=2 ( 3 injected conversions in the sequencer), the ADC converts the channels in this order:
JSQ2[4:0] >> JSQ3[4:0] >> JSQ4[4:0]
When JL=1 ( 2 injected conversions in the sequencer), the ADC converts the channels in this order:
JSQ3[4:0] >> JSQ4[4:0]
When JL=0 (1 injected conversion in the sequencer), the ADC converts only JSQ4[4:0] channel
*/
/****************************************************************************/


/* Global functions 																			*/
/* ADC1_voidInit -> Initializes ADC1 applying configurations from ADC_config.h 			*/
/* I/P: void																			*/
/* O/P: void																			*/
void ADC1_voidInit(void);
/****************************************************************************************/

void ADC1_voidStartConv(void);

/* ADC1_voidSetThresholds -> Sets Low & High Thresholds of the analog watchdog			*/
/* I/P: Cpy_u16LowThreshold:-  * Low Threshold of the analog watchdog
  							   * Type: u16
  		Cpy_u16HighThreshold:- * High Threshold of the analog watchdog
  							   * Type: u16												*/
/* O/P: void																			*/
void ADC1_voidSetThresholds(u16 Cpy_u16LowThreshold, u16 Cpy_u16HighThreshold);
/****************************************************************************************/

/* ADC1_u16GetRegularVal -> Gets resulted value of A/D conversion or regular channel	*/
/* I/P: void																			*/
/* O/P: u16: Low 16 bits of DR ADC1 register											*/
u16 ADC1_u16GetRegularVal(void);
/****************************************************************************************/

/* ADC1_SetAWDCallBack -> Sets CallBack function for AWD interrupt						*/
/* I/P: CallBack: Pointer to function to be set as CallBack function for AWD interrupt	*/
/* O/P: void																			*/
void ADC1_SetAWDCallBack(void (*CallBack) (void));
/****************************************************************************************/

void ADC1_SetEOCCallBack(void (*CallBack) (void));
/************************************************************************************************/




#endif //_ADC_INTERFACE_H


















