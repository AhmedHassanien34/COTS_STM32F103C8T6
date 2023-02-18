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
/* Include libraries                                                                        */
/********************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/********************************************************************************************/
/* Include Interface Files in MCAL                                                          */
/********************************************************************************************/
#include "GPIO_interface.h"
#include "STK_interface.h"

/********************************************************************************************/
/* Include Component Files                                                                  */
/********************************************************************************************/
#include "LEDMAT_interface.h"
#include "LEDMAT_private.h"
#include "LEDMAT_config.h"


/******************************************************************************/
/* Syntax           : void HLEDMAT_voidInit(void)
 * Description      : Initialize Pins of Led Matrix
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void HLEDMAT_voidInit(void)
{
	/* Declare Local Counter */
	u8 Local_u8Counter;

	/* Set Rows Direction */
	for(Local_u8Counter = NULL; Local_u8Counter < LEDMAT_ROWS_NUMBER; Local_u8Counter++)
	{
		MGPIO_u8SetPinDirection(LEDMAT_RowsPortPins[Local_u8Counter][0] , LEDMAT_RowsPortPins[Local_u8Counter][1] , GPIO_OUTPUT_SPEED_2MHZ_PP);
	}

	/* Set Columns Direction */
	for(Local_u8Counter = NULL; Local_u8Counter < LEDMAT_COLS_NUMBER; Local_u8Counter++)
	{
		MGPIO_u8SetPinDirection(LEDMAT_ColsPortPins[Local_u8Counter][0] , LEDMAT_ColsPortPins[Local_u8Counter][1] , GPIO_OUTPUT_SPEED_2MHZ_PP);
	}
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void HLEDMAT_voidDisplayChar(u8 *Copy_pu8Data , u16 Copy_u16DisplayTime)
 * Description      : Display One char on Led Matrix
 * Sync\Async       : Synchronous
 * Parameters       : u8 *Copy_pu8Data , Copy_u16DisplayTime
 * Return value:    : void
 *******************************************************************************/
