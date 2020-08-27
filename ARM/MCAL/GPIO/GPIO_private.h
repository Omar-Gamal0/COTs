/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V03								*/
/* 	Date: 19 August 2020						*/
/************************************************/

#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

/* Registers Macros definitions */

/* Ports starting addresses */

#define GPIO_PORTA_START_ADDRESS 			0x40010800				/* Macro holding value of the Start (Base) address of PortA registers */
#define GPIO_PORTB_START_ADDRESS			0x40010C00				/* Macro holding value of the Start (Base) address of PortB registers */
#define GPIO_PORTC_START_ADDRESS			0x40011000				/* Macro holding value of the Start (Base) address of PortC registers */

/****************************/

/* PORTA Registers */

#define GPIO_GPIOA_CRL 						*((volatile u32 *) (GPIO_PORTA_START_ADDRESS + 0x00))		/* Macro holding value of PortA CRL */
#define GPIO_GPIOA_CRH 						*((volatile u32 *) (GPIO_PORTA_START_ADDRESS + 0x04))		/* Macro holding value of PortA CRH */
#define GPIO_GPIOA_IDR 						*((volatile u32 *) (GPIO_PORTA_START_ADDRESS + 0x08))		/* Macro holding value of PortA IDR */
#define GPIO_GPIOA_ODR 						*((volatile u32 *) (GPIO_PORTA_START_ADDRESS + 0x0C))		/* Macro holding value of PortA ODR */
#define GPIO_GPIOA_BSRR 					*((volatile u32 *) (GPIO_PORTA_START_ADDRESS + 0x10))		/* Macro holding value of PortA BSRR */
#define GPIO_GPIOA_BRR 						*((volatile u32 *) (GPIO_PORTA_START_ADDRESS + 0x14))		/* Macro holding value of PortA BRR */
#define GPIO_GPIOA_LCKR 					*((volatile u32 *) (GPIO_PORTA_START_ADDRESS + 0x18))		/* Macro holding value of PortA LCKR */

/*******************/

/* PORTB Registers */

#define GPIO_GPIOB_CRL 						*((volatile u32 *) (GPIO_PORTB_START_ADDRESS + 0x00))        /* Macro holding value of PortB CRL */
#define GPIO_GPIOB_CRH 						*((volatile u32 *) (GPIO_PORTB_START_ADDRESS + 0x04))        /* Macro holding value of PortB CRH */
#define GPIO_GPIOB_IDR 						*((volatile u32 *) (GPIO_PORTB_START_ADDRESS + 0x08))        /* Macro holding value of PortB IDR */
#define GPIO_GPIOB_ODR 						*((volatile u32 *) (GPIO_PORTB_START_ADDRESS + 0x0C))        /* Macro holding value of PortB ODR */
#define GPIO_GPIOB_BSRR 					*((volatile u32 *) (GPIO_PORTB_START_ADDRESS + 0x10))        /* Macro holding value of PortB BSRR */
#define GPIO_GPIOB_BRR 						*((volatile u32 *) (GPIO_PORTB_START_ADDRESS + 0x14))        /* Macro holding value of PortB BRR */
#define GPIO_GPIOB_LCKR 					*((volatile u32 *) (GPIO_PORTB_START_ADDRESS + 0x18))        /* Macro holding value of PortB LCKR */

/*******************/

/* PORTC Registers */

#define GPIO_GPIOC_CRL 						*((volatile u32 *) (GPIO_PORTC_START_ADDRESS + 0x00))        /* Macro holding value of PortC CRL */
#define GPIO_GPIOC_CRH 						*((volatile u32 *) (GPIO_PORTC_START_ADDRESS + 0x04))        /* Macro holding value of PortC CRH */
#define GPIO_GPIOC_IDR 						*((volatile u32 *) (GPIO_PORTC_START_ADDRESS + 0x08))        /* Macro holding value of PortC IDR */
#define GPIO_GPIOC_ODR 						*((volatile u32 *) (GPIO_PORTC_START_ADDRESS + 0x0C))        /* Macro holding value of PortC ODR */
#define GPIO_GPIOC_BSRR 					*((volatile u32 *) (GPIO_PORTC_START_ADDRESS + 0x10))        /* Macro holding value of PortC BSRR */
#define GPIO_GPIOC_BRR 						*((volatile u32 *) (GPIO_PORTC_START_ADDRESS + 0x14))        /* Macro holding value of PortC BRR */
#define GPIO_GPIOC_LCKR 					*((volatile u32 *) (GPIO_PORTC_START_ADDRESS + 0x18))        /* Macro holding value of PortC LCKR */

/*******************/

/********************************/


/* Private Functions */

/*********************/

#endif

