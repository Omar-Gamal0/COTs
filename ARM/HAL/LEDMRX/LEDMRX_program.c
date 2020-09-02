/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V31								*/
/* 	Date: 31 August 2020						*/
/************************************************/

/* Library layer includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**************************/

/* Mcal layer Includes */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
/***********************/

/* HLED includes */
#include "LEDMRX_config.h"
#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
/*****************/

/*
 * Try making the code generate the array for the word
 */

u8 HLED_Matrix_Char_A[8]={0, 124, 18, 18, 18, 124, 0, 0};
u8 HLED_Matrix_Char_B[8]={0, 126, 82, 82, 82, 44, 0, 0};
u8 HLED_Matrix_Char_C[8]={0, 60, 66, 66, 66, 66, 0, 0};
u8 HLED_Matrix_Char_D[8]={0, 126, 66, 66, 66, 60, 0, 0};
u8 HLED_Matrix_Char_E[8]={0, 126, 82, 82, 82, 66, 0, 0};
u8 HLED_Matrix_Char_F[8]={0, 126, 18, 18, 18, 2, 0, 0};
u8 HLED_Matrix_Char_G[8]={0, 60, 66, 66, 82, 48, 0, 0};
u8 HLED_Matrix_Char_H[8]={0, 126, 16, 16, 16, 126, 0, 0};
u8 HLED_Matrix_Char_I[8]={0, 66, 66, 126, 66, 66, 0, 0};
u8 HLED_Matrix_Char_J[8]={0, 50, 66, 66, 62, 2, 0, 0};
u8 HLED_Matrix_Char_K[8]={0, 126, 8, 8, 20, 98, 0, 0};
u8 HLED_Matrix_Char_L[8]={0, 126, 64, 64, 64, 0, 0, 0};
u8 HLED_Matrix_Char_M[8]={0, 126, 4, 8, 4, 126, 0, 0};
u8 HLED_Matrix_Char_N[8]={0, 126, 4, 8, 16, 126, 0, 0};
u8 HLED_Matrix_Char_O[8]={0, 60, 66, 66, 66, 66, 60, 0};
u8 HLED_Matrix_Char_P[8]={0, 126, 18, 18, 18, 12, 0, 0};
u8 HLED_Matrix_Char_Q[8]={0, 60, 66, 82, 98, 60, 0, 0};
u8 HLED_Matrix_Char_R[8]={0, 126, 18, 18, 50, 76, 0, 0};
u8 HLED_Matrix_Char_S[8]={0, 76, 82, 82, 82, 34, 0, 0};
u8 HLED_Matrix_Char_T[8]={0, 2, 2, 126, 2, 2, 0, 0};
u8 HLED_Matrix_Char_U[8]={0, 62, 64, 64, 64, 62, 0, 0};
u8 HLED_Matrix_Char_V[8]={0, 30, 32, 64, 32, 30, 0, 0};
u8 HLED_Matrix_Char_W[8]={0, 126, 32, 16, 32, 126, 0, 0};
u8 HLED_Matrix_Char_X[8]={0, 70, 40, 16, 40, 70, 0, 0};
u8 HLED_Matrix_Char_Y[8]={0, 6, 8, 112, 8, 6, 0, 0};
u8 HLED_Matrix_Char_Z[8]={0, 98, 114, 90, 78, 70, 0, 0};

