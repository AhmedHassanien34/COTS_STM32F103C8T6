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
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Select  Enable Clock source */
/* choose : 
            1- RCC_HSI
			2- RCC_HSE
            3- RCC_PLL
 */
#define RCC_CLOCK_SOURCE					RCC_HSE

/* Note: Select value only if you have HSE as input clock source */
#if RCC_CLOCK_SOURCE == RCC_HSE
/* Select HSE type */
/* choose : 
            1- RCC_RC
			2- RCC_CRYSTAL
 */
#define RCC_HSE_TYPE						RCC_CRYSTAL
#endif

/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_SOURCE == RCC_PLL
/* Configure PLL entry clock source */
/* choose :
            1- RCC_HSI_DIV_BY_2
			2- RCC_HSE
 */
#define RCC_PLL_ENTRY_CLOCK_SOURCE			RCC_HSE


/* Configure HSE divider for PLL entry */
/* choose :
            1- RCC_HSE_NOT_DIV
			2- RCC_HSE_DIV_BY_2
 */
#define RCC_HSE_DIV_FOR_PLL_ENTRY			RCC_HSE_DIV_BY_2

/* Configure PLL multiplication factor */
/* Caution: The PLL output frequency must not exceed 72 MHz */
/* choose :
            1-  RCC_PLL_MUL_BY_2
		    2-  RCC_PLL_MUL_BY_3
		    3-  RCC_PLL_MUL_BY_4
		    4-  RCC_PLL_MUL_BY_5
		    5-  RCC_PLL_MUL_BY_6
		    6-  RCC_PLL_MUL_BY_7
		    7-  RCC_PLL_MUL_BY_8
		    8-  RCC_PLL_MUL_BY_9
		    9-  RCC_PLL_MUL_BY_10
		    10- RCC_PLL_MUL_BY_11
		    11- RCC_PLL_MUL_BY_12
		    12- RCC_PLL_MUL_BY_13
		    13- RCC_PLL_MUL_BY_14
		    14- RCC_PLL_MUL_BY_15
		    15- RCC_PLL_MUL_BY_16
		    16- RCC_PLL_MUL_BY_16
 */
#define RCC_PLL_MUL_FACTOR					RCC_PLL_MUL_BY_2
#endif

/* Configure Clock security system */
/* choose : 
            1- RCC_CSS_ENABLE
			2- RCC_CSS_DISABLE
 */
#define CLOCK_SECURITY_SYSTEM				RCC_CSS_DISABLE

/* Configure Internal high-speed clock trimming */
/* choose : 
            1-  RCC_HSITRIM_P40KHZ
			2-  RCC_HSITRIM_P80KHZ
			3-  RCC_HSITRIM_P120KHZ
			4-  RCC_HSITRIM_P160KHZ
			5-  RCC_HSITRIM_P200KHZ
			6-  RCC_HSITRIM_P240KHZ
			7-  RCC_HSITRIM_P280KHZ
            8-  RCC_HSITRIM_P320KHZ
            9-  RCC_HSITRIM_P360KHZ			
			10- RCC_HSITRIM_P400KHZ			
			11- RCC_HSITRIM_P440KHZ			
			12- RCC_HSITRIM_P480KHZ			
			13- RCC_HSITRIM_P520KHZ			
			14- RCC_HSITRIM_P560KHZ			
			15- RCC_HSITRIM_P600KHZ	
			------------------------
			16- RCC_HSITRIM_0KHZ	
			------------------------
            17- RCC_HSITRIM_N40KHZ
			18- RCC_HSITRIM_N80KHZ
			19- RCC_HSITRIM_N120KHZ
			20- RCC_HSITRIM_N160KHZ
			21- RCC_HSITRIM_N200KHZ
			22- RCC_HSITRIM_N240KHZ
			23- RCC_HSITRIM_N280KHZ
            24- RCC_HSITRIM_N320KHZ
            25- RCC_HSITRIM_N360KHZ			
			26- RCC_HSITRIM_N400KHZ			
			27- RCC_HSITRIM_N440KHZ			
			28- RCC_HSITRIM_N480KHZ			
			29- RCC_HSITRIM_N520KHZ			
			30- RCC_HSITRIM_N560KHZ			
			31- RCC_HSITRIM_N600KHZ			
			32- RCC_HSITRIM_N640KHZ					
 */
#define RCC_HSI_CLOCK_TRIMMING				RCC_HSITRIM_0KHZ

/* Configure APB high-speed prescaler (APB2) */
/* choose :
            1- RCC_HCLK_APB2_NOT_DIVIDED
		    2- RCC_HCLK_APB2_DIVIDED_BY_2
		    3- RCC_HCLK_APB2_DIVIDED_BY_4
            4- RCC_HCLK_APB2_DIVIDED_BY_8
            5- RCC_HCLK_APB2_DIVIDED_BY_16
 */
#define RCC_APB_HIGH_SPEED_PRESCALER		RCC_HCLK_APB2_NOT_DIVIDED

/* Configure APB low-speed prescaler (APB1) */
/* Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain */
/* choose :
            1- RCC_HCLK_APB1_NOT_DIVIDED
		    2- RCC_HCLK_APB1_DIVIDED_BY_2
		    3- RCC_HCLK_APB1_DIVIDED_BY_4
		    4- RCC_HCLK_APB1_DIVIDED_BY_8
		    5- RCC_HCLK_APB1_DIVIDED_BY_16

 */
#define RCC_APB_LOW_SPEED_PRESCALER			RCC_HCLK_APB1_NOT_DIVIDED

/* Configure  AHB prescaler */
/* choose :
            1- SYSCLK_NOT_DIVIDED
		    2- SYSCLK_DIVIDED_BY_2
		    3- SYSCLK_DIVIDED_BY_4
		    4- SYSCLK_DIVIDED_BY_8
		    5- SYSCLK_DIVIDED_BY_16
		    6- SYSCLK_DIVIDED_BY_64
		    7- SYSCLK_DIVIDED_BY_128
		    8- SYSCLK_DIVIDED_BY_256
		    9- SYSCLK_DIVIDED_BY_512
 */
#define RCC_AHP_PRESCALER 			 		SYSCLK_NOT_DIVIDED

/* Configure System clock switch */
/* choose :
            1-  RCC_HSI_SYSTEM_CLOCK
		    2-  RCC_HSE_SYSTEM_CLOCK
		    3-  RCC_PLL_SYSTEM_CLOCK
 */
#define RCC_SYSTEM_CLOCK					RCC_HSE_SYSTEM_CLOCK

#endif 
/********************************************************************************************/
/* END OF FILE: RCC_config.h                                                                */
/********************************************************************************************/
