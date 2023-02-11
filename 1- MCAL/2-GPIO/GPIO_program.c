/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    11 February 2023	            		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 GPIO									*************/
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
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


/******************************************************************************/
/* Syntax           : u8 MGPIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
 * Description      : Set Pin Direction
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Port , Copy_u8Pin , Copy_u8Mode
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MGPIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Check Equality Of Port */
	switch(Copy_u8Port)
	{
	case GPIOA :
		/* pin is equal or lower than pin7 */
		if(Copy_u8Pin <= GPIO_PIN7)
		{
			/* Clear 4 Mode bits for this pin */
			GPIOA_CRL &= ~((0b1111) << (Copy_u8Pin * 4));

			/* Set 4 Mode bits for this pin */
			GPIOA_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}

		/* pin is equal or lower than pin15 and higher pin7 */
		else if(Copy_u8Pin <= GPIO_PIN15)
		{
			/* Mapping number of pin with number of bit */
			Copy_u8Pin -= 8;

			/* Clear 4 Mode bits for this pin */
			GPIOA_CRH &= ~((0b1111) << (Copy_u8Pin * 4));

			/* Set 4 Mode bits for this pin */
			GPIOA_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else
		{
			Local_u8ErrorState = NOK;		/* Wrong Choice In Copy_u8Pin */
		}
		break;

	case GPIOB :
		/* pin is equal or lower than pin7 */
		if(Copy_u8Pin <= GPIO_PIN7)
		{
			/* Clear 4 Mode bits for this pin */
			GPIOB_CRL &= ~((0b1111) << (Copy_u8Pin * 4));

			/* Set 4 Mode bits for this pin */
			GPIOB_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}

		/* pin is equal or lower than pin15 and higher pin7 */
		else if(Copy_u8Pin <= GPIO_PIN15)
		{
			/* Mapping number of pin with number of bit */
			Copy_u8Pin -= 8;

			/* Clear 4 Mode bits for this pin */
			GPIOB_CRH &= ~((0b1111) << (Copy_u8Pin * 4));

			/* Set 4 Mode bits for this pin */
			GPIOB_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else
		{
			Local_u8ErrorState = NOK;		/* Wrong Choice In Copy_u8Pin */
		}
		break;
	case GPIOC :
		/* pin is equal or lower than pin7 */
		if(Copy_u8Pin <= GPIO_PIN7)
		{
			/* Clear 4 Mode bits for this pin */
			GPIOC_CRL &= ~((0b1111) << (Copy_u8Pin * 4));

			/* Set 4 Mode bits for this pin */
			GPIOC_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}

		/* pin is equal or lower than pin15 and higher pin7 */
		else if(Copy_u8Pin <= GPIO_PIN15)
		{
			/* Mapping number of pin with number of bit */
			Copy_u8Pin -= 8;

			/* Clear 4 Mode bits for this pin */
			GPIOC_CRH &= ~((0b1111) << (Copy_u8Pin * 4));

			/* Set 4 Mode bits for this pin */
			GPIOC_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else
		{
			Local_u8ErrorState = NOK;		            /* Wrong Choice In Copy_u8Pin */
		}
		break;

	default :   Local_u8ErrorState = NOK; break;        /* Wrong Choice In Copy_u8Pin */
	}

	return Local_u8ErrorState;							/* Return Error State         */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : u8 MGPIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
 * Description      : Set Pin Value
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Port , Copy_u8Pin , Copy_u8Value
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MGPIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Check Equality Of Port */
	switch(Copy_u8Port)
	{
	case GPIOA :
		/* Pin value is High */
		if(Copy_u8Value == GPIO_HIGH)
		{
			/* Set number of pin in BSRR Register */
			GPIOA_BSRR = (1 <<  Copy_u8Pin);
		}

		/* Pin value is Low */
		else if(Copy_u8Value == GPIO_LOW)
		{
			/* Clear number of pin in BRR Register */
			GPIOA_BRR =	(1 <<  (Copy_u8Pin));
		}
		else
		{
			Local_u8ErrorState = NOK;		/* Wrong Choice In Copy_u8Value */
		}
		break;

	case GPIOB :
		/* Pin value is High */
		if(Copy_u8Value == GPIO_HIGH)
		{
			/* Set number of pin in BSRR Register */
			GPIOB_BSRR = (1 <<  Copy_u8Pin);
		}
		/* Pin value is Low */
		else if(Copy_u8Value == GPIO_LOW)
		{
			/* Clear number of pin in BRR Register */
			GPIOB_BRR =	(1 <<  (Copy_u8Pin));
		}
		else
		{
			Local_u8ErrorState = NOK;		/* Wrong Choice In Copy_u8Value */
		}
		break;

	case GPIOC :
		/* Pin value is High */
		if(Copy_u8Value == GPIO_HIGH)
		{
			/* Set number of pin in BSRR Register */
			GPIOC_BSRR = (1 <<  Copy_u8Pin);
		}
		/* Pin value is Low */
		else if(Copy_u8Value == GPIO_LOW)
		{
			/* Clear number of pin in BRR Register */
			GPIOC_BRR =	(1 <<  (Copy_u8Pin));
		}
		else
		{
			Local_u8ErrorState = NOK;		            /* Wrong Choice In Copy_u8Value */
		}
		break;

	default :  Local_u8ErrorState = NOK; break;		    /* Wrong Choice In Copy_u8Port */
	}
	return Local_u8ErrorState;							/* Return Error State          */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_pu8Value)
 * Description      : Get Pin Value
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Port , Copy_u8Pin , Copy_pu8Value
 * Return value:    : Local_u8ErrorState , Copy_pu8Value
 *******************************************************************************/
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_pu8Value)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Copy_pu8Value != NULL and pin <= 15 */
	if((Copy_pu8Value != NULL) && (Copy_u8Pin <= GPIO_PIN15))
	{
		/* Check Equality Of Port */
		switch(Copy_u8Port)
		{
		case GPIOA :	*Copy_pu8Value = GET_BIT(GPIOA_IDR , Copy_u8Pin);		/* Store bit value in Copy_pu8Value */
		break;
		case GPIOB :	*Copy_pu8Value = GET_BIT(GPIOB_IDR , Copy_u8Pin);		/* Store bit value in Copy_pu8Value */
		break;
		case GPIOC :	*Copy_pu8Value = GET_BIT(GPIOC_IDR , Copy_u8Pin);		/* Store bit value in Copy_pu8Value */
		break;
		default    :    Local_u8ErrorState = NOK;   break;						/* Wrong Choice In Copy_u8Port */
		}
	}
	else
	{
		Local_u8ErrorState = NOK;													/* Copy_pu8Value = NULL and pin > 15 */
	}

	return Local_u8ErrorState;														/* Return Error State          */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/




/******************************************************************************/
/* Syntax           : u8 MGPIO_u8SetLowPortDirection(u8 Copy_u8Port , u32 Copy_u32HalfPortMode)
 * Description      : Set pins Derction from pin0 to pin7
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Port , Copy_u32HalfPortMode
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MGPIO_u8SetLowPortDirection(u8 Copy_u8Port , u32 Copy_u32HalfPortMode)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Check Equality Of Port */
	switch(Copy_u8Port)
	{
	case GPIOA	:	GPIOA_CRL = Copy_u32HalfPortMode;	break;     /* Set pins Mode in GPIOA from pin0 to pin7 */
	case GPIOB	:	GPIOB_CRL = Copy_u32HalfPortMode;	break;	   /* Set pins Mode in GPIOB from pin0 to pin7 */
	default   	: 	Local_u8ErrorState = NOK;	break;	   		   /* Wrong Choice In Copy_u8Port              */
	}
	return Local_u8ErrorState;							           /* Return Error State                       */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : u8 MGPIO_u8SetHighPortDirection(u8 Copy_u8Port , u32 Copy_u32HalfPortMode)
 * Description      : Set pins Derction from pin8 to pin15
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Port , Copy_u32HalfPortMode
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MGPIO_u8SetHighPortDirection(u8 Copy_u8Port , u32 Copy_u32HalfPortMode)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Check Equality Of Port */
	switch(Copy_u8Port)
	{
	case GPIOA	:	GPIOA_CRH = Copy_u32HalfPortMode;	break;     /* Set pins Mode in GPIOA from pin8 to pin15 */
	case GPIOB	:	GPIOB_CRH = Copy_u32HalfPortMode;	break;	   /* Set pins Mode in GPIOB from pin8 to pin15 */
	default   	: 	Local_u8ErrorState = NOK;	break;	   		   /* Wrong Choice In Copy_u8Port               */
	}
	return Local_u8ErrorState;							 		   /* Return Error State                        */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : u8 MGPIO_u8SetHalfPortValue(u8 Copy_u8Port , u8 Copy_u8HalfPort , u8 Copy_u8Value)
 * Description      : Set half Port value from pin0 to pin7 or from pin8 to pin15
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Port , Copy_u8HalfPort , Copy_u8Value
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MGPIO_u8SetHalfPortValue(u8 Copy_u8Port , u8 Copy_u8HalfPort , u8 Copy_u8Value)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* port is PORTA */
	if(Copy_u8Port == GPIOA)
	{
		/* Check Equality Of HalfPort */
		switch(Copy_u8HalfPort)
		{
		/* HalfPort is First HalfPort  */
		case GPIO_1ST_HALF_PORT:
			GPIOA_ODR &= GPIO_1ST_HALF_PORT_MASK;			/* Clear bits from A0 to A7          */
			GPIOA_ODR |= Copy_u8Value;						/* Set HalfPort value from A0 to A7  */
			break;

		/* HalfPort is Second HalfPort  */
		case GPIO_2ND_HALF_PORT:
			GPIOA_ODR &= GPIO_2ND_HALF_PORT_MASK;			/* Clear bits from A8 to A15         */
			GPIOA_ODR |= Copy_u8Value << 8;					/* Set HalfPort value from A8 to A15 */
			break;

		default	:  Local_u8ErrorState = NOK;   break;		/* Wrong Choice In Copy_u8HalfPort   */
		}
	}

	/* port is PORTB */
	else if(Copy_u8Port == GPIOB)
	{
		/* Check Equality Of HalfPort */
		switch(Copy_u8HalfPort)
		{
		/* HalfPort is First HalfPort  */
		case GPIO_1ST_HALF_PORT:
			GPIOB_ODR &= GPIO_1ST_HALF_PORT_MASK;			/* Clear bits from B0 to B7          */
			GPIOB_ODR |= Copy_u8Value;						/* Set HalfPort value from B0 to B7  */
			break;

		/* HalfPort is Second HalfPort  */
		case GPIO_2ND_HALF_PORT:
			GPIOB_ODR &= GPIO_2ND_HALF_PORT_MASK;			/* Clear bits from B8 to B15          */
			GPIOB_ODR |= Copy_u8Value << 8;					/* Set HalfPort value from B8 to B15  */
			break;

		default	:  Local_u8ErrorState = NOK;   break;		/* Wrong Choice In Copy_u8HalfPort    */
		}
	}
	else
	{
		Local_u8ErrorState = NOK;							/* Wrong Choice In Copy_u8Port        */
	}
	return Local_u8ErrorState;							   /* Return Error State                  */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void MGPIO_voidSetPortDirection(u8 Copy_u8Port , u32 Copy_u32HalfPortMode)
 * Description      : Set PORT Direction
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Port , Copy_u32HalfPortMode
 * Return value:    : void
 *******************************************************************************/
void MGPIO_voidSetPortDirection(u8 Copy_u8Port , u32 Copy_u32HalfPortMode)
{
	/* Set Low port direction from pin0 to pin7 */
	MGPIO_u8SetLowPortDirection(Copy_u8Port , Copy_u32HalfPortMode);

	/* Set High port direction from pin8 to pin15 */
	MGPIO_u8SetHighPortDirection(Copy_u8Port , Copy_u32HalfPortMode);
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : u8 MGPIO_u8SetPortValue(u8 Copy_u8Port , u16 Copy_u16Value)
 * Description      : Set Port value from pin0 to pin15
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Port , Copy_u16Value
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MGPIO_u8SetPortValue(u8 Copy_u8Port , u16 Copy_u16Value)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Check Equality Of Port */
	switch(Copy_u8Port)
	{
	case GPIOA	:	GPIOA_ODR = Copy_u16Value;	break;     /* Set pins value in GPIOA from pin0 to pin15 */
	case GPIOB	:	GPIOB_ODR = Copy_u16Value;	break;	   /* Set pins value in GPIOB from pin0 to pin15 */
	default   	: 	Local_u8ErrorState = NOK;	break;	   /* Wrong Choice In Copy_u8Port                */
	}
	return Local_u8ErrorState;							   /* Return Error State                         */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/********************************************************************************************/
/*   END OF FILE: GPIO_program.c                                                            */
/********************************************************************************************/
