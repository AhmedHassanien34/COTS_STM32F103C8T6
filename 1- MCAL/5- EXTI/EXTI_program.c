/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    9 march 2023	 		           		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 EXTI									*************/
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
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/******************************************************************************/
/* Syntax           : void MEXTI_voidInit(void)
 * Description      : Initialize Mode of EXTI and Disable Interrupts
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void MEXTI_voidInit(void)
{
	#if   EXTI_MODE == EXTI_RISING_EDGE
		SET_BIT( EXTI->RTSR , EXTI_LINE );					/* Set RISING EDGE Mode   */
	#elif EXTI_MODE == EXTI_FALING_EDGE
		SET_BIT( EXTI->FTSR , EXTI_LINE );					/* Set FALING EDGE Mode   */
	#elif EXTI_MODE == EXTI_ON_CHANGE
		SET_BIT( EXTI->RTSR , EXTI_LINE );					/* Set ON CHANGE Mode     */
		SET_BIT( EXTI->FTSR , EXTI_LINE );
	#else 
		#error "Wrong Mode or Line Choice"					/* Wrong Configuration    */
	#endif
	CLR_BIT(EXTI->IMR , EXTI_LINE);						    /* Disable all interrupts */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
 * Description      : Enable EXTI LINE
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Line
 * Return value:    : void
 *******************************************************************************/
void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
		SET_BIT(EXTI->IMR , Copy_u8Line);				/* Enable EXTI LINE       */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
 * Description      : Disable EXTI LINE
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Line
 * Return value:    : void
 *******************************************************************************/
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
		CLR_BIT(EXTI->IMR , Copy_u8Line);				/* Disable EXTI LINE */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void MEXTI_voidSwTrigger(u8 Copy_u8Line)
 * Description      : Set SW Trigger
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Line
 * Return value:    : void
 *******************************************************************************/
void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
		SET_BIT(EXTI->SWIER , Copy_u8Line);				/* Set SW Trigger         */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : u8 MEXTI_u8SetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode )
 * Description      : Set Mode of EXTI in run time
 * Sync\Async       : Synchronous
 * Parameters       : Copy_u8Line
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MEXTI_u8SetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode )
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	switch(Copy_u8Mode)
	{
		case EXTI_RISING_EDGE:   SET_BIT( EXTI->RTSR , Copy_u8Line ); break;	/* Set RISING EDGE Mode    */
		case EXTI_FALING_EDGE: 	 SET_BIT( EXTI->FTSR , Copy_u8Line ); break;	/* Set FALING EDGE Mode    */
		case EXTI_ON_CHANGE	 :   SET_BIT( EXTI->RTSR , Copy_u8Line );			/* Set ON CHANGE EDGE Mode */
		                         SET_BIT( EXTI->FTSR , Copy_u8Line ); break;
		default				 : 	 Local_u8ErrorState = NOK;						/* Wrong Choice In Copy_u8Line or Copy_u8Mode*/
	}
	return Local_u8ErrorState;							/* Return Error State */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : u8 MEXTI_u8SetCallBack(void (*Copy_ptr) (void) , u8 Copy_u8Line)
 * Description      : Set Call back
 * Sync\Async       : Synchronous
 * Parameters       : void (*Copy_ptr) (void) , Copy_u8Line
 * Return value:    : Local_u8ErrorState
 *******************************************************************************/
u8 MEXTI_u8SetCallBack(void (*Copy_ptr) (void) , u8 Copy_u8Line)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Check if callBack or Copy_ptr pointer pointe to NULL or not */
	if(Copy_ptr != NULL)
	{
		/* Assign CallBack pointer with pointer to function that pointe to Application function */
		EXTI_CallBack[Copy_u8Line] = Copy_ptr;
	}
	else
	{
		Local_u8ErrorState = NOK; 						/* Wild Pointer				  */
	}

	return Local_u8ErrorState;							/* Return Error State         */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI0_IRQHandler(void)
 * Description      : EXTI0 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI0_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE0]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE0);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI1_IRQHandler(void)
 * Description      : EXTI1 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI1_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE1]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE1);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI2_IRQHandler(void)
 * Description      : EXTI2 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI2_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE2]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE2);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI3_IRQHandler(void)
 * Description      : EXTI3 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI3_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE3]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE3);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI4_IRQHandler(void)
 * Description      : EXTI4 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI4_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE4]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE4);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI5_IRQHandler(void)
 * Description      : EXTI5 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI5_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE5]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE5);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI6_IRQHandler(void)
 * Description      : EXTI6 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI6_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE6]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE6);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI7_IRQHandler(void)
 * Description      : EXTI7 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI7_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE7]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE7);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI8_IRQHandler(void)
 * Description      : EXTI8 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI8_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE8]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE8);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI9_IRQHandler(void)
 * Description      : EXTI9 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI9_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE9]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE9);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI10_IRQHandler(void)
 * Description      : EXTI10 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI10_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE10]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE10);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI11_IRQHandler(void)
 * Description      : EXTI11 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI11_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE11]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE11);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI12_IRQHandler(void)
 * Description      : EXTI12 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI12_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE12]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE12);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI13_IRQHandler(void)
 * Description      : EXTI13 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI13_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE13]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE13);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI14_IRQHandler(void)
 * Description      : EXTI14 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI14_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE14]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE14);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax           : void EXTI15_IRQHandler(void)
 * Description      : EXTI15 ISR
 * Sync\Async       : Synchronous
 * Parameters       : void
 * Return value:    : void
 *******************************************************************************/
void EXTI15_IRQHandler(void)
{
	EXTI_CallBack[EXTI_LINE15]();      /* Call application function through CallBack pointer */
	SET_BIT(EXTI->PR , EXTI_LINE15);   /* Clear corresponding pending bit to Copy_u8Line in PR Reg */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/********************************************************************************************/
/*   END OF FILE: EXTI_program.c                                                            */
/********************************************************************************************/
