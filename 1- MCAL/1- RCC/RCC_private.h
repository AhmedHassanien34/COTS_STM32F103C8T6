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
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* RCC BASE ADDRESS                                                              */
#define RCC_BASE_ADDRESS			        0x40021000

/* REGISTERS ADDRESSES                                                           */
#define RCC_CR		   				        *((volatile u32*)(RCC_BASE_ADDRESS + 0x00))
#define RCC_CFGR	   				        *((volatile u32*)(RCC_BASE_ADDRESS + 0x04))
#define RCC_CIR		   				        *((volatile u32*)(RCC_BASE_ADDRESS + 0x08))
#define RCC_APB2RSTR   				        *((volatile u32*)(RCC_BASE_ADDRESS + 0x0C))
#define RCC_APB1RSTR   				        *((volatile u32*)(RCC_BASE_ADDRESS + 0x10))
#define RCC_AHBENR	   				        *((volatile u32*)(RCC_BASE_ADDRESS + 0x14))
#define RCC_APB2ENR	   				        *((volatile u32*)(RCC_BASE_ADDRESS + 0x18))
#define RCC_APB1ENR	   				        *((volatile u32*)(RCC_BASE_ADDRESS + 0x1C))
#define RCC_BDCR	   				        *((volatile u32*)(RCC_BASE_ADDRESS + 0x20))
#define RCC_CSR		   				        *((volatile u32*)(RCC_BASE_ADDRESS + 0x24))

/* REGISTER BITS                                                                 */
/* CR REGISTER                                                                   */
#define RCC_HSI_ON						    0
#define RCC_HSE_ON						    16
#define RCC_HSE_BYP					        18
#define RCC_CSS_ON					        19
#define RCC_PLL_ON					        24

/* CFGR REGISTER                                                                 */
#define RCC_PLLSRC					        16
#define RCC_PLLXTPRE				        17


/* Define configuration paramaters of Enable Clock source                        */
#define RCC_HSI								1
#define RCC_HSE								2
#define RCC_PLL								3

/* Define configuration paramaters of HSE type                                   */
#define RCC_RC								1
#define RCC_CRYSTAL							2

/* Define configuration paramaters of Clock security system                      */
#define RCC_CSS_ENABLE						1
#define RCC_CSS_DISABLE						2

/* Define MASK & configuration paramaters of Internal high-speed clock trimming  */
#define RCC_HSITRIM_N40KHZ					0x00000000
#define RCC_HSITRIM_N80KHZ                  0x00000008
#define RCC_HSITRIM_N120KHZ                 0x00000010
#define RCC_HSITRIM_N160KHZ                 0x00000018
#define RCC_HSITRIM_N200KHZ                 0x00000020
#define RCC_HSITRIM_N240KHZ                 0x00000028
#define RCC_HSITRIM_N280KHZ                 0x00000030
#define RCC_HSITRIM_N320KHZ                 0x00000038
#define RCC_HSITRIM_N360KHZ                 0x00000040
#define RCC_HSI0TRIM_N400KHZ                0x00000048
#define RCC_HSITRIM_N440KHZ               	0x00000050
#define RCC_HSITRIM_N480KHZ               	0x00000058
#define RCC_HSITRIM_N520KHZ                	0x00000060
#define RCC_HSITRIM_N560KHZ                	0x00000068
#define RCC_HSITRIM_N600KHZ                	0x00000070
#define RCC_HSITRIM_N640KHZ					0x00000078
#define RCC_HSITRIM_0KHZ     				0x00000080
#define RCC_HSITRIM_P40KHZ					0x00000088
#define RCC_HSITRIM_P80KHZ					0x00000090
#define RCC_HSITRIM_P120KHZ					0x00000098
#define RCC_HSITRIM_P160KHZ                 0x000000A0
#define RCC_HSITRIM_P200KHZ                 0x000000A8
#define RCC_HSITRIM_P240KHZ                 0x000000B0
#define RCC_HSITRIM_P280KHZ                 0x000000B8
#define RCC_HSITRIM_P320KHZ                 0x000000C0
#define RCC_HSITRIM_P360KHZ                 0x000000C8
#define RCC_HSITRIM_P400KHZ                 0x000000D0
#define RCC_HSITRIM_P440KHZ                 0x000000D8
#define RCC_HSITRIM_P480KHZ                 0x000000E0
#define RCC_HSITRIM_P520KHZ                 0x000000E8
#define RCC_HSITRIM_P560KHZ                 0x000000F0
#define RCC_HSITRIM_P600KHZ                 0x000000F8

