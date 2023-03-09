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
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef EXTI_INTRTFACE_H
#define EXTI_INTERFACE_H

/********************************************************************************************/
/* Define function parameters  			 			                                        */
/********************************************************************************************/

/* Copy_U8Line */
/* notice:
LINE0 for A0 or B0 or C0
LINE1 for A1 or B1 or C1
etc...
*/
#define EXTI_LINE0      			0
#define EXTI_LINE1      			1
#define EXTI_LINE2      			2
#define EXTI_LINE3      			3
#define EXTI_LINE4      			4
#define EXTI_LINE5      			5
#define EXTI_LINE6      			6
#define EXTI_LINE7      			7
#define EXTI_LINE8      			8
#define EXTI_LINE9      			9
#define EXTI_LINE10     			10
#define EXTI_LINE11     			11
#define EXTI_LINE12     			12
#define EXTI_LINE13     			13
#define EXTI_LINE14     			14
#define EXTI_LINE15     			15


/* EXTI Mode */
#define EXTI_RISING_EDGE   			1
#define EXTI_FALING_EDGE   			2
#define EXTI_ON_CHANGE    			3



/********************************************************************************************/
/* Functions Prototype					 			                                        */
/********************************************************************************************/
void MEXTI_voidInit(void);

void MEXTI_voidEnableEXTI(u8 Copy_u8Line) ;

void MEXTI_voidDisableEXTI(u8 Copy_u8Line);

void MEXTI_voidSwTrigger(u8 Copy_u8Line)  ;

u8 MEXTI_u8SetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode );

u8 MEXTI_u8SetCallBack(void (*Copy_ptr) (void) , u8 Copy_u8Line);

#endif
/********************************************************************************************/
/* END OF FILE: EXTI_interface.h                                                            */
/********************************************************************************************/