void HLEDMAT_voidDisplayChar(u8 *Copy_pu8Data , u16 Copy_u16DisplayTime)
{
	/* Declare Local Counters */
	u8 Local_u8ColsCounter , Local_u8RowsCounter;
	u16 Local_u16TimeCounter;

	/* Declare Local Variable to carry Row Data Bit */
	u8 Local_u8RowDataBit;

	/* Initialize Local variable to carry actual counts for Second Loop */
	u16 Local_u16Count = (Copy_u16DisplayTime / 25);

	/* First loop For Timing Display */
	for(Local_u16TimeCounter = 0; Local_u16TimeCounter < Local_u16Count; Local_u16TimeCounter++)
	{
		/* Set Rows values and activate Certain Column */
		for(Local_u8ColsCounter = NULL; Local_u8ColsCounter < LEDMAT_COLS_NUMBER; Local_u8ColsCounter++)
		{
			/* Disable All Columns */
			DisableColumns();

			for(Local_u8RowsCounter = NULL; Local_u8RowsCounter < LEDMAT_ROWS_NUMBER; Local_u8RowsCounter++)
			{
				/* Get Row Data Bit */
				Local_u8RowDataBit = GET_BIT(Copy_pu8Data[Local_u8ColsCounter] , Local_u8RowsCounter);

				/* Set Row value */
				MGPIO_u8SetPinValue(LEDMAT_RowsPortPins[Local_u8RowsCounter][0] , LEDMAT_RowsPortPins[Local_u8RowsCounter][1] , Local_u8RowDataBit);
			}
			/* Activate Certain Column */
			MGPIO_u8SetPinValue(LEDMAT_ColsPortPins[Local_u8ColsCounter][0] , LEDMAT_ColsPortPins[Local_u8ColsCounter][1] , GPIO_LOW);

			/* Wait untill FPS Time */
			MSTK_voidSetBusyWaitInMicroSec(LEDMAT_FPS_TIME);
		}
	}
	/* For garbage Disable all columns */
	DisableColumns();
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void HLEDMAT_voidMoveChar(u8 *Copy_pu8Data)
 * Description      : Move One char on Led Matrix
 * Sync\Async       : Synchronous
 * Parameters       : u8 *Copy_pu8Data
 * Return value:    : void
 *******************************************************************************/
void HLEDMAT_voidMoveChar(u8 *Copy_pu8Data)
{
	/* Declare Local Counters */
	u8 Local_u8ColsCounter , Local_u8RowsCounter , Local_u8Nextcolumn;
	u16 Local_u16TimeCounter;

	/* Declare Local Variable to carry Row Data Bit */
	u8 Local_u8RowDataBit;

	/* Declare Indx variable */
	u8 Local_u8Indx;

	/* Initialize Local variable to carry actual counts for Second Loop */
	u16 Local_u16Count = (LEDMAT_FRAME_MOVE_TIME / 25);

	/* First Loop To Shift Columns */
	for(Local_u8Nextcolumn = NULL ; Local_u8Nextcolumn < LEDMAT_COLS_NUMBER; Local_u8Nextcolumn++)
	{
		/* Second loop For Time between every column shifting */
		for(Local_u16TimeCounter = 0; Local_u16TimeCounter < Local_u16Count; Local_u16TimeCounter++)
		{
			/* Third loop to iterate on certain Column to activate it */
			for(Local_u8ColsCounter = NULL; Local_u8ColsCounter < LEDMAT_COLS_NUMBER; Local_u8ColsCounter++)
			{
				/* Disable All Columns */
				DisableColumns();

				/* Fourth Loop to Set ROWS Values */
				for(Local_u8RowsCounter = NULL; Local_u8RowsCounter < LEDMAT_ROWS_NUMBER; Local_u8RowsCounter++)
				{
					/* Assign actual indx of Copy_pu8Data for shifting column */
					if((Local_u8ColsCounter+Local_u8Nextcolumn) > (LEDMAT_COLS_NUMBER - 1))
					{
						Local_u8Indx = (Local_u8ColsCounter+Local_u8Nextcolumn) - LEDMAT_COLS_NUMBER;
					}
					else
					{
						Local_u8Indx = Local_u8ColsCounter+Local_u8Nextcolumn;
					}

					/* Get Row Data Bit */
					Local_u8RowDataBit = GET_BIT(Copy_pu8Data[Local_u8Indx] , Local_u8RowsCounter);

					/* Set Row value */
					MGPIO_u8SetPinValue(LEDMAT_RowsPortPins[Local_u8RowsCounter][0] , LEDMAT_RowsPortPins[Local_u8RowsCounter][1] , Local_u8RowDataBit);
				}
				/* Activate Certain Column */
				MGPIO_u8SetPinValue(LEDMAT_ColsPortPins[Local_u8ColsCounter][0] , LEDMAT_ColsPortPins[Local_u8ColsCounter][1] , GPIO_LOW);

				/* Wait untill FPS Time */
				MSTK_voidSetBusyWaitInMicroSec(LEDMAT_FPS_TIME);
			}
		}
	}
	/* For garbage Disable all columns */
	DisableColumns();
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void HLEDMAT_voidMoveFrameRToL(u8 Copy_pu8Data[LEDMAT_CHAR_NUMBERS_MoveFRAME_R_TO_L][LEDMAT_COL_NUMBERS])
 * Description      : Move Frame from Right to Left on Led Matrix
 * Sync\Async       : Synchronous
 * Parameters       : u8 Copy_pu8Data[LEDMAT_CHAR_NUMBERS_MoveFRAME_R_TO_L][LEDMAT_COL_NUMBERS]
 * Return value:    : void
 *******************************************************************************/
void HLEDMAT_voidMoveFrameRToL(u8 Copy_pu8Data[LEDMAT_CHAR_NUMBERS_MoveFRAME_R_TO_L][LEDMAT_COL_NUMBERS])
{
	/* Declare Local Counters */
	u8 Local_u8ColsCounter , Local_u8RowsCounter;
	u16 Local_u16TimeCounter;
	s32 Local_s32Nextcolumn;

	/* Declare Local Variable to carry Row Data Bit */
	u8 Local_u8RowDataBit;

	/* Declare Indx variable */
	u8 Local_u8Indx2;
	s8 Local_s8Indx1;

	/* Initialize Local variable to carry actual counts for Second Loop */
	u16 Local_u16Count = (LEDMAT_FRAME_MOVE_TIME / 25);

	/* First Loop To Shift Columns */
	for(Local_s32Nextcolumn = -LEDMAT_COL_NUMBERS ; Local_s32Nextcolumn < (LEDMAT_CHAR_NUMBERS_MoveFRAME_R_TO_L * LEDMAT_COL_NUMBERS) ; Local_s32Nextcolumn++)
	{
		/* Second loop For Time between every column shifting */
		for(Local_u16TimeCounter = 0; Local_u16TimeCounter < Local_u16Count; Local_u16TimeCounter++)
		{
			/* Third loop to iterate on certain Column to activate it */
			for(Local_u8ColsCounter = NULL; Local_u8ColsCounter < LEDMAT_COL_NUMBERS; Local_u8ColsCounter++)
			{
				/* Disable All Columns */
				DisableColumns();

				/* Fourth Loop to Set ROWS Values */
				for(Local_u8RowsCounter = NULL; Local_u8RowsCounter < LEDMAT_ROWS_NUMBER; Local_u8RowsCounter++)
				{
					/* Assign actual indx of Copy_pu8Data for shifting column */
					Local_s8Indx1 = (Local_u8ColsCounter+Local_s32Nextcolumn) / LEDMAT_COL_NUMBERS;

					/* Mapping indx2 */
					if((Local_u8ColsCounter+Local_s32Nextcolumn) > (LEDMAT_COL_NUMBERS - 1))
					{
						Local_u8Indx2 = ((Local_u8ColsCounter+Local_s32Nextcolumn) - LEDMAT_COL_NUMBERS);
						while(Local_u8Indx2 >= LEDMAT_COL_NUMBERS)
						{
							Local_u8Indx2 -= LEDMAT_COL_NUMBERS;
						}
					}
					else
					{
						Local_u8Indx2 = Local_u8ColsCounter+Local_s32Nextcolumn;
					}

					/* To avoid point to row which is not exist */
					if(Local_s8Indx1 > (LEDMAT_CHAR_NUMBERS_MoveFRAME_R_TO_L - 1))
					{
						MGPIO_u8SetPinValue(LEDMAT_RowsPortPins[Local_u8RowsCounter][0] , LEDMAT_RowsPortPins[Local_u8RowsCounter][1] , GPIO_LOW);
					}
					/* To provide space before start */
					else if(Local_u8Indx2 > (LEDMAT_COL_NUMBERS - 1))
					{
						MGPIO_u8SetPinValue(LEDMAT_RowsPortPins[Local_u8RowsCounter][0] , LEDMAT_RowsPortPins[Local_u8RowsCounter][1] , GPIO_LOW);
					}
					else
					{
						/* Get Row Data Bit */
						Local_u8RowDataBit = GET_BIT(Copy_pu8Data[Local_s8Indx1][Local_u8Indx2] , Local_u8RowsCounter);

						/* Set Row value */
						MGPIO_u8SetPinValue(LEDMAT_RowsPortPins[Local_u8RowsCounter][0] , LEDMAT_RowsPortPins[Local_u8RowsCounter][1] , Local_u8RowDataBit);
					}

				}

				/* Activate Certain Column move it from R To L */
				MGPIO_u8SetPinValue(LEDMAT_ColsPortPins[Local_u8ColsCounter][0] , LEDMAT_ColsPortPins[Local_u8ColsCounter][1] , GPIO_LOW);

				/* Wait untill FPS Time */
				MSTK_voidSetBusyWaitInMicroSec(LEDMAT_FPS_TIME);
			}
		}
	}

	/* For garbage Disable all columns */
	DisableColumns();
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void HLEDMAT_voidMoveFrameLToR(u8 Copy_pu8Data[LEDMAT_CHAR_NUMBERS_MoveFRAME_L_TO_R][LEDMAT_COL_NUMBERS])
 * Description      : Move Frame from Left to Right on Led Matrix
 * Sync\Async       : Synchronous
 * Parameters       : u8 Copy_pu8Data[LEDMAT_CHAR_NUMBERS_MoveFRAME_L_TO_R][LEDMAT_COL_NUMBERS]
 * Return value:    : void
 *******************************************************************************/
void HLEDMAT_voidMoveFrameLToR(u8 Copy_pu8Data[LEDMAT_CHAR_NUMBERS_MoveFRAME_L_TO_R][LEDMAT_COL_NUMBERS])
{
	/* Declare Local Counters */
	u8 Local_u8ColsCounter , Local_u8RowsCounter , Local_u8TimeCounter;
	s8 Local_s8Nextcolumn;

	/* Declare Local Variable to carry Row Data Bit */
	u8 Local_u8RowDataBit;

	/* Declare Indx variable */
	u8 Local_u8Indx2;
	s8 Local_s8Indx1;

	/* Initialize Local variable to carry actual counts for Second Loop */
	u8 Local_u8Count = (LEDMAT_FRAME_MOVE_TIME / 25);

	/* First Loop To Shift Columns */
	for(Local_s8Nextcolumn = -LEDMAT_COL_NUMBERS ; Local_s8Nextcolumn < (LEDMAT_CHAR_NUMBERS_MoveFRAME_L_TO_R * LEDMAT_COL_NUMBERS); Local_s8Nextcolumn++)
	{
		/* Second loop For Time between every column shifting */
		for(Local_u8TimeCounter = 0; Local_u8TimeCounter < Local_u8Count; Local_u8TimeCounter++)
		{
			/* Third loop to iterate on certain Column to activate it */
			for(Local_u8ColsCounter = NULL; Local_u8ColsCounter < LEDMAT_COL_NUMBERS; Local_u8ColsCounter++)
			{
				/* Disable All Columns */
				DisableColumns();

				/* Fourth Loop to Set ROWS Values */
				for(Local_u8RowsCounter = NULL; Local_u8RowsCounter < LEDMAT_ROWS_NUMBER; Local_u8RowsCounter++)
				{
					/* Assign actual indx of Copy_pu8Data for shifting column */
					Local_s8Indx1 = (Local_u8ColsCounter+Local_s8Nextcolumn) / LEDMAT_COL_NUMBERS;

					/* Mapping indx2 */
					if((Local_u8ColsCounter+Local_s8Nextcolumn) > (LEDMAT_COL_NUMBERS - 1))
					{
						Local_u8Indx2 = ((Local_u8ColsCounter+Local_s8Nextcolumn) - LEDMAT_COL_NUMBERS);
						while(Local_u8Indx2 >= LEDMAT_COL_NUMBERS)
						{
							Local_u8Indx2 -= LEDMAT_COL_NUMBERS;
						}
					}
					else
					{
						Local_u8Indx2 = Local_u8ColsCounter+Local_s8Nextcolumn;
					}

					/* Column 0 take value of Column n & Column1 take value of Column n-1 ...etc */
					Local_u8Indx2 = (LEDMAT_COL_NUMBERS - 1) - Local_u8Indx2;

					/* To avoid point to row which is not exist */
					if(Local_s8Indx1 > (LEDMAT_CHAR_NUMBERS_MoveFRAME_L_TO_R - 1))
					{
						MGPIO_u8SetPinValue(LEDMAT_RowsPortPins[Local_u8RowsCounter][0] , LEDMAT_RowsPortPins[Local_u8RowsCounter][1] , GPIO_LOW);
					}
					/* To provide space before start */
					else if(Local_u8Indx2 > (LEDMAT_COL_NUMBERS - 1))
					{
						MGPIO_u8SetPinValue(LEDMAT_RowsPortPins[Local_u8RowsCounter][0] , LEDMAT_RowsPortPins[Local_u8RowsCounter][1] , GPIO_LOW);
					}
					else
					{
						/* Get Row Data Bit */
						Local_u8RowDataBit = GET_BIT(Copy_pu8Data[Local_s8Indx1][Local_u8Indx2] , Local_u8RowsCounter);

						/* Set Row value */
						MGPIO_u8SetPinValue(LEDMAT_RowsPortPins[Local_u8RowsCounter][0] , LEDMAT_RowsPortPins[Local_u8RowsCounter][1] , Local_u8RowDataBit);
					}

				}

				/* Activate Certain Column & move it from L To R */
				MGPIO_u8SetPinValue(LEDMAT_ColsPortPins[(LEDMAT_COL_NUMBERS - 1)-Local_u8ColsCounter][0] , LEDMAT_ColsPortPins[(LEDMAT_COL_NUMBERS - 1)-Local_u8ColsCounter][1] , GPIO_LOW);

				/* Wait untill FPS Time */
				MSTK_voidSetBusyWaitInMicroSec(LEDMAT_FPS_TIME);
			}
		}
	}

	/* For garbage Disable all columns */
	DisableColumns();
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/********************************************************************************************/
/*   END OF FILE: LEDMAT_program.c                                                          */
/********************************************************************************************/
