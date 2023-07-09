/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    3 APRIL 2023	 		           		*************/
/**************************		Layer:   HAL								   	*************/
/**************************		SWC:	 DAC									*************/
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
#include "RCC_interface.h"
/********************************************************************************************/
/* Include Component Files                                                                  */
/********************************************************************************************/
#include "DAC_interface.h"
#include "DAC_config.h"
#include "DAC_private.h"



/******************************************************************************/
/* Syntax           : void HDAC_voidInit(void)
 * Description      : Initialize Pins of DAC
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void HDAC_voidInit(void)
{
	MGPIO_u8SetPinDirection(DAC_PIN0 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_u8SetPinDirection(DAC_PIN1 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_u8SetPinDirection(DAC_PIN2 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_u8SetPinDirection(DAC_PIN3 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_u8SetPinDirection(DAC_PIN4 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_u8SetPinDirection(DAC_PIN5 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_u8SetPinDirection(DAC_PIN6 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_u8SetPinDirection(DAC_PIN7 , GPIO_OUTPUT_SPEED_2MHZ_PP);
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : HDAC_voidWriteData(u8 Copy_u8Data)
 * Description      : Write Data on Dac
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Data
 * Return value:    : void
 *******************************************************************************/
void HDAC_voidWriteData(u8 Copy_u8Data)
{
	MGPIO_u8SetPinValue(DAC_PIN0 , GET_BIT(Copy_u8Data , 0));
	MGPIO_u8SetPinValue(DAC_PIN1 , GET_BIT(Copy_u8Data , 1));
	MGPIO_u8SetPinValue(DAC_PIN2 , GET_BIT(Copy_u8Data , 2));
	MGPIO_u8SetPinValue(DAC_PIN3 , GET_BIT(Copy_u8Data , 3));
	MGPIO_u8SetPinValue(DAC_PIN4 , GET_BIT(Copy_u8Data , 4));
	MGPIO_u8SetPinValue(DAC_PIN5 , GET_BIT(Copy_u8Data , 5));
	MGPIO_u8SetPinValue(DAC_PIN6 , GET_BIT(Copy_u8Data , 6));
	MGPIO_u8SetPinValue(DAC_PIN7 , GET_BIT(Copy_u8Data , 7));
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/




/********************************************************************************************/
/*   END OF FILE: DAC_program.c                                                             */
/********************************************************************************************/
