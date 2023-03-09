/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    5 march 2023	 		           		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 NVIC									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* REGISTERS ADDRESSES FOR NVIC */
#define	NVIC_ISER0					*((u32*)0xE000E100)	 			/* Enable External interrupts from 0 to 31    */
#define NVIC_ISER1					*((u32*)0xE000E104)				/* Enable External interrupts from 32 to 63   */

#define	NVIC_ICER0					*((u32*)0xE000E180)	 			/* Disable External interrupts from 0 to 31   */
#define NVIC_ICER1					*((u32*)0xE000E184)				/* Disable External interrupts from 32 to 63  */

#define NVIC_ISPR0              	*((u32*)0xE000E200)				/* Set pending flag from 0  to 31             */
#define NVIC_ISPR1              	*((u32*)0xE000E204)				/* Set pending flag from 32 to 63             */

#define NVIC_ICPR0              	*((u32*)0xE000E280)				/* Clear pending flag from 32 to 63           */
#define NVIC_ICPR1              	*((u32*)0xE000E284)				/* Clear pending flag from 32 to 63           */

#define NVIC_IABR0					*((volatile u32*)0xE000E300) 	/* to check active bit register status from  0  to 31 */
#define NVIC_IABR1					*((volatile u32*)0xE000E300)	/* to check active bit register status from  32 to 63 */

#define NVIC_IPR				 	((u8 *)0xE000E400)              /* Set priority of interrupts */

/* Macros Definition */
#define NVIC_INTERRUPT_INDX_31		31
#define NVIC_INTERRUPT_INDX_59		59

#endif
/********************************************************************************************/
/* END OF FILE: NVIC_private.h                                                              */
/********************************************************************************************/
