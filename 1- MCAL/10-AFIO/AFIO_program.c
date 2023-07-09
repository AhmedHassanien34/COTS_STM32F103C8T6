/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    9 march 2023	 		           		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 AFIO									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


/********************************************************************************************/
/* Include libraries                                                                        */
/********************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/********************************************************************************************/
/* Include Component Files                                                                  */
/********************************************************************************************/
#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"


/******************************************************************************/
/* Syntax           : u8 MAFIO_u8SetEXTIConfiguration(u8 Copy_u8Line ,u8 Copy_u8PortMap)
 * Description      : Set EXTI Configuration
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Line , Copy_u8PortMap
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MAFIO_u8SetEXTIConfiguration(u8 Copy_u8Line ,u8 Copy_u8PortMap)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Initialize local variable to carry indx of EXTICR Register */
	u8 Local_u8RegIndex = 0 ;

	if(Copy_u8Line <= AFIO_LAST_4_BITS_IN_EXTICR0)								/* Check over first 4 lines  			    */
	{
			Local_u8RegIndex = AFIO_EXTICR0;									/* EXTICR[x] is EXTICR0                     */
	}
	else if(Copy_u8Line <= AFIO_LAST_4_BITS_IN_EXTICR1)							/* Check over first 4 lines  			    */
	{	
		Local_u8RegIndex = AFIO_EXTICR1;										/* EXTICR[x] is EXTICR1                     */
		Copy_u8Line -= 4;														/* Subtract Copy_u8Line from 4 for mapping  */
	}
	else if(Copy_u8Line <= AFIO_LAST_4_BITS_IN_EXTICR2)							/* Check over third 4 lines                 */
	{
		Local_u8RegIndex = AFIO_EXTICR2;										/* EXTICR[x] is EXTICR2                     */
		Copy_u8Line -= 8;														/* Subtract Copy_u8Line from 8 for mapping  */
	
	}
	else if(Copy_u8Line <= AFIO_LAST_4_BITS_IN_EXTICR3)							/* Check over fourth 4 lines                */
	{
		Local_u8RegIndex = AFIO_EXTICR3;										/* EXTICR[x] is EXTICR3	                    */
		Copy_u8Line -= 12;														/* Subtract Copy_u8Line from 12 for mapping */
	}
	else
	{
		Local_u8ErrorState = NOK;												/* Wrong Choice In Copy_u8Line or Copy_u8PortMap*/
		return Local_u8ErrorState;
	}

	AFIO->EXTICR[Local_u8RegIndex]  &= ~((0b1111) << (Copy_u8Line * 4))       ; /* Removing old values */
	AFIO->EXTICR[Local_u8RegIndex]  |= ((Copy_u8PortMap) << (Copy_u8Line * 4));	/* Set PortMap Value   */

	return Local_u8ErrorState;													/* Return Error State  */
}