void HLED_Matrix_voidInit(void)
{

	GPIO_voidSetPinMode(HLED_MATRIX_ROW0_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_ROW1_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_ROW2_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_ROW3_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_ROW4_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_ROW5_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_ROW6_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_ROW7_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);


	GPIO_voidSetPinMode(HLED_MATRIX_COL0_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_COL1_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_COL2_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_COL3_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_COL4_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_COL5_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_COL6_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(HLED_MATRIX_COL7_PIN,GPIO_U8_OUTPUT_MODE_GP_PP,GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);

}

static void callback(void){
	asm("NOP");
}

void HLED_Matrix_voidCharDisp(u8 Cpy_u8Data,u32 Cpy_u32Time)
{
	u8 Loc_u8Char[8];
	if(Cpy_u8Data == 'A'){
		for(u8 i = 0; i<8; i++)
		(Loc_u8Char[i] = HLED_Matrix_Char_A[i]);
	}
	u32 Loc_u32TimesOfDisp = 8*2500;
	Loc_u32TimesOfDisp = Cpy_u32Time/Loc_u32TimesOfDisp;
	for(u32 i = 0; i<Loc_u32TimesOfDisp; i++){
/* Displaying the data														*/
	for(u8 i = 0; i<8; i++){
	/* Disable all columns */
	HLED_Matrix_voidDisableAllCols();
	/***********************/

	/* Writing corresponding value of Rows 	*/
	HLED_Matrix_voidSetRowVal(Loc_u8Char[i]);
	/****************************************/

	/*Enable column i */
	HLED_Matrix_voidSetLineVal(COLS,i,GPIO_U8_LOW);
	/*****************/
/****************************************************************************/
	MSTK_voidSetBusyWait(2500,STK_U8_MICROS,callback);			/* Busy wait for 2.5ms */
	}
	}

}


void HLED_Matrix_voidWordDisp(u8 *Cpy_u8Word, u32 Cpy_u32Time)
{
	u8 Loc_u8Word[HLED_MATRIX_U8_MAX_NO_OF_CHARS_IN_WORD][8];
	u8 NumberOfChar = 0;
	while(Cpy_u8Word[NumberOfChar] != '\0'){
		switch(Cpy_u8Word[NumberOfChar]){
		case 'A':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_A[i];
			}break;
		case 'B':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_B[i];
			}break;
		case 'C':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_C[i];
			}break;
		case 'D':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_D[i];
			}break;
		case 'E':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_E[i];
			}break;
		case 'F':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_F[i];
			}break;
		case 'G':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_G[i];
			}break;
		case 'H':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_H[i];
			}break;
		case 'I':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_I[i];
			}break;
		case 'J':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_J[i];
			}break;
		case 'K':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_K[i];
			}break;
		case 'L':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_L[i];
			}break;
		case 'M':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_M[i];
			}break;
		case 'N':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_N[i];
			}break;
		case 'O':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_O[i];
			}break;
		case 'P':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_P[i];
			}break;
		case 'Q':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_Q[i];
			}break;
		case 'R':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_R[i];
			}break;
		case 'S':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_S[i];
			}break;
		case 'T':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_T[i];
			}break;
		case 'U':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_U[i];
			}break;
		case 'V':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_V[i];
			}break;
		case 'W':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_W[i];
			}break;
		case 'X':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_X[i];
			}break;
		case 'Y':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_Y[i];
			}break;
		case 'Z':
			for(u8 i = 0; i<8; i++){
				Loc_u8Word[NumberOfChar][i]= HLED_Matrix_Char_Z[i];
			}break;
		}
		NumberOfChar++;
	}
	u8 Loc_u8CurrentChar[8];
	u8 Loc_u8TempIndex = 0;
	u8 Loc_u8CharIndex = 0;
	u32 Loc_u32TimesOfDisp = 8*2500;
	Loc_u32TimesOfDisp = Cpy_u32Time/Loc_u32TimesOfDisp;
