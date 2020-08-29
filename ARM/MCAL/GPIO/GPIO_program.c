/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V03								*/
/* 	Date: 19 August 2020						*/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

void GPIO_voidAllPortsInit(void) { /* Enables clock for All Ports, sets all pins outputs to low & Initializes the system clock */

	RCC_voidInitSysClock(); /* Initializes the system clock */
	GPIO_voidPORTA_Init(); /* Enables clock for PortA, sets all pins' outputs of PortA to low */
	GPIO_voidPORTB_Init(); /* Enables clock for PortB, sets all pins' outputs of PortB to low */
	GPIO_voidPORTC_Init(); /* Enables clock for PortC, sets all pins' outputs of PortC to low */

}

void GPIO_voidPORTA_Init(void) { /* Enables clock for PortA, sets all pins' outputs of PortA to low */

	RCC_voidEnableClock(RCC_APB2, 2);
	GPIO_GPIOA_ODR = 0x00;

}

void GPIO_voidPORTB_Init(void) { /* Enables clock for PortB, sets all pins' outputs of PortB to low */

	RCC_voidEnableClock(RCC_APB2, 3);
	GPIO_GPIOB_ODR = 0x00;

}

void GPIO_voidPORTC_Init(void) { /* Enables clock for PortC, sets all pins' outputs of PortC to low */

	RCC_voidEnableClock(RCC_APB2, 4);
	GPIO_GPIOC_ODR = 0x00;

}

void GPIO_voidSetPinVal(u8 Cpy_u8Port, u8 Cpy_u8PinNum, u8 Cpy_u8PinVal) { /* Sets output value of wanted pin */

	switch (Cpy_u8Port) {

	case GPIO_U8_PORTA:

		if ((Cpy_u8PinVal == GPIO_U8_HIGH) && (Cpy_u8PinNum < 16)) {
			GPIO_GPIOA_BSRR = (0x01 << Cpy_u8PinNum);
		} else if ((Cpy_u8PinVal == GPIO_U8_LOW) && (Cpy_u8PinNum < 16)) {
			GPIO_GPIOA_BRR = (0x01 << Cpy_u8PinNum);
		} else {

		}

		break;
	case GPIO_U8_PORTB:

		if ((Cpy_u8PinVal == GPIO_U8_HIGH) && (Cpy_u8PinNum < 16)) {
			GPIO_GPIOB_BSRR = (0x01 << Cpy_u8PinNum);
		} else if ((Cpy_u8PinVal == GPIO_U8_LOW) && (Cpy_u8PinNum < 16)) {
			GPIO_GPIOB_BRR = (0x01 << Cpy_u8PinNum);
		} else {

		}

		break;
	case GPIO_U8_PORTC:

		if ((Cpy_u8PinVal == GPIO_U8_HIGH) && (Cpy_u8PinNum < 16)) {
			GPIO_GPIOC_BSRR = (0x01 << Cpy_u8PinNum);
		} else if ((Cpy_u8PinVal == GPIO_U8_LOW) && (Cpy_u8PinNum < 16)) {
			GPIO_GPIOC_BRR = (0x01 << Cpy_u8PinNum);
		} else {

		}
	}
}

void GPIO_voidTogPinVal(u8 Cpy_u8Port,u8 Cpy_u8PinNum)
{
	
	switch (Cpy_u8Port) {

	case GPIO_U8_PORTA:
		
		TOG_BIT(GPIO_GPIOA_ODR, Cpy_u8PinNum);

		break;
	case GPIO_U8_PORTB:

	TOG_BIT(GPIO_GPIOB_ODR, Cpy_u8PinNum);

		break;
	case GPIO_U8_PORTC:

		TOG_BIT(GPIO_GPIOC_ODR, Cpy_u8PinNum);
		
		break;
	}
}

u8 GPIO_u8GetPinVal(u8 Cpy_u8Port, u8 Cpy_u8PinNum) { /* Returns input value of wanted pin */
	u8 Loc_u8PinValue = 0;
	switch (Cpy_u8Port) {

	case GPIO_U8_PORTA:
		Loc_u8PinValue = GET_BIT(GPIO_GPIOA_IDR, Cpy_u8PinNum);
		break;
	case GPIO_U8_PORTB:
		Loc_u8PinValue = GET_BIT(GPIO_GPIOB_IDR, Cpy_u8PinNum);
		break;
	case GPIO_U8_PORTC:
		Loc_u8PinValue = GET_BIT(GPIO_GPIOC_IDR, Cpy_u8PinNum);
		break;
	}
	return Loc_u8PinValue;
}

