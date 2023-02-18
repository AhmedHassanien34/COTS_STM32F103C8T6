/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    3 February 2023	            		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 RCC									*************/
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
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


/******************************************************************************/
/* Syntax          : void MRCC_voidInitSysClock(void)
* Description      : Initialize System Clock
* Sync\Async       : Synchronous
* Parameters       : void
* Return value:    : void
*******************************************************************************/
void MRCC_voidInitSysClock(void)
{
	/* Configure Enable Clock source */
#if RCC_CLOCK_SOURCE == RCC_HSI									/* Enable HSI as Clock source                        */
	SET_BIT(RCC_CR ,RCC_HSI_ON);							    /* Set HSION bit in CR register                      */
	CLR_BIT(RCC_CR ,RCC_HSE_ON);							    /* Clear HSEON bit in CR register                    */
	CLR_BIT(RCC_CR ,RCC_PLL_ON);								/* Clear PLLON bit in CR register                    */

#elif RCC_CLOCK_SOURCE == RCC_HSE							    /* Enable HSE as Clock source                        */
	CLR_BIT(RCC_CR ,RCC_HSI_ON);								/* Clear HSION bit in CR register                    */
	SET_BIT(RCC_CR ,RCC_HSE_ON);								/* Set HSEON bit in CR register                      */
	CLR_BIT(RCC_CR ,RCC_PLL_ON);								/* Clear PLLON bit in CR register                    */

	/* Configure HSE type */
#if RCC_HSE_TYPE == RCC_RC										/* Select RC as External Clock                       */
	SET_BIT(RCC_CR , RCC_HSE_BYP);								/* Set HSE_BYP bit in CR register                    */

#elif RCC_HSE_TYPE == RCC_CRYSTAL								/* Select Crystal as External Clock                  */
	CLR_BIT(RCC_CR , RCC_HSE_BYP);								/* Set HSE_BYP bit in CR register                    */
#else
	#error("You Choose Wrong HSE type")                         /* Print Error for chosing wrong configration */
#endif

#elif RCC_CLOCK_SOURCE == RCC_PLL								/* Enable PLL as Clock source                        */
	/* Select PLL entry clock source */
#if RCC_PLL_ENTRY_CLOCK_SOURCE == RCC_HSI_DIV_BY_2              /* HSI oscillator clock / 2 selected as PLL input clock */
	CLR_BIT(RCC_CFGR , RCC_PLLSRC);								/* Clear RCC_PLLSRC bit in CFGR Register */

#elif RCC_PLL_ENTRY_CLOCK_SOURCE == RCC_HSE						/* HSE oscillator clock selected as PLL input clock */
	SET_BIT(RCC_CFGR , RCC_PLLSRC);                             /* Set RCC_PLLSRC bit in CFGR Register */

	/* Select HSE divider for PLL entry */
#if RCC_HSE_DIV_FOR_PLL_ENTRY == RCC_HSE_NOT_DIV                /* HSE clock not divided */
	CLR_BIT(RCC_CFGR , RCC_PLLXTPRE);						    /* Clear RCC_PLLXTPRE bit in CFGR Register */

#elif RCC_HSE_DIV_FOR_PLL_ENTRY == RCC_HSE_DIV_BY_2				/* HSE clock divided by 2 */
	SET_BIT(RCC_CFGR , RCC_PLLXTPRE);							/* Set RCC_PLLXTPRE bit in CFGR Register */
#else
	#error("You Choose Wrong HSE divider for PLL entry")        /* Print Error for chosing wrong configration        */
#endif
#else
	#error("You Choose Wrong PLL entry clock source")        /* Print Error for chosing wrong configration           */
#endif

	/* Configure PLL multiplication factor */
	/* Set LL multiplication factor before enable PLL */
	RCC_CFGR &= RCC_PLL_MUL_MASK;                               /* Clear only PLLMUL bits in CFGR register            */
	RCC_CFGR |= RCC_PLL_MUL_FACTOR;                             /* Set Choosing Mode in PLLMUL bits in CFGR register  */

    /* Enable PLL after setting configrations */
	CLR_BIT(RCC_CR ,RCC_HSI_ON);			                    /* Clear HSION bit in CR register                    */
	CLR_BIT(RCC_CR ,RCC_HSE_ON);                                /* Clear HSEON bit in CR register                    */
	SET_BIT(RCC_CR ,RCC_PLL_ON);                                /* Set PLLON bit in CR register                      */
#else
	#error("You Choose Wrong Enable Clock source type")         /* Print Error for chosing wrong configration        */
#endif

	/* Configure Clock security system */
#if CLOCK_SECURITY_SYSTEM == RCC_CSS_ENABLE                     /* Enable Clock security system                      */
	SET_BIT(RCC_CR , RCC_CSS_ON);                               /* Set CSS_ON bit in CR register                     */

#elif CLOCK_SECURITY_SYSTEM == RCC_CSS_DISABLE                  /* Disable Clock security system                     */
	CLR_BIT(RCC_CR , RCC_CSS_ON);                               /* Clear CSS_ON bit in CR register                   */
#else
	#error("You Choose Wrong Clock security system")            /* Print Error for chosing wrong configration        */
#endif

	/* Configure Internal high-speed clock trimming */
	RCC_CR &= RCC_HSITRIM_MASK;                                 /* Clear only HSITRIM bits in CR register            */
	RCC_CR |= RCC_HSI_CLOCK_TRIMMING;                           /* Set Choosing Mode in HSITRIM bits in CR register  */

	/* Select APB high-speed prescaler (APB2) */
	RCC_CFGR &= RCC_HCLK_APB2_PRESCALER_MASK;                   /* Clear only PPRE2 bits in CFGR register            */
    RCC_CFGR |= RCC_APB_HIGH_SPEED_PRESCALER;                   /* Set Choosing Mode in PPRE2 bits in CFGR register  */

	/* Select APB low-speed prescaler (APB1) */
	RCC_CFGR &= RCC_HCLK_APB1_PRESCALER_MASK;                   /* Clear only PPRE1 bits in CFGR register            */
    RCC_CFGR |= RCC_APB_LOW_SPEED_PRESCALER;                    /* Set Choosing Mode in PPRE1 bits in CFGR register  */

	/* Select AHB prescaler */
	RCC_CFGR &= RCC_AHB_PRESCALER_MASK;                   		/* Clear only HPRE bits in CFGR register             */
    RCC_CFGR |= RCC_AHP_PRESCALER;                  		    /* Set Choosing Mode in HPRE bits in CFGR register   */

	/* Selecte System Clock */
	RCC_CFGR &= RCC_SW_MASK;                                    /* Clear only SW bits in CFGR register               */
    RCC_CFGR |= RCC_SYSTEM_CLOCK;                               /* Set Choosing Mode in SW bits in CFGR register     */

}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax          : u8 MRCC_u8EnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
* Description      : Enable Clock of Peripherals
* Sync\Async       : Synchronous
* Parameters       : Copy_u8BusId , Copy_u8PerId
* Return value:    : Local_u8ErrorState
*******************************************************************************/
u8 MRCC_u8EnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Check Number Of PerId */
	if(Copy_u8PerId <= RCC_MAX_NUM_OF_PER_ID)
	{
		/* Check Equality Of BusId */
		switch(Copy_u8BusId)
		{
		case RCC_AHB  :  SET_BIT(RCC_AHBENR  ,Copy_u8PerId);    break;  	/* Set PerId Bit In AHBENR Register  */
		case RCC_APB1 :  SET_BIT(RCC_APB1ENR ,Copy_u8PerId);	break;		/* Set PerId Bit In APB1ENR Register */
		case RCC_APB2 :  SET_BIT(RCC_APB2ENR ,Copy_u8PerId);	break;		/* Set PerId Bit In APB2ENR Register */
		default       :	 Local_u8ErrorState = NOK; 							/* Wrong In BusId                    */
		}
	}
	else
	{
		Local_u8ErrorState = NOK; 											/* Wrong Choice In PerId     */
	}
	return Local_u8ErrorState;												/* Return Error State */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/******************************************************************************/
