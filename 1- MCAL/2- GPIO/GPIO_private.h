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
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* RCC BASE ADDRESSES            */
#define GPIOA_BASE_ADDRESS			0x40010800
#define GPIOB_BASE_ADDRESS			0x40010C00
#define GPIOC_BASE_ADDRESS			0x40011000

/* REGISTERS ADDRESSES FOR PORTA */
#define GPIOA_CRL					*((u32*)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH					*((u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR					*((u32*)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR					*((u32*)(GPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_BSRR					*((u32*)(GPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR					*((u32*)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_LCK					*((u32*)(GPIOA_BASE_ADDRESS + 0x18))

/* REGISTERS ADDRESSES FOR PORTB */
#define GPIOB_CRL					*((u32*)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH					*((u32*)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR					*((u32*)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR					*((u32*)(GPIOB_BASE_ADDRESS + 0x0C))
#define GPIOB_BSRR					*((u32*)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR					*((u32*)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_LCK					*((u32*)(GPIOB_BASE_ADDRESS + 0x18))

/* REGISTERS ADDRESSES FOR PORTC */
#define GPIOC_CRL					*((u32*)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH					*((u32*)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR					*((u32*)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR					*((u32*)(GPIOC_BASE_ADDRESS + 0x0C))
#define GPIOC_BSRR					*((u32*)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR					*((u32*)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_LCK					*((u32*)(GPIOC_BASE_ADDRESS + 0x18))

/* Define first and second HalfPort */
#define GPIO_1ST_HALF_PORT_MASK			0xFFFFFF00
#define GPIO_2ND_HALF_PORT_MASK			0xFFFF00FF


#endif
/********************************************************************************************/
/* END OF FILE: GPIO_private.h                                                              */
/********************************************************************************************/
