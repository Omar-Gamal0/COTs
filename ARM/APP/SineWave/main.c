
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "DAC_interface.h"



void main(void) {

	RCC_voidInitSysClock(); /* Initializes the system clock */
	GPIO_voidPORTA_Init();  /* Enables clock for PortA, sets all pins' outputs of PortA to low */
	MSTK_voidSTKInit();
	DAC_voidInit();

	DAC_voidStart(DAC_U8_FUNC);

	while (1) {

	}
}
