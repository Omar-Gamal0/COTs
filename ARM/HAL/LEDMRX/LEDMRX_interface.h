/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V31								*/
/* 	Date: 31 August 2020						*/
/************************************************/

#ifndef HLED_MATRIX_INTERFACE_H_
#define HLED_MATRIX_INTERFACE_H_

#define ROWS						0
#define COLS						1

/* HLED_Matrix_voidInit --> Initializes Led Matrix & Sets it's pins' mode as output with max frequency 2MHz */
/* I/P: void																								*/
/* O/P: void 																								*/
void HLED_Matrix_voidInit(void);
/************************************************************************************************************/

/* HLED_Matrix_voidCharDisp --> Displays a certain character on the LED matrix 								*/
/* I/P: Cpy_u8Data:- Character (of u8 type) to be displayed
 * 		Cpy_u32Time:- Time for which the character is to be shown in micro seconds							*/
/* O/P: void 																								*/
void HLED_Matrix_voidCharDisp(u8 Cpy_u8Data,u32 Cpy_u32Time);
/************************************************************************************************************/

/* HLED_Matrix_voidCharDisp --> Displays a certain word on the LED matrix 								*/
/* I/P: Cpy_u8Word:- Word to be displayed (of Array of u8 type)
 * 		Cpy_u32Time:- Time for which each full frame is to be shown in micro seconds							*/
/* O/P: void 																								*/
void HLED_Matrix_voidWordDisp(u8 *Cpy_u8Word, u32 Cpy_u32Time);

#endif /* HLED_MATRIX_INTERFACE_H_ */
