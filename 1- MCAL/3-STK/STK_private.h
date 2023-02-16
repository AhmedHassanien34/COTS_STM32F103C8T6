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
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

/* STK BASE ADDRESS                                                              				*/
#define STK_BASE_ADDRESS			        0xE000E010

/* REGISTERS ADDRESSES                                                           				*/
#define STK_CTRL			                *((volatile u32 *)(STK_BASE_ADDRESS + 0x00))
#define STK_LOAD			                *((volatile u32 *)(STK_BASE_ADDRESS + 0x04))
#define STK_VAL				                *((volatile u32 *)(STK_BASE_ADDRESS + 0x08))

/* REGISTER BITS                                                                 				*/
#define STK_ENABLE			                0
#define STK_TICKINT			                1
#define STK_CLKSOURCE		                2
#define STK_COUNTFLAG			            16

/* Define configuration paramaters of Clock source selection                     				*/
#define STK_AHB_DIV_BY_8        	        1
#define STK_PROCESSOR_CLOCK_AHB	            2

/* Define type of interval Macros  																*/
#define			STK_SINGLE_INTERVAL			1
#define			STK_PERIODIC_INTERVAL		2

/* Initialize pointer to function with NULL */
static void (*CallBack) (void) = NULL;

/* Initialize Global Variable to carry type of interval */
static u8 MSTK_u8ModeOfInterval = STK_SINGLE_INTERVAL;

#endif
/********************************************************************************************/
/* END OF FILE: STK_private.h                                                               */
/********************************************************************************************/