void GPIO_voidSetPinMode(u8 Cpy_u8Port, u8 Cpy_u8PinNum, u8 Cpy_u8PinConfig, /* Sets wanted pin Mode */
u8 Cpy_u8PinOutputMode) {

	u8 Cpy_u8PinMode = ((Cpy_u8PinConfig << 2) | Cpy_u8PinOutputMode);

	switch (Cpy_u8Port) {
	case GPIO_U8_PORTA:

		if (Cpy_u8PinNum <= 7) {

			GPIO_GPIOA_CRL &= ~(u32) ((0b1111) << (Cpy_u8PinNum * 4));
			GPIO_GPIOA_CRL |= (u32) ((Cpy_u8PinMode) << (Cpy_u8PinNum * 4));

		} else if (Cpy_u8PinNum <= 15) {

			GPIO_GPIOA_CRH &= ~(u32) ((0b1111) << ((Cpy_u8PinNum - 8) * 4));
			GPIO_GPIOA_CRH |= (u32) ((Cpy_u8PinMode) << (Cpy_u8PinNum * 4));

		} else {

		}

		break;

	case GPIO_U8_PORTB:
		if (Cpy_u8PinNum <= 7) {

			GPIO_GPIOB_CRL &= ~(u32) ((0b1111) << (Cpy_u8PinNum * 4));
			GPIO_GPIOB_CRL |= (u32) ((Cpy_u8PinMode) << (Cpy_u8PinNum * 4));

		} else if (Cpy_u8PinNum <= 15) {

			GPIO_GPIOB_CRH &= ~(u32) ((0b1111) << ((Cpy_u8PinNum - 8) * 4));
			GPIO_GPIOB_CRH |= (u32) ((Cpy_u8PinMode) << (Cpy_u8PinNum * 4));

		} else {

		}
		break;

	case GPIO_U8_PORTC:
		if (Cpy_u8PinNum <= 7) {

			GPIO_GPIOC_CRL &= ~(u32) ((0b1111) << (Cpy_u8PinNum * 4));
			GPIO_GPIOC_CRL |= (u32) ((Cpy_u8PinMode) << (Cpy_u8PinNum * 4));

		} else if (Cpy_u8PinNum <= 15) {

			GPIO_GPIOC_CRH &= ~(u32) ((0b1111) << ((Cpy_u8PinNum - 8) * 4));
			GPIO_GPIOC_CRH |= (u32) ((Cpy_u8PinMode) << (Cpy_u8PinNum * 4));

		} else {

		}
		break;
	}
}

void GPIO_voidSetPinPullingState(u8 Cpy_u8Port, u8 Cpy_u8PinNum,
		u8 Cpy_u8PullingState) { /* Sets wanted pin Pulling state (Up or Down) */

	switch (Cpy_u8Port) {

	case GPIO_U8_PORTA:
		GPIO_GPIOA_BSRR = (Cpy_u8PullingState << Cpy_u8PinNum);
		break;
	case GPIO_U8_PORTB:

		GPIO_GPIOB_BSRR = (Cpy_u8PullingState << Cpy_u8PinNum);
		break;
	case GPIO_U8_PORTC:
		GPIO_GPIOC_BSRR = (Cpy_u8PullingState << Cpy_u8PinNum);
		break;
	}

}

void GPIO_voidPinLock(u8 Cpy_u8Port, u8 Cpy_u8PinNum) { 				/* Locks a specific pin Mode */

	u32 Loc_u32temp = 0x00010000;
	Loc_u32temp |= (1 << Cpy_u8PinNum);

	switch (Cpy_u8Port) {

	case GPIO_U8_PORTA:

		if (Cpy_u8PinNum < 16) {

			GPIO_GPIOA_LCKR = Loc_u32temp;
			GPIO_GPIOA_LCKR = (1 << Cpy_u8PinNum);
			GPIO_GPIOA_LCKR = Loc_u32temp;
			Loc_u32temp = GPIO_GPIOA_LCKR;
			Loc_u32temp = GPIO_GPIOA_LCKR;
		} else {

		}
		break;

	case GPIO_U8_PORTB:

		if (Cpy_u8PinNum < 16) {
			GPIO_GPIOB_LCKR = Loc_u32temp;
			GPIO_GPIOB_LCKR = (1 << Cpy_u8PinNum);
			GPIO_GPIOB_LCKR = Loc_u32temp;
			Loc_u32temp = GPIO_GPIOB_LCKR;
			Loc_u32temp = GPIO_GPIOB_LCKR;
		} else {

		}
		break;

	case GPIO_U8_PORTC:

		if (Cpy_u8PinNum < 16) {
			GPIO_GPIOC_LCKR = Loc_u32temp;
			GPIO_GPIOC_LCKR = (1 << Cpy_u8PinNum);
			GPIO_GPIOC_LCKR = Loc_u32temp;
			Loc_u32temp = GPIO_GPIOC_LCKR;
			Loc_u32temp = GPIO_GPIOC_LCKR;
		} else {

		}
		break;

	}

}

void GPIO_voidPortLock(u8 Cpy_u8Port) {										/* Locks all pins Modes of a specific port */

	u32 Loc_u32LckVal;

	switch (Cpy_u8Port) {

		case GPIO_U8_PORTA:
			GPIO_GPIOA_LCKR = 0x1FFFF;
			GPIO_GPIOA_LCKR = 0xFFFF;
			GPIO_GPIOA_LCKR = 0x1FFFF;
			Loc_u32LckVal = GPIO_GPIOA_LCKR;
			Loc_u32LckVal = GPIO_GPIOA_LCKR;

			break;

		case GPIO_U8_PORTB:

			GPIO_GPIOB_LCKR = 0x0FFFF;
			GPIO_GPIOB_LCKR = 0x1FFFF;
			GPIO_GPIOB_LCKR = 0x0FFFF;
			GPIO_GPIOB_LCKR = 0x1FFFF;
			Loc_u32LckVal = GPIO_GPIOB_LCKR;
			Loc_u32LckVal = GPIO_GPIOB_LCKR;

			break;

		case GPIO_U8_PORTC:

			GPIO_GPIOC_LCKR = 0x0FFFF;
			GPIO_GPIOC_LCKR = 0x1FFFF;
			GPIO_GPIOC_LCKR = 0x0FFFF;
			GPIO_GPIOC_LCKR = 0x1FFFF;
			Loc_u32LckVal = GPIO_GPIOC_LCKR;
			Loc_u32LckVal = GPIO_GPIOC_LCKR;

			break;

		}

}
