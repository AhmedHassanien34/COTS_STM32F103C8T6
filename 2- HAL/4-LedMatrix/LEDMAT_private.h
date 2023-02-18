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

#ifndef LEDMAT_PRIVATE_H
#define LEDMAT_PRIVATE_H

/********************************************************************************************/
/* Private Functions Prototype					 			                                */
/********************************************************************************************/
static void DisableColumns(void);

/* Number of Rows */
#define LEDMAT_ROWS_NUMBER						8

/* Number of Columns */
#define LEDMAT_COLS_NUMBER						8

/* FPS Time in ms */
#define LEDMAT_FPS_TIME							2500

/* Define Mapping Indx */
#define LEDMAT_INDX0 							0
#define LEDMAT_INDX1 							1
#define LEDMAT_INDX2 							2
#define LEDMAT_INDX3 							3
#define LEDMAT_INDX4 							4
#define LEDMAT_INDX5 							5
#define LEDMAT_INDX6 							6
#define LEDMAT_INDX8 							8
#define LEDMAT_INDX9 							9
#define LEDMAT_INDX10							10
#define LEDMAT_INDX11							11
#define LEDMAT_INDX12							12
#define LEDMAT_INDX13							13
#define LEDMAT_INDX14							14

/* Initialize Array that carry port and pin configuration for LEDMAT ROWS */
static u8 LEDMAT_RowsPortPins[LEDMAT_ROWS_NUMBER][2] = {{LEDMAT_ROW0_PIN},
		{LEDMAT_ROW1_PIN},
		{LEDMAT_ROW2_PIN},
		{LEDMAT_ROW3_PIN},
		{LEDMAT_ROW4_PIN},
		{LEDMAT_ROW5_PIN},
		{LEDMAT_ROW6_PIN},
		{LEDMAT_ROW7_PIN}};

/* Initialize Array that carry port and pin configuration for LEDMAT COLUMNS */												
static u8 LEDMAT_ColsPortPins[LEDMAT_COLS_NUMBER][2] = {{LEDMAT_COL0_PIN},
		{LEDMAT_COL1_PIN},
		{LEDMAT_COL2_PIN},
		{LEDMAT_COL3_PIN},
		{LEDMAT_COL4_PIN},
		{LEDMAT_COL5_PIN},
		{LEDMAT_COL6_PIN},
		{LEDMAT_COL7_PIN}};


/******************************************************************************/
/* Syntax          : static void DisableColumns(void)
 * Description      : Disable All Columns on Led Matrix
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
static void DisableColumns(void)
{
	/* Declare Local Counter */
	u8 Local_u8Counter;

	/* Disable All Columns */
	for(Local_u8Counter = NULL; Local_u8Counter < LEDMAT_COLS_NUMBER; Local_u8Counter++)
	{
		MGPIO_u8SetPinValue(LEDMAT_ColsPortPins[Local_u8Counter][0] , LEDMAT_ColsPortPins[Local_u8Counter][1] , GPIO_HIGH);
	}
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/

#endif
/********************************************************************************************/
/* END OF FILE: LEDMAT_private.h                                                            */
/********************************************************************************************/