/* Displaying the data														*/
	for(u8 CurrentStart = 0; CurrentStart < ((NumberOfChar)*8); CurrentStart++){

		for(u8 CurrentCharIndex = 0;CurrentCharIndex < 8;CurrentCharIndex++){
			Loc_u8TempIndex = (CurrentStart+CurrentCharIndex);
			if(Loc_u8TempIndex < ((NumberOfChar)*8)){
				Loc_u8CharIndex = Loc_u8TempIndex / 8;
				Loc_u8TempIndex %= 8;
				Loc_u8CurrentChar[CurrentCharIndex] = Loc_u8Word[Loc_u8CharIndex][Loc_u8TempIndex];
			}else{
				Loc_u8TempIndex %= 8;
				Loc_u8CurrentChar[CurrentCharIndex] = Loc_u8Word[0][Loc_u8TempIndex];
			}

		}

for(u8 Hold = 0; Hold < (Loc_u32TimesOfDisp); Hold++ ){
		for(u8 i = 0; i<8; i++){
		/* Disable all columns */
		HLED_Matrix_voidDisableAllCols();
		/***********************/

		/* Writing corresponding value of Rows 	*/
		HLED_Matrix_voidSetRowVal(Loc_u8CurrentChar[i]);
		/****************************************/

		/*Enable column i */
		HLED_Matrix_voidSetLineVal(COLS,i,GPIO_U8_LOW);
		/*****************/
	/****************************************************************************/
		MSTK_voidSetBusyWait(2500,STK_U8_MICROS,callback);			/* Busy wait for 2.5ms */
		}
}
	}


}

static void HLED_Matrix_voidDisableAllCols(void){
	for (u8 i = 0; i<8; i++){
		HLED_Matrix_voidSetLineVal(COLS,i,GPIO_U8_HIGH);
	}

}

static void HLED_Matrix_voidSetRowVal(u8 Cpy_u8Val){
	/* Writing corresponding value of Rows 	*/
	for (u8 i = 0; i<8; i++){

		HLED_Matrix_voidSetLineVal(ROWS,i,GET_BIT(Cpy_u8Val, i));

	}
	/****************************************/
}

static void HLED_Matrix_voidSetLineVal(u8 Cpy_u8LineType, u8 Cpy_u8LineNum,u8 Cpy_u8LineVal){
	switch (Cpy_u8LineType){
	case ROWS:
		switch(Cpy_u8LineNum){
		case 0:	GPIO_voidSetPinVal(HLED_MATRIX_ROW0_PIN,Cpy_u8LineVal);			break;
		case 1:	GPIO_voidSetPinVal(HLED_MATRIX_ROW1_PIN,Cpy_u8LineVal);			break;
		case 2:	GPIO_voidSetPinVal(HLED_MATRIX_ROW2_PIN,Cpy_u8LineVal);			break;
		case 3:	GPIO_voidSetPinVal(HLED_MATRIX_ROW3_PIN,Cpy_u8LineVal);			break;
		case 4:	GPIO_voidSetPinVal(HLED_MATRIX_ROW4_PIN,Cpy_u8LineVal);			break;
		case 5:	GPIO_voidSetPinVal(HLED_MATRIX_ROW5_PIN,Cpy_u8LineVal);			break;
		case 6:	GPIO_voidSetPinVal(HLED_MATRIX_ROW6_PIN,Cpy_u8LineVal);			break;
		case 7:	GPIO_voidSetPinVal(HLED_MATRIX_ROW7_PIN,Cpy_u8LineVal);			break;
		}
		break;

	case COLS:
		switch(Cpy_u8LineNum){
		case 0:	GPIO_voidSetPinVal(HLED_MATRIX_COL0_PIN,Cpy_u8LineVal);			break;
		case 1:	GPIO_voidSetPinVal(HLED_MATRIX_COL1_PIN,Cpy_u8LineVal);			break;
		case 2:	GPIO_voidSetPinVal(HLED_MATRIX_COL2_PIN,Cpy_u8LineVal);			break;
		case 3:	GPIO_voidSetPinVal(HLED_MATRIX_COL3_PIN,Cpy_u8LineVal);			break;
		case 4:	GPIO_voidSetPinVal(HLED_MATRIX_COL4_PIN,Cpy_u8LineVal);			break;
		case 5:	GPIO_voidSetPinVal(HLED_MATRIX_COL5_PIN,Cpy_u8LineVal);			break;
		case 6:	GPIO_voidSetPinVal(HLED_MATRIX_COL6_PIN,Cpy_u8LineVal);			break;
		case 7:	GPIO_voidSetPinVal(HLED_MATRIX_COL7_PIN,Cpy_u8LineVal);			break;
		}
		break;
	}
}

