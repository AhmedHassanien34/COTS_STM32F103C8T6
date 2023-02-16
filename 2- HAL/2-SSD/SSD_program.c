/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    16 February 2023	            		*************/
/**************************		Layer:   HAL								   	*************/
/**************************		SWC:	 SSD									*************/
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

/********************************************************************************************/
/* Include Component Files                                                                  */
/********************************************************************************************/
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"


/******************************************************************************/
/* Syntax           : u8 HSSD_u8DisplayNumber(u8 Copy_u8Type , u8 Copy_u8Number , u8 Copy_u8Port , u8 Copy_u8HalfPort)
 * Description      : Display Number on Seven sesgment which connected to full half port
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Type , Copy_u8Number , Copy_u8Port , Copy_u8HalfPort
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 HSSD_u8DisplayNumber(u8 Copy_u8Type , u8 Copy_u8Number , u8 Copy_u8Port , u8 Copy_u8HalfPort)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Initialize array of u8 with binary numbers for numbers from 0 to 9 */
	u8 SevenSegBinNumbers[SSD_SIZE_OF_ARRAY] = {SSD_ZERO,SSD_ONE,SSD_TWO,SSD_THREE,SSD_FOUR,SSD_FIVE,SSD_SIX,SSD_SEVEN,SSD_EIGHT,SSD_NINE};

	/* Check HalfPort */
	/* Halfport has pins from 0 to 7 */
	if(Copy_u8HalfPort == SSD_1ST_HALF_PORT)
	{
		/* Set Port from pin0 to pin7 with mode OUTPUT_SPEED_2MHZ_PP */
		MGPIO_u8SetLowPortDirection(Copy_u8Port , GPIO_PORT_OUTPUT_SPEED_2MHZ_PP);

		/* Check SSD Type */
		/* Seven segment is common cathode*/
		if(Copy_u8Type == SSD_CATHODE)
		{
			/* Check Equality of Number which it will display */
			switch(Copy_u8Number)
			{
			case SSD_NUMBER0:
				/* Set value SSD_ZERO on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER1:
				/* Set value SSD_ONE on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER2:
				/* Set value SSD_TWO on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER3:
				/* Set value SSD_THREE on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER4:
				/* Set value SSD_FOUR on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER5:
				/* Set value SSD_FIVE on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER6:
				/* Set value SSD_SIX on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER7:
				/* Set value SSD_SEVEN on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER8:
				/* Set value SSD_EIGHT on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER9:
				/* Set value SSD_NINE on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;
			default         : Local_u8ErrorState = NOK;       break;      /* Wrong Choice in Copy_u8Number */
			}
		}
		/* Seven segment is common anode*/
		else if(Copy_u8Type == SSD_ANODE)
		{
			/* Check Equality of Number which it will display */
			switch(Copy_u8Number)
			{
			case SSD_NUMBER0:
				/* Set value ~SSD_ZERO on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER1:
				/* Set value ~SSD_ONE on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;
			case SSD_NUMBER2:
				/* Set value ~SSD_TWO on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;
			case SSD_NUMBER3:
				/* Set value ~SSD_THREE on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;
			case SSD_NUMBER4:
				/* Set value ~SSD_FOUR on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;
			case SSD_NUMBER5:
				/* Set value ~SSD_FIVE on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;
			case SSD_NUMBER6:
				/* Set value ~SSD_SIX on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;
			case SSD_NUMBER7:
				/* Set value ~SSD_SEVEN on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;
			case SSD_NUMBER8:
				/* Set value ~SSD_EIGHT on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;
			case SSD_NUMBER9:
				/* Set value ~SSD_NINE on pin0 to pin7 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_1ST_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;
			default         : Local_u8ErrorState = NOK;       break;      /* Wrong in Copy_u8Number */
			}
		}
		else
		{
			Local_u8ErrorState = NOK;									  /* Wrong Choice in Copy_u8Type */
		}
	}
	/* Halfport has pins from 8 to 15 */
	else if(Copy_u8HalfPort == SSD_2ND_HALF_PORT)
	{
		/* Set Port from pin8 to pin15 with mode OUTPUT_SPEED_2MHZ_PP */
		MGPIO_u8SetHighPortDirection(Copy_u8Port , GPIO_PORT_OUTPUT_SPEED_2MHZ_PP);

		/* Seven segment is common cathode*/
		if(Copy_u8Type == SSD_CATHODE)
		{
			/* Check Equality of Number which it will display */
			switch(Copy_u8Number)
			{
			case SSD_NUMBER0:
				/* Set value SSD_ZERO on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER1:
				/* Set value SSD_ONE on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER2:
				/* Set value SSD_TWO on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER3:
				/* Set value SSD_THREE on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER4:
				/* Set value SSD_FOUR on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER5:
				/* Set value SSD_FIVE on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER6:
				/* Set value SSD_SIX on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER7:
				/* Set value SSD_SEVEN on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER8:
				/* Set value SSD_EIGHT on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER9:
				/* Set value SSD_NINE on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , SevenSegBinNumbers[Copy_u8Number]);
				break;

			default         : Local_u8ErrorState = NOK;       break;      /* Wrong in Copy_u8Number */
			}
		}
		else if(Copy_u8Type == SSD_ANODE)
		{
			switch(Copy_u8Number)
			{
			case SSD_NUMBER0:
				/* Set value ~SSD_ZERO on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER1:
				/* Set value ~SSD_ONE on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER2:
				/* Set value ~SSD_TWO on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER3:
				/* Set value SSD_THREE on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER4:
				/* Set value ~SSD_FOUR on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER5:
				/* Set value ~SSD_FIVE on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER6:
				/* Set value ~SSD_SIX on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER7:
				/* Set value ~SSD_SEVEN on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER8:
				/* Set value ~SSD_EIGHT on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;

			case SSD_NUMBER9:
				/* Set value ~SSD_NINE on pin8 to pin15 */
				MGPIO_u8SetHalfPortValue(Copy_u8Port , SSD_2ND_HALF_PORT , ~SevenSegBinNumbers[Copy_u8Number]);
				break;

			default         : Local_u8ErrorState = NOK;       break;      /* Wrong in Copy_u8Number */
			}
		}
		else
		{
			Local_u8ErrorState = NOK;									   /* Wrong Choice in Copy_u8Type */
		}
	}
	else
	{
		Local_u8ErrorState = NOK;								    	   /* Wrong Choice in Copy_u8HalfPort */
	}

	return Local_u8ErrorState;											   /* Return Error State              */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/********************************************************************************************/
/*   END OF FILE: SSD_program.c                                                             */
/********************************************************************************************/