/* Syntax          : u8 MRCC_u8DisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
* Description      : Disable Clock of Peripherals
* Sync\Async       : Synchronous
* Parameters       : Copy_u8BusId , Copy_u8PerId
* Return value:    : Local_u8ErrorState
*******************************************************************************/
u8 MRCC_u8DisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	/* Initialize Error State Local Variable */
	u8 Local_u8ErrorState = OK;

	/* Check Number Of Pin */
	if(Copy_u8PerId <= RCC_MAX_NUM_OF_PER_ID)
	{
		/* Check Equality Of BusId */
		switch(Copy_u8BusId)
		{
		case RCC_AHB  :  CLR_BIT(RCC_AHBENR  ,Copy_u8PerId);  	break;      /* Clear PerId Bit In AHBENR Register  */
		case RCC_APB1 :  CLR_BIT(RCC_APB1ENR ,Copy_u8PerId);	break;      /* Clear PerId Bit In APB1ENR Register */
		case RCC_APB2 :  CLR_BIT(RCC_APB2ENR ,Copy_u8PerId);	break;      /* Clear PerId Bit In APB2ENR Register */
		default       :	 Local_u8ErrorState = NOK; 							/* Wrong In BusId                      */
		}
	}
	else
	{
		Local_u8ErrorState = NOK; 									    	/* Wrong Choice In PerId     */
	}
	return Local_u8ErrorState;												/* Return Error State */
}
/********************************************************************************************/
/*   END OF Function                                                                        */
/********************************************************************************************/



/********************************************************************************************/
/*   END OF FILE: RCC_program.c                                                             */
/********************************************************************************************/
