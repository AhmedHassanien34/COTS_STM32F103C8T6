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
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/********************************************************************************************/
/* Define function parameters  			 			                                        */
/********************************************************************************************/
/* Copy_u8IntNumber */
#define NVIC_EXTI0					6
#define NVIC_EXTI1					7
#define NVIC_EXTI2					8
#define NVIC_EXTI3					9
#define NVIC_EXTI4					10

/* Copy_u8GroupPriority */
#define NVIC_GROUP0					0
#define NVIC_GROUP1					1
#define NVIC_GROUP2					2
#define NVIC_GROUP3					3
#define NVIC_GROUP4					4
#define NVIC_GROUP5					5
#define NVIC_GROUP6					6
#define NVIC_GROUP7					7
#define NVIC_GROUP8					8
#define NVIC_GROUP9					9
#define NVIC_GROUP10				10
#define NVIC_GROUP11				11
#define NVIC_GROUP12				12
#define NVIC_GROUP13				13
#define NVIC_GROUP14				14
#define NVIC_GROUP15				15

/* Copy_u8SubPriority */
#define NVIC_SUB_GROUP0             0
#define NVIC_SUB_GROUP1             1
#define NVIC_SUB_GROUP2             2
#define NVIC_SUB_GROUP3             3
#define NVIC_SUB_GROUP4             4
#define NVIC_SUB_GROUP5             5
#define NVIC_SUB_GROUP6             6
#define NVIC_SUB_GROUP7             7
#define NVIC_SUB_GROUP8             8
#define NVIC_SUB_GROUP9             9
#define NVIC_SUB_GROUP10            10
#define NVIC_SUB_GROUP11            11
#define NVIC_SUB_GROUP12            12
#define NVIC_SUB_GROUP13            13
#define NVIC_SUB_GROUP14            14
#define NVIC_SUB_GROUP15            15

/* Copy_u32GroupSubGroub */
#define NVIC_GROUP_4_SUB_0			0x05FA0300  // 4 bits for group
#define NVIC_GROUP_3_SUB_1			0x05FA0400  // 3 bits for group and 1 bit for sub
#define NVIC_GROUP_2_SUB_2			0x05FA0500  // 2 bits for group and 2 bit for sub
#define NVIC_GROUP_1_SUB_3			0x05FA0600  // 1 bits for group and 3 bit for sub
#define NVIC_GROUP_0_SUB_4			0x05FA0700  // 0 group and 4 bits for sub



/********************************************************************************************/
/* Functions Prototype					 			                                        */
/********************************************************************************************/
u8 MNVIC_u8EnableInterrupt(u8 Copy_u8IntNumber);

u8 MNVIC_u8DisableInterrupt(u8 Copy_u8IntNumber);

u8 MNVIC_u8SetPendingFlag(u8 Copy_u8IntNumber);

u8 MNVIC_u8ClearPendingFlag(u8 Copy_u8IntNumber);

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber , u8* Copy_pu8Result);

void MNVIC_voidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u32Mode);

#endif
/********************************************************************************************/
/* END OF FILE: NVIC_interface.h                                                            */
/********************************************************************************************/
