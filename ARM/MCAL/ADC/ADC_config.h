/* FILENAME: ADC_config  
*  Author:  Omar Gamal
*  Version:  V1.0
*  DATE:   Thu 09/24/2020
*/
#ifndef _ADC_CONFIG_H
#define _ADC_CONFIG_H

#define ADC_U8_AWDCH							ADC_U8_CH0					/* Analog watchdog channel select 				        	*/
#define ADC_U8_EOCIE							ADC_U8_DISABLE				/* Interrupt enable for EOC (End Of Conversion)         	*/
#define ADC_U8_AWDIE							ADC_U8_ENABLE				/* Analog watchdog interrupt enable				        	*/
#define ADC_U8_JEOCIE							ADC_U8_DISABLE				/* Interrupt enable for injected channels		        	*/
#define ADC_U8_SCAN								ADC_U8_DISABLE				/* Scan mode									        	*/
#define ADC_U8_AWDSGL							ADC_U8_DISABLE				/* Enable the watchdog on a single channel in scan mode		*/
#define ADC_U8_JAUTO							ADC_U8_DISABLE				/* Automatic Injected Group conversion						*/
#define ADC_U8_DISCEN							ADC_U8_DISABLE				/* Discontinuous mode on regular channels					*/
#define ADC_U8_JDISCEN							ADC_U8_DISABLE				/* Discontinuous mode on injected channels					*/
#define ADC_U8_DISCNUM							ADC_U8_1_Channel			/* Discontinuous mode channel count							*/
#define ADC_U8_DUALMOD							ADC_U8_DISABLE				/* Dual mode selection										*/
#define ADC_U8_JAWDEN							ADC_U8_DISABLE				/* Analog watchdog enable on injected channels				*/
#define ADC_U8_AWDEN							ADC_U8_ENABLE				/* Analog watchdog enable on regular channels				*/

#define ADC_U8_CONT								ADC_U8_ENABLE				/* Continuous conversion 									*/
#define ADC_U8_CAL								ADC_U8_DISABLE				/* A/D Calibration 											*/
#define ADC_U8_RSTCAL							ADC_U8_DISABLE				/* Reset calibration 										*/
#define ADC_U8_DMA								ADC_U8_DISABLE				/* Direct memory access mode 								*/
#define ADC_U8_ALIGN							ADC_U8_RIGHT_ALIGNMENT		/* Data alignment			 								*/
#define ADC_U8_JEXTSEL							ADC_U8_JSWSTART				/* External event select for injected group					*/
#define ADC_U8_JEXTTRIG							ADC_U8_DISABLE				/* External trigger conversion mode for injected channels	*/
#define ADC_U8_EXTSEL							ADC_U8_SWSTART				/* External event select for regular group					*/
#define ADC_U8_EXTTRIG							ADC_U8_DISABLE				/* External trigger conversion mode for regular channels	*/
#define ADC_U8_TSVREFE							ADC_U8_DISABLE				/* Temperature sensor and V_REFINT enable					*/

/* Channel x Sample time selection */
#define ADC_U8_SMP0								ADC_U8_1_5_CYCLES			/* Channel 1 Sample time selection */
// To be completed for the rest of CHnnels
/***********************************/

#define ADC_U8_REGULAR_SEQUENCE_LENGTH			ADC_U8_1_CONVERSION			/* Regular channel sequence length */

#endif //_ADC_CONFIG_H
