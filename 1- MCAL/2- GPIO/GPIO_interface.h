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
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/********************************************************************************************/
/* Define function parameters  			 			                                        */
/********************************************************************************************/
/* Copy_u8Value */
#define	GPIO_HIGH						                1
#define	GPIO_LOW							            0

/* Copy_u8Port */
#define GPIOA 						    	            0
#define GPIOB 						    	            1
#define GPIOC 						    	            2

/* Copy_u8Pin */
#define GPIO_PIN0						                0
#define GPIO_PIN1						                1
#define GPIO_PIN2						                2
#define GPIO_PIN3						                3
#define GPIO_PIN4						                4
#define GPIO_PIN5						                5
#define GPIO_PIN6						                6
#define GPIO_PIN7						                7
#define GPIO_PIN8						                8
#define GPIO_PIN9						                9
#define GPIO_PIN10						                10
#define GPIO_PIN11						                11
#define GPIO_PIN12						                12
#define GPIO_PIN13						                13
#define GPIO_PIN14						                14
#define GPIO_PIN15						                15

/* Copy_u8Mode */
#define GPIO_INPUT_ANALOG				                0b0000
#define GPIO_INPUT_FLOATING				                0b0100
#define GPIO_INPUT_PULL_UP_DOWN			                0b1000

#define GPIO_OUTPUT_SPEED_10MHZ_PP		                0b0001
#define GPIO_OUTPUT_SPEED_10MHZ_OD		                0b0101
#define GPIO_OUTPUT_SPEED_10MHZ_AFPP		            0b1001
#define GPIO_OUTPUT_SPEED_10MHZ_AFOD		            0b1101

#define GPIO_OUTPUT_SPEED_2MHZ_PP		                0b0010
#define GPIO_OUTPUT_SPEED_2MHZ_OD		                0b0110
#define GPIO_OUTPUT_SPEED_2MHZ_AFPP		                0b1010
#define GPIO_OUTPUT_SPEED_2MHZ_AFOD		                0b1110

#define GPIO_OUTPUT_SPEED_50MHZ_PP			            0b0011
#define GPIO_OUTPUT_SPEED_50MHZ_OD			            0b0111
#define GPIO_OUTPUT_SPEED_50MHZ_AFPP		            0b1011
#define GPIO_OUTPUT_SPEED_50MHZ_AFOD		            0b1111

/* Copy_u8HalfPortMode */
#define GPIO_PORT_INPUT_ANALOG				            0x00000000
#define GPIO_PORT_INPUT_FLOATING			            0x44444444
#define GPIO_PORT_INPUT_PULL_UP_DOWN		            0x88888888

#define GPIO_PORT_OUTPUT_SPEED_10MHZ_PP		            0x11111111
#define GPIO_PORT_OUTPUT_SPEED_10MHZ_OD		            0x55555555
#define GPIO_PORT_OUTPUT_SPEED_10MHZ_AFPP               0x99999999
#define GPIO_PORT_OUTPUT_SPEED_10MHZ_AFOD	            0xDDDDDDDD

#define GPIO_PORT_OUTPUT_SPEED_2MHZ_PP		            0x22222222
#define GPIO_PORT_OUTPUT_SPEED_2MHZ_OD		            0x66666666
#define GPIO_PORT_OUTPUT_SPEED_2MHZ_AFPP	            0xAAAAAAAA
#define GPIO_PORT_OUTPUT_SPEED_2MHZ_AFOD	            0xEEEEEEEE

#define GPIO_PORT_OUTPUT_SPEED_50MHZ_PP		            0x33333333
#define GPIO_PORT_OUTPUT_SPEED_50MHZ_OD		            0x77777777
#define GPIO_PORT_OUTPUT_SPEED_50MHZ_AFPP	            0xBBBBBBBB
#define GPIO_PORT_OUTPUT_SPEED_50MHZ_AFOD				0xFFFFFFFF

/* Copy_u8HalfPort */
#define GPIO_1ST_HALF_PORT								1
#define GPIO_2ND_HALF_PORT								2



/********************************************************************************************/
/* Functions Prototype					 			                                        */
/********************************************************************************************/
u8 MGPIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode);

u8 MGPIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_pu8Value);

u8 MGPIO_u8SetLowPortDirection(u8 Copy_u8Port , u32 Copy_u32HalfPortMode);

u8 MGPIO_u8SetHighPortDirection(u8 Copy_u8Port , u32 Copy_u32HalfPortMode);

u8 MGPIO_u8SetHalfPortValue(u8 Copy_u8Port , u8 Copy_u8HalfPort , u8 Copy_u8Value);

void MGPIO_voidSetPortDirection(u8 Copy_u8Port , u32 Copy_u32HalfPortMode);

u8 MGPIO_u8SetPortValue(u8 Copy_u8Port , u16 Copy_u16Value);

#endif
/********************************************************************************************/
/* END OF FILE: GPIO_interface.h                                                            */
/********************************************************************************************/
