/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    13 February 2023	            		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 STK									*************/
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
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


/******************************************************************************/
/* Syntax          : void MSTK_voidInit(void)
* Description      : Initialize Clock source of STK
* Sync\Async       : Synchronous
* Parameters       : void
* Return value:    : void
*******************************************************************************/
void MSTK_voidInit(void)
{
#if   Clock_Source == STK_AHB_DIV_BY_8
	STK_CTRL = 0x00000000;									/* Select AHB DIV BY 8 as clock source for STK */
#elif Clock_Source == STK_PROCESSOR_CLOCK_AHB
	STK_CTRL = 0x00000004;									/* Select AHB 8 as clock source for STK        */
#else
#error "Wrong Clock_Source_STK Choice"						/* Wrong Clock Source STK Choice 			   */

#endif
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax          : void MSTK_voidSetBusyWaitInMilliSec(u16 Copy_u16Time)
* Description      : Set Busy Wait in Milli Sec
* Sync\Async       : Synchronous
* Parameters       : Copy_u16Time
* Return value:    : void
*******************************************************************************/
void MSTK_voidSetBusyWaitInMilliSec(u16 Copy_u16Time)
{
	/* Store In LOAD Reg number of ticks (in ms) */
	STK_LOAD = Copy_u16Time * 1000;

	/* Enable STK */
	SET_BIT(STK_CTRL , STK_ENABLE);

	/* Waiting until STK finsih count */
	while(GET_BIT(STK_CTRL , STK_COUNTFLAG) == 0 );

	/* Stop Timer */
	SET_BIT(STK_CTRL , STK_ENABLE);
	STK_LOAD = NULL;
	STK_VAL = NULL;
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax          : u8 MSTK_u8SetIntervalSingleInMilliSec(u16 Copy_u16Time , void (*Copy_ptr) (void))
* Description      : Set Interval Single in Milli Sec
* Sync\Async       : Asynchronous
* Parameters       : Copy_u16Time , void (*Copy_ptr) (void)
* Return value:    : Local_u8ErrorState
*******************************************************************************/
u8 MSTK_u8SetIntervalSingleInMilliSec(u16 Copy_u16Time , void (*Copy_ptr) (void))
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Mode of interval is single */
	MSTK_u8ModeOfInterval = STK_SINGLE_INTERVAL;

	/* Assign CallBack pointer with pointer to function that pointe to Application function */
	CallBack = Copy_ptr;

	/* Check if callBack or Copy_ptr pointer pointe to NULL or not */
	if(CallBack != NULL)
	{
		/* Store In LOAD Reg number of ticks (in ms) */
		STK_LOAD = Copy_u16Time * 1000;

		/* Enable STK Interrupt */
		SET_BIT(STK_CTRL , STK_TICKINT);

		/* Enable STK */
		SET_BIT(STK_CTRL , STK_ENABLE);
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
/* Syntax          : u8 MSTK_u8SetIntervalPeriodicInMilliSec(u16 Copy_u16Time , void (*Copy_ptr) (void))
* Description      : Set Interval Periodic in Milli Sec
* Sync\Async       : Asynchronous
* Parameters       : Copy_u16Time , void (*Copy_ptr) (void)
* Return value:    : Local_u8ErrorState
*******************************************************************************/
u8 MSTK_u8SetIntervalPeriodicInMilliSec(u16 Copy_u16Time , void (*Copy_ptr) (void))
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Mode of interval is Periodic */
	MSTK_u8ModeOfInterval = STK_PERIODIC_INTERVAL;

	/* Assign CallBack pointer with pointer to function that pointe to Application function */
	CallBack = Copy_ptr;

	/* Check if callBack or Copy_ptr pointer pointe to NULL or not */
	if(CallBack != NULL)
	{
		/* Store In LOAD Reg number of ticks (in ms) */
		STK_LOAD = Copy_u16Time * 1000;

		/* Enable STK Interrupt */
		SET_BIT(STK_CTRL , STK_TICKINT);

		/* Enable STK */
		SET_BIT(STK_CTRL , STK_ENABLE);
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
/* Syntax          : void MSTK_voidSetBusyWaitInMicroSec(u32 Copy_u32Time)
* Description      : Set Busy Wait in Micro Sec
* Sync\Async       : Synchronous
* Parameters       : Copy_u32Time
* Return value:    : void
*******************************************************************************/
void MSTK_voidSetBusyWaitInMicroSec(u32 Copy_u32Time)
{
	/* Store In LOAD Reg number of ticks (in Ms) */
	STK_LOAD = Copy_u32Time;
	
	/* Enable STK */
	SET_BIT(STK_CTRL , STK_ENABLE);
	
	/* Waiting until STK finsih count */
	while(GET_BIT(STK_CTRL , STK_COUNTFLAG) == 0 );
	
	/* Stop Timer */
	SET_BIT(STK_CTRL , STK_ENABLE);
	STK_LOAD = NULL;
	STK_VAL = NULL;
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax          : u8 MSTK_u8SetIntervalSingleInMicroSec(u32 Copy_u32Time , void (*Copy_ptr) (void))
* Description      : Set Interval Single in Micro Sec
* Sync\Async       : Asynchronous
* Parameters       : Copy_u32Time , void (*Copy_ptr) (void)
* Return value:    : Local_u8ErrorState
*******************************************************************************/
u8 MSTK_u8SetIntervalSingleInMicroSec(u32 Copy_u32Time , void (*Copy_ptr) (void))
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;
	
	/* Mode of interval is single */
	MSTK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
	
	/* Assign CallBack pointer with pointer to function that pointe to Application function */
	CallBack = Copy_ptr;
	
	/* Check if callBack or Copy_ptr pointer pointe to NULL or not */
	if(CallBack != NULL)
	{
		/* Store In LOAD Reg number of ticks (in Ms) */
		STK_LOAD = Copy_u32Time;
		
		/* Enable STK Interrupt */
		SET_BIT(STK_CTRL , STK_TICKINT);
		
		/* Enable STK */
		SET_BIT(STK_CTRL , STK_ENABLE);
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
/* Syntax          : u8 MSTK_u8SetIntervalPeriodicInMicroSec(u32 Copy_u32Time , void (*Copy_ptr) (void))
* Description      : Set Interval Periodic in Micro Sec
* Sync\Async       : Asynchronous
* Parameters       : Copy_u32Time , void (*Copy_ptr) (void)
* Return value:    : Local_u8ErrorState
*******************************************************************************/
u8 MSTK_u8SetIntervalPeriodicInMicroSec(u32 Copy_u32Time , void (*Copy_ptr) (void))
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;
	
	/* Mode of interval is Periodic */
	MSTK_u8ModeOfInterval = STK_PERIODIC_INTERVAL;
	
	/* Assign CallBack pointer with pointer to function that pointe to Application function */
	CallBack = Copy_ptr;
	
	/* Check if callBack or Copy_ptr pointer pointe to NULL or not */
	if(CallBack != NULL)
	{
		/* Store In LOAD Reg number of ticks (in Ms) */
		STK_LOAD = Copy_u32Time;
		
		/* Enable STK Interrupt */
		SET_BIT(STK_CTRL , STK_TICKINT);
		
		/* Enable STK */
		SET_BIT(STK_CTRL , STK_ENABLE);
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
/* Syntax          : void MSTK_voidStopInterval(void)
* Description      : Stop Interval
* Sync\Async       : Synchronous
* Parameters       : void
* Return value:    : void
*******************************************************************************/
void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK_CTRL , STK_TICKINT);
	
	/* Stop Timer */
	SET_BIT(STK_CTRL , STK_ENABLE);
	STK_LOAD = NULL;
	STK_VAL = NULL;
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax          : u32 MSTK_u32GetElapsedTimeInMilliSec(void)
* Description      : Get Elapse Time in milli sec
* Sync\Async       : Synchronous
* Parameters       : void
* Return value:    : Local_u32ElapseTicks / 1000
*******************************************************************************/
u32 MSTK_u32GetElapsedTimeInMilliSec(void)
{
	/* Intialize Elapse Ticks with 0 */
	u32 Local_u32ElapseTicks = 0;
	
	/* Get Elapse Ticks = LOAD REG - VALUE REG */
	Local_u32ElapseTicks = STK_LOAD - STK_VAL;
	
	/* return Elapse Time (in ms) */
	return (Local_u32ElapseTicks / 1000);
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax          : u32 MSTK_u32GetRemainingTimeInMilliSec(void)
* Description      : Get Remaining Time in milli sec
* Sync\Async       : Synchronous
* Parameters       : void
* Return value:    : STK_VAL / 1000
*******************************************************************************/
u32 MSTK_u32GetRemainingTimeInMilliSec(void)
{
	/* return Remaining Time (in ms) */
	return (STK_VAL / 1000);
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax          : u32 MSTK_u32GetElapsedTimeInMicroSec(void)
* Description      : Get Elapse Time in micro sec
* Sync\Async       : Synchronous
* Parameters       : void
* Return value:    : Local_u32ElapseTicks
*******************************************************************************/
u32 MSTK_u32GetElapsedTimeInMicroSec(void)
{
	/* Intialize Elapse Ticks with 0 */
	u32 Local_u32ElapseTicks = 0;

	/* Get Elapse Ticks = LOAD REG - VALUE REG */
	Local_u32ElapseTicks = STK_LOAD - STK_VAL;

	/* return Elapse Time (in Ms) */
	return Local_u32ElapseTicks;
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax          : u32 MSTK_u32GetRemainingTimeInMicroSec(void)
* Description      : Get Remaining Time in micro sec
* Sync\Async       : Synchronous
* Parameters       : void
* Return value:    : STK_VAL
*******************************************************************************/
u32 MSTK_u32GetRemainingTimeInMicroSec(void)
{
	/* return Remaining Time (in Ms) */
	return STK_VAL;
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax          : u8 MSTK_u8SetIntervalSingleInMicroSecWithTimerReset(u32 Copy_u32Time , void (*Copy_ptr) (void))
* Description      : Set Interval Single in Micro Sec with reset timer
* Sync\Async       : Asynchronous
* Parameters       : Copy_u32Time , void (*Copy_ptr) (void)
* Return value:    : Local_u8ErrorState
*******************************************************************************/
u8 MSTK_u8SetIntervalSingleInMicroSecWithResetTimer(u32 Copy_u32Time , void (*Copy_ptr) (void))
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Disable STK */
	CLR_BIT(STK_CTRL , STK_ENABLE);

	/* Clear Value Reg */
	STK_VAL = NULL;

	/* Mode of interval is single */
	MSTK_u8ModeOfInterval = STK_SINGLE_INTERVAL;

	/* Assign CallBack pointer with pointer to function that pointe to Application function */
	CallBack = Copy_ptr;

	/* Check if callBack or Copy_ptr pointer pointe to NULL or not */
	if(CallBack != NULL)
	{
		/* Store In LOAD Reg number of ticks (in Ms) */
		STK_LOAD = Copy_u32Time;

		/* Enable STK Interrupt */
		SET_BIT(STK_CTRL , STK_TICKINT);

		/* Enable STK */
		SET_BIT(STK_CTRL , STK_ENABLE);
	}
	else
	{
		Local_u8ErrorState = NOK; 						/* Wild Pointer				  */
	}

	return Local_u8ErrorState;							/* Return Error State         */
}

/******************************************************************************/
/* Syntax          : void SysTick_Handler(void)
* Description      : STK ISR
* Sync\Async       : Synchronous
* Parameters       : void
* Return value:    : void
*******************************************************************************/
void SysTick_Handler(void)
{
	/* Initialize local variable to read COUNTFLAG */
	u8 Local_u8ReadFlag;
	
	/* Check of Mode Of Interval*/
	if(MSTK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK_CTRL , STK_TICKINT);
		
		/* Stop Timer */
		SET_BIT(STK_CTRL , STK_ENABLE);
		STK_LOAD = NULL;
		STK_VAL = NULL;
	}
	
	/* Call application function through CallBack pointer */
	CallBack();
	
	/* Clear COUNTFLAG */
	Local_u8ReadFlag = GET_BIT(STK_CTRL , STK_COUNTFLAG);
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/********************************************************************************************/
/*   END OF FILE: STK_program.c                                                             */
/********************************************************************************************/
