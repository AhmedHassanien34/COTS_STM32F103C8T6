/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    18 February 2023	            		*************/
/**************************		Layer:   HAL								   	*************/
/**************************		SWC:	 LED_MATRIX								*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef LEDMAT_INTERFACE_H
#define LEDMAT_INTERFACE_H


/* Configure Size of 2D array */
#define LEDMAT_CHAR_NUMBERS_MoveFRAME_R_TO_L			        29
#define LEDMAT_CHAR_NUMBERS_MoveFRAME_L_TO_R			        2
#define LEDMAT_COL_NUMBERS										8



/********************************************************************************************/
/* Functions Prototype					 			                                        */
/********************************************************************************************/
void HLEDMAT_voidInit(void);

void HLEDMAT_voidDisplayChar(u8 *Copy_pu8Data , u16 Copy_u16DisplayTime);

void HLEDMAT_voidMoveChar(u8 *Copy_pu8Data);

void HLEDMAT_voidMoveFrameRToL(u8 Copy_pu8Data[LEDMAT_CHAR_NUMBERS_MoveFRAME_R_TO_L][LEDMAT_COL_NUMBERS]);

void HLEDMAT_voidMoveFrameLToR(u8 Copy_pu8Data[LEDMAT_CHAR_NUMBERS_MoveFRAME_L_TO_R][LEDMAT_COL_NUMBERS]);

#endif
/********************************************************************************************/
/* END OF FILE: LEDMAT_interface.h                                                          */
/********************************************************************************************/
