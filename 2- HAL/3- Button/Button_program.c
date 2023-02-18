/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    17 February 2023	            		*************/
/**************************		Layer:   HAL								   	*************/
/**************************		SWC:	 Button									*************/
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
#include "Button_interface.h"
#include "Button_private.h"
#include "Button_config.h"



/******************************************************************************/
/* Syntax          : u8 HButton_u8CreateButton(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8ConcType)
* Description      : Initialize Button
* Sync\Async       : Synchronous
* Parameters       : Copy_u8Port , Copy_u8Pin , Copy_u8ConcType
* Return value:    : Local_u8ErrorState
*******************************************************************************/
u8 HButton_u8CreateButton(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8ConcType)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;
	
	/*SET PORT, PIN & MODE*/
	MGPIO_u8SetPinDirection(Copy_u8Port , Copy_u8Pin , GPIO_INPUT_PULL_UP_DOWN);
	
	/* Connection Type Check */
	if(Copy_u8ConcType == Button_PULLUP)
	{
		MGPIO_u8SetPinValue(Copy_u8Port ,  Copy_u8Pin , GPIO_HIGH);					/* Set Button as input PullUp      */
	}
	else if(Copy_u8ConcType == Button_PULLDOWN)
	{
		MGPIO_u8SetPinValue(Copy_u8Port ,  Copy_u8Pin , GPIO_LOW);					/* Set Button as input PullDown    */
	}
	else
	{
		Local_u8ErrorState = NOK;													/* Wrong Choice In Copy_u8ConcType */
	}
	return Local_u8ErrorState;														/* Return Error State         	   */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax          : u8 HButton_u8GetButtonState(u8 Copy_u8Port , u8 Copy_u8Pin)
* Description      : Turn Off LED
* Sync\Async       : Synchronous
* Parameters       : Copy_u8Port , Copy_u8Pin
* Return value:    : void
*******************************************************************************/
u8 HButton_u8GetButtonState(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	/* Inintialize Button State Variable */
	u8 Local_u8ButtonState = 0;
	
	/* Get Buttont State */
	MGPIO_u8GetPinValue(Copy_u8Port , Copy_u8Pin , &Local_u8ButtonState);
	
	/* Return Button State Value */
	return Local_u8ButtonState;
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/********************************************************************************************/
/*   END OF FILE: Button_program.c                                                          */
/********************************************************************************************/
