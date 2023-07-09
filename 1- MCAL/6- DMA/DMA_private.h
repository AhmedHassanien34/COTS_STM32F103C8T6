/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    9 march 2023	 		           		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 DMA									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

#define DMA_u32_BASE_ADDRESS                                0x40020000U

typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	volatile u32 CCR1;
	volatile u32 CNDTR1;
	volatile u32 CPAR1;
	volatile u32 CMAR1;
	volatile u32 reserved1;
	volatile u32 CCR2;
	volatile u32 CNDTR2;
	volatile u32 CPAR2;
	volatile u32 CMAR2;
	volatile u32 reserved2;
	volatile u32 CCR3;
	volatile u32 CNDTR3;
	volatile u32 CPAR3;
	volatile u32 CMAR3;
	volatile u32 reserved3;
	volatile u32 CCR4;
	volatile u32 CNDTR4;
	volatile u32 CPAR4;
	volatile u32 CMAR4;
	volatile u32 reserved4;
	volatile u32 CCR5;
	volatile u32 CNDTR5;
	volatile u32 CPAR5;
	volatile u32 CMAR5;
	volatile u32 reserved5;
	volatile u32 CCR6;
	volatile u32 CNDTR6;
	volatile u32 CPAR6;
	volatile u32 CMAR6;
	volatile u32 reserved6;
	volatile u32 CCR7;
	volatile u32 CNDTR7;
	volatile u32 CPAR7;
	volatile u32 CMAR7;
	volatile u32 reserved7;
}DMA_RegDef_t;

#define DMA                                  ((DMA_RegDef_t*)DMA_u32_BASE_ADDRESS)

#endif /* DMA_PRIVATE_H_ */

