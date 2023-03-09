/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    5 march 2023	 		           		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 NVIC									*************/
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
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


/******************************************************************************/
/* Syntax           : u8 MNVIC_u8EnableInterrupt(u8 Copy_u8IntNumber)
 * Description      : Enable External Interrupts
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8IntNumber
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MNVIC_u8EnableInterrupt(u8 Copy_u8IntNumber)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* If the user wants to enable interrupt in ISER0 register */
	if(Copy_u8IntNumber <= NVIC_INTERRUPT_INDX_31)
	{
		/* Enable Interrupt */
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}

	/* If the user wants to enable interrupt in ISER1 register */
	else if(Copy_u8IntNumber <= NVIC_INTERRUPT_INDX_59)
	{
		/* Subtract interrupt indx from 32 for mapping */
		Copy_u8IntNumber -= 32;

		/* Enable Interrupt */
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState = NOK;		/* Wrong Choice In Copy_IntNumber */
	}

	return Local_u8ErrorState;							/* Return Error State         */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : u8 MNVIC_u8DisableInterrupt(u8 Copy_u8IntNumber)
 * Description      : Disable External Interrupts
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8IntNumber
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MNVIC_u8DisableInterrupt(u8 Copy_u8IntNumber)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* If the user wants to disable interrupt in ISER0 register */
	if(Copy_u8IntNumber <= NVIC_INTERRUPT_INDX_31)
	{
		/* Disable Interrupt */
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}

	/* If the user wants to disable interrupt in ISER1 register */
	else if(Copy_u8IntNumber <= NVIC_INTERRUPT_INDX_59)
	{
		/* Subtract interrupt indx from 32 for mapping */
		Copy_u8IntNumber -= 32;

		/* Disable Interrupt */
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState = NOK;		/* Wrong Choice In Copy_IntNumber */
	}

	return Local_u8ErrorState;							/* Return Error State         */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : u8 MNVIC_u8DisableInterrupt(u8 Copy_u8IntNumber)
 * Description      : Set Pending Flag
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8IntNumber
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MNVIC_u8SetPendingFlag(u8 Copy_u8IntNumber)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* If the user wants to Set pending flag in ISPR0 register */
	if(Copy_u8IntNumber <= NVIC_INTERRUPT_INDX_31)
	{
		/* Set Pending Flag */
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}

	/* If the user wants to Set pending flag in ISPR1 register */
	else if(Copy_u8IntNumber <= NVIC_INTERRUPT_INDX_59)
	{
		/* Subtract interrupt indx from 32 for mapping */
		Copy_u8IntNumber -= 32;

		/* Set Pending Flag */
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState = NOK;		/* Wrong Choice In Copy_IntNumber */
	}

	return Local_u8ErrorState;							/* Return Error State         */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : u8 MNVIC_u8ClearPendingFlag(u8 Copy_u8IntNumber)
 * Description      : Clear Pending Flag
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8IntNumber
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MNVIC_u8ClearPendingFlag(u8 Copy_u8IntNumber)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* If the user wants to clear pending flag in ICPR0 register */
	if(Copy_u8IntNumber <= NVIC_INTERRUPT_INDX_31)
	{
		/* Clear Pending Flag */
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}

	/* If the user wants to clear pending flag in ICPR1 register */
	else if(Copy_u8IntNumber <= NVIC_INTERRUPT_INDX_59)
	{
		/* Subtract interrupt indx from 32 for mapping */
		Copy_u8IntNumber -= 32;

		/* Clear Pending Flag */
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState = NOK;		/* Wrong Choice In Copy_IntNumber */
	}

	return Local_u8ErrorState;							/* Return Error State         */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : u8 MNVIC_u8GetActiveFlag(u8 Copy_IntNumber , u8* Copy_pu8Result)
 * Description      : Get Active Flag
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8IntNumber , Copy_pu8Result
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber , u8* Copy_pu8Result)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* If the user wants to Get Active Flag in IABR0 register */
	if(Copy_u8IntNumber <= NVIC_INTERRUPT_INDX_31)
	{
		/* Get Active Flag */
		*Copy_pu8Result = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber);
	}

	/* If the user wants to Get Active Flag in IABR1 register */
	else if(Copy_u8IntNumber <= NVIC_INTERRUPT_INDX_59)
	{
		/* Subtract interrupt indx from 32 for mapping */
		Copy_u8IntNumber -= 32;

		/* Get Active Flag */
		*Copy_pu8Result = GET_BIT(NVIC_IABR1 , Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState = NOK;		/* Wrong Choice In Copy_IntNumber */
	}

	return Local_u8ErrorState;							/* Return Error State         */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void MNVIC_voidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u32Mode)
 * Description      : Set Priority
 * Sync\Async       : Synchronous
 * Parameters       : Copy_s8IntID , Copy_u8GroupPriority , Copy_u8SubPriority , Copy_u32Mode
 * Return value:    : void
 *******************************************************************************/
void MNVIC_voidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u32Mode)
{
	/* Initialize local variable with groub and sub groub value(4 bits) */
	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << (Copy_u32Mode - 0x05FA0300) / 256);

	/* External Peripheral has priority >= 0 */
	if(Copy_s8IntID >= 0)
	{
		/* Set interrupt priority with 4 bits value (groub and sub groub) and shifted left by 4 For MSB (LSB is Reserved)*/
		NVIC_IPR[Copy_s8IntID] = Local_u8Priority << 4;
	}
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/********************************************************************************************/
/*   END OF FILE: NVIC_program.c                                                            */
/********************************************************************************************/
