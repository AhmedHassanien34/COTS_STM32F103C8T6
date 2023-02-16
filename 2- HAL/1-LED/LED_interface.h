/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    15 February 2023	            		*************/
/**************************		Layer:   HAL								   	*************/
/**************************		SWC:	 LED									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

/********************************************************************************************/
/* Functions Prototype					 			                                        */
/********************************************************************************************/
void HLED_voidTurnOn(u8 Copy_u8PORT , u8 Copy_u8PIN);

void HLED_voidTurnOff(u8 Copy_u8PORT , u8 Copy_u8PIN);

void HLED_voidToggle(u8 Copy_u8PORT , u8 Copy_u8PIN, u16 Copy_u8Delay);

#endif
/********************************************************************************************/
/* END OF FILE: LED_interface.h                                                             */
/********************************************************************************************/