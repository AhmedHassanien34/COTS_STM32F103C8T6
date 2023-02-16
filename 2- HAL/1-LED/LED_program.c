/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    15 February 2023	            		*************/
/**************************		Layer:   HAL								   	*************/
/**************************		SWC:	 LED									*************/
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
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"



/******************************************************************************/
/* Syntax          : void HLED_voidTurnOn(u8 Copy_u8PORT , u8 Copy_u8PIN)
* Description      : Turn On LED
* Sync\Async       : Synchronous
* Parameters       : Copy_u8PORT , Copy_u8PIN
* Return value:    : void
*******************************************************************************/
void HLED_voidTurnOn(u8 Copy_u8PORT , u8 Copy_u8PIN)
{
	/*SET PORT, PIN && MODE*/
	MGPIO_u8SetPinDirection(Copy_u8PORT , Copy_u8PIN , GPIO_OUTPUT_SPEED_10MHZ_PP);

	/*SET PIN HIGH*/
	MGPIO_u8SetPinValue(Copy_u8PORT , Copy_u8PIN , GPIO_HIGH);
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax          : void HLED_voidTurnOff(u8 Copy_u8PORT , u8 Copy_u8PIN)
* Description      : Turn Off LED
* Sync\Async       : Synchronous
* Parameters       : Copy_u8PORT , Copy_u8PIN
* Return value:    : void
*******************************************************************************/
void HLED_voidTurnOff(u8 Copy_u8PORT , u8 Copy_u8PIN)
{
	/*SET PORT, PIN && MODE*/
	MGPIO_u8SetPinDirection(Copy_u8PORT , Copy_u8PIN , GPIO_OUTPUT_SPEED_10MHZ_PP);

	/*SET PIN LOW*/
	MGPIO_u8SetPinValue(Copy_u8PORT , Copy_u8PIN , GPIO_LOW);
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax          : void HLED_voidToggle(u8 Copy_u8PORT , u8 Copy_u8PIN, u16 Copy_u8Delay)
* Description      : Toggle LED
* Sync\Async       : Synchronous
* Parameters       : Copy_u8PORT , Copy_u8PIN , Copy_u8Delay
* Return value:    : void
*******************************************************************************/
void HLED_voidToggle(u8 Copy_u8PORT , u8 Copy_u8PIN, u16 Copy_u8Delay)
{
	/* Turn on Led */
	HLED_voidTurnOn(Copy_u8PORT , Copy_u8PIN);

	/* Wait for delay */
	MSTK_voidSetBusyWaitInMilliSec(Copy_u8Delay);

	/* Turn off led */
	HLED_voidTurnOff(Copy_u8PORT , Copy_u8PIN);

	/* Wait for delay */
	MSTK_voidSetBusyWaitInMilliSec(Copy_u8Delay);
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/********************************************************************************************/
/*   END OF FILE: LED_program.c                                                             */
/********************************************************************************************/
