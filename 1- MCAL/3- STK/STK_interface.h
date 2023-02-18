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
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H



/********************************************************************************************/
/* Functions Prototype					 			                                        */
/********************************************************************************************/
void MSTK_voidInit(void);

void MSTK_voidSetBusyWaitInMilliSec    (u16 Copy_u16Time);

u8 MSTK_u8SetIntervalSingleInMilliSec  (u16 Copy_u16Time , void (*Copy_ptr) (void));

u8 MSTK_u8SetIntervalPeriodicInMilliSec(u16 Copy_u16Time , void (*Copy_ptr) (void));

void MSTK_voidSetBusyWaitInMicroSec	   (u32 Copy_u32Time);

u8 MSTK_u8SetIntervalSingleInMicroSec  (u32 Copy_u32Time , void (*Copy_ptr) (void));

u8 MSTK_u8SetIntervalPeriodicInMicroSec(u32 Copy_u32Time , void (*Copy_ptr) (void));

void MSTK_voidStopInterval(void);

u32 MSTK_u32GetElapsedTimeInMilliSec(void);

u32 MSTK_u32GetRemainingTimeInMilliSec(void);

u32 MSTK_u32GetElapsedTimeInMicroSec(void);

u32 MSTK_u32GetRemainingTimeInMicroSec(void);

u8 MSTK_u8SetIntervalSingleInMicroSecWithResetTimer(u32 Copy_u32Time , void (*Copy_ptr) (void));

#endif
/********************************************************************************************/
/* END OF FILE: STK_interface.h                                                             */
/********************************************************************************************/
