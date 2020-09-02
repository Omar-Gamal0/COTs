/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V31								*/
/* 	Date: 31 August 2020						*/
/************************************************/

#ifndef HLED_MATRIX_CONFIG_H_
#define HLED_MATRIX_CONFIG_H_

/* Please write pin pair port,pin for rows & columns*/
#define HLED_MATRIX_ROW0_PIN					GPIO_U8_PORTA,GPIO_U8_PIN0
#define HLED_MATRIX_ROW1_PIN					GPIO_U8_PORTA,GPIO_U8_PIN1
#define HLED_MATRIX_ROW2_PIN					GPIO_U8_PORTA,GPIO_U8_PIN2
#define HLED_MATRIX_ROW3_PIN					GPIO_U8_PORTA,GPIO_U8_PIN3
#define HLED_MATRIX_ROW4_PIN					GPIO_U8_PORTA,GPIO_U8_PIN4
#define HLED_MATRIX_ROW5_PIN					GPIO_U8_PORTA,GPIO_U8_PIN5
#define HLED_MATRIX_ROW6_PIN					GPIO_U8_PORTA,GPIO_U8_PIN6
#define HLED_MATRIX_ROW7_PIN					GPIO_U8_PORTA,GPIO_U8_PIN7

#define HLED_MATRIX_COL0_PIN		        	GPIO_U8_PORTB,GPIO_U8_PIN0
#define HLED_MATRIX_COL1_PIN		        	GPIO_U8_PORTB,GPIO_U8_PIN1
#define HLED_MATRIX_COL2_PIN		        	GPIO_U8_PORTB,GPIO_U8_PIN5
#define HLED_MATRIX_COL3_PIN		        	GPIO_U8_PORTB,GPIO_U8_PIN6
#define HLED_MATRIX_COL4_PIN		        	GPIO_U8_PORTB,GPIO_U8_PIN7
#define HLED_MATRIX_COL5_PIN		        	GPIO_U8_PORTB,GPIO_U8_PIN8
#define HLED_MATRIX_COL6_PIN		        	GPIO_U8_PORTB,GPIO_U8_PIN9
#define HLED_MATRIX_COL7_PIN		        	GPIO_U8_PORTB,GPIO_U8_PIN10
/****************************************************/

/**/
#define HLED_MATRIX_U8_MAX_NO_OF_CHARS_IN_WORD	30
/**/

#endif /* HLED_MATRIX_CONFIG_H_ */