#define RCC_HSITRIM_MASK					0xFFFFFF07

/* Define configuration paramaters of PLL entry clock source                     */
#define RCC_HSI_DIV_BY_2					1
#define RCC_HSE								2

/* Define configuration paramaters of HSE divider for PLL entry                  */
#define RCC_HSE_NOT_DIV 					1
#define RCC_HSE_DIV_BY_2					2

/* Define MASK & configuration paramaters of  PLL multiplication factor          */
#define RCC_PLL_MUL_BY_2					0x00000000
#define RCC_PLL_MUL_BY_3                    0x00040000
#define RCC_PLL_MUL_BY_4                    0x00080000
#define RCC_PLL_MUL_BY_5                    0x000C0000
#define RCC_PLL_MUL_BY_6                    0x00100000
#define RCC_PLL_MUL_BY_7                    0x00140000
#define RCC_PLL_MUL_BY_8                    0x00180000
#define RCC_PLL_MUL_BY_9                    0x001C0000
#define RCC_PLL_MUL_BY_10                   0x00200000
#define RCC_PLL_MUL_BY_11                   0x00240000
#define RCC_PLL_MUL_BY_12                   0x00280000
#define RCC_PLL_MUL_BY_13                   0x002C0000
#define RCC_PLL_MUL_BY_14                   0x00300000
#define RCC_PLL_MUL_BY_15                   0x00340000
#define RCC_PLL_MUL_BY_16                   0x00380000

#define RCC_PLL_MUL_MASK					0xFFC3FFFF

/* Define MASK & configuration paramaters of APB high-speed prescaler (APB2)     */
#define RCC_HCLK_APB2_NOT_DIVIDED			0x00000000
#define RCC_HCLK_APB2_DIVIDED_BY_2			0x00002000
#define RCC_HCLK_APB2_DIVIDED_BY_4			0x00002800
#define RCC_HCLK_APB2_DIVIDED_BY_8			0x00003000
#define RCC_HCLK_APB2_DIVIDED_BY_16			0x00003800

#define RCC_HCLK_APB2_PRESCALER_MASK		0xFFFFC7FF


/* Define MASK & configuration paramaters of APB low-speed prescaler (APB1)      */
#define RCC_HCLK_APB1_NOT_DIVIDED			0x00000000
#define RCC_HCLK_APB1_DIVIDED_BY_2			0x00000400
#define RCC_HCLK_APB1_DIVIDED_BY_4			0x00000500
#define RCC_HCLK_APB1_DIVIDED_BY_8			0x00000600
#define RCC_HCLK_APB1_DIVIDED_BY_16			0x00000700

#define RCC_HCLK_APB1_PRESCALER_MASK		0xFFFFF8FF

/* Define MASK & configuration paramaters of AHB prescaler                       */
#define SYSCLK_NOT_DIVIDED   				0x00000000
#define SYSCLK_DIVIDED_BY_2   				0x00000080
#define SYSCLK_DIVIDED_BY_4  				0x00000090
#define SYSCLK_DIVIDED_BY_8                 0x000000A0
#define SYSCLK_DIVIDED_BY_16                0x000000B0
#define SYSCLK_DIVIDED_BY_64                0x000000C0
#define SYSCLK_DIVIDED_BY_128               0x000000D0
#define SYSCLK_DIVIDED_BY_256               0x000000E0
#define SYSCLK_DIVIDED_BY_512               0x000000F0

#define RCC_AHB_PRESCALER_MASK			    0xFFFFFF0F

/* Define MASK & configuration paramaters of System clock switch                 */
#define RCC_HSI_SYSTEM_CLOCK   				0x00000000
#define RCC_HSE_SYSTEM_CLOCK   				0x0000000D
#define RCC_PLL_SYSTEM_CLOCK   				0x0000000E

#define RCC_SW_MASK							0xFFFFFFFC

/* Define Max number of peripheral id */
#define RCC_MAX_NUM_OF_PER_ID				31

#endif
/********************************************************************************************/
/* END OF FILE: RCC_private.h                                                               */
/********************************************************************************************/
