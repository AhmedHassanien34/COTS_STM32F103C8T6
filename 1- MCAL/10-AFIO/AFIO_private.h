/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    9 march 2023	 		           		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 AFIO									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

/* Define Struct for AFIO Registers */
typedef struct{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
	
}AFIO_t;

/* AFIO is a pointer to struct */
#define AFIO ((volatile AFIO_t *)0x40010000)

/* Define Macros */
#define AFIO_LAST_4_BITS_IN_EXTICR0					3
#define AFIO_LAST_4_BITS_IN_EXTICR1					7
#define AFIO_LAST_4_BITS_IN_EXTICR2					11
#define AFIO_LAST_4_BITS_IN_EXTICR3					15

#define AFIO_EXTICR0								0
#define AFIO_EXTICR1								1
#define AFIO_EXTICR2								2
#define AFIO_EXTICR3								3

#endif
/********************************************************************************************/
/* END OF FILE: AFIO_private.h                                                              */
/********************************************************************************************/
