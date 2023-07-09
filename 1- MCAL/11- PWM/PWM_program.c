/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    15 march 2023	 		           		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 PWM									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "PWM_private.h"
#include "PWM_config.h"
#include "PWM_interface.h"

void PWM_VidInit(void)
{
	//OCxREF + Polarity OCx=OCxREF xor CCxP,OCx_EN=1
	//SET_BIT(TIM1->BDTR,15);
	//SET_BIT(TIM1->BDTR,11);
	SET_BIT(TIM4->CCER,0);
	CLR_BIT(TIM4->CCER,2);
	//ARPE: Auto-reload preload enable -- >1: TIMx_ARR register is buffered
	SET_BIT(TIM4->CR1,7);
	//OC1M: Output Compare 1 mode -- > 110: PWM mode 1
	SET_BIT(TIM4->CCMR1,6);
	SET_BIT(TIM4->CCMR1,5);
	CLR_BIT(TIM4->CCMR1,4);
	//Output Compare 1 preload enable -- >1: Preload register on TIMx_CCR1 enabled
	SET_BIT(TIM4->CCMR1,3);
	//Prescaller and Freq = 50 Hz
	TIM4->PSC =1599;
	TIM4->ARR=100;
	//Duty = 2
	TIM4->CCR1=2;
	//UG: Update generation -->1: Reinitialize the counter and generates an update of the registers
	SET_BIT(TIM4->EGR,0);
	//CEN: Counter enable -- >1: Counter enabled
	SET_BIT(TIM4->CR1,0);
}
void PWM_VidSetDuty(u16 Copy_U16Duty)
{
	TIM4->CCR1=Copy_U16Duty;
}

