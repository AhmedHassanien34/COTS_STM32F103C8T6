/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    9 march 2023	 		           		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 DMA									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

/**************************************** Includes ****************************************/
/*LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*MCAL*/
#include "DMA_private.h"
#include "DMA_config.h"
#include "DMA_interface.h"

/**************************************** Typedefs ****************************************/

typedef void (*fptr_t)(void);

/**************************************** Important variables ****************************************/

fptr_t Global_pfArr[7] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};

/**************************************** Functions' definitions ****************************************/

u8 DMA_u8DMAChannelInit(DMA_configStruct_t* Copy_pstructDMAChannelConfig)
{
	u8 Local_errorState = STD_TYPES_OK;

	switch(Copy_pstructDMAChannelConfig -> channelNumber)
	{
		case DMA_CHANNEL1:

			DMA -> CCR1 = 0;
			DMA -> CCR1 |= ((Copy_pstructDMAChannelConfig -> channelPriority) << 12);
			DMA -> CCR1 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 8);
			DMA -> CCR1 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 10);
			DMA -> CCR1 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 6);
			DMA -> CCR1 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 7);
			DMA -> CCR1 |= ((Copy_pstructDMAChannelConfig -> enableTCInt) << 1);

			if( (Copy_pstructDMAChannelConfig -> dataTransferType) == DMA_MEM_TO_MEM)
			{
				SET_BIT(DMA -> CCR1, 14);
			}
			else
			{
				DMA -> CCR1 |= ((Copy_pstructDMAChannelConfig -> dataTransferType) << 4);
			}

			break;

		case DMA_CHANNEL2:

			DMA -> CCR2 = 0;
			DMA -> CCR2 |= ((Copy_pstructDMAChannelConfig -> channelPriority) << 12);
			DMA -> CCR2 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 8);
			DMA -> CCR2 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 10);
			DMA -> CCR2 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 6);
			DMA -> CCR2 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 7);
			DMA -> CCR2 |= ((Copy_pstructDMAChannelConfig -> enableTCInt) << 1);

			if( (Copy_pstructDMAChannelConfig -> dataTransferType) == DMA_MEM_TO_MEM)
			{
				SET_BIT(DMA -> CCR2, 14);
			}
			else
			{
				DMA -> CCR2 |= ((Copy_pstructDMAChannelConfig -> dataTransferType) << 4);
			}

			break;

		case DMA_CHANNEL3:

			DMA -> CCR3 = 0;
			DMA -> CCR3 |= ((Copy_pstructDMAChannelConfig -> channelPriority) << 12);
			DMA -> CCR3 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 8);
			DMA -> CCR3 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 10);
			DMA -> CCR3 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 6);
			DMA -> CCR3 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 7);
			DMA -> CCR3 |= ((Copy_pstructDMAChannelConfig -> enableTCInt) << 1);

			if( (Copy_pstructDMAChannelConfig -> dataTransferType) == DMA_MEM_TO_MEM)
			{
				SET_BIT(DMA -> CCR3, 14);
			}
			else
			{
				DMA -> CCR3 |= ((Copy_pstructDMAChannelConfig -> dataTransferType) << 4);
			}

			break;

		case DMA_CHANNEL4:

			DMA -> CCR4 = 0;
			DMA -> CCR4 |= ((Copy_pstructDMAChannelConfig -> channelPriority) << 12);
			DMA -> CCR4 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 8);
			DMA -> CCR4 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 10);
			DMA -> CCR4 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 6);
			DMA -> CCR4 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 7);
			DMA -> CCR4 |= ((Copy_pstructDMAChannelConfig -> enableTCInt) << 1);

			if( (Copy_pstructDMAChannelConfig -> dataTransferType) == DMA_MEM_TO_MEM)
			{
				SET_BIT(DMA -> CCR4, 14);
			}
			else
			{
				DMA -> CCR4 |= ((Copy_pstructDMAChannelConfig -> dataTransferType) << 4);
			}

			break;

		case DMA_CHANNEL5:

			DMA -> CCR5 = 0;
			DMA -> CCR5 |= ((Copy_pstructDMAChannelConfig -> channelPriority) << 12);
			DMA -> CCR5 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 8);
			DMA -> CCR5 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 10);
			DMA -> CCR5 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 6);
			DMA -> CCR5 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 7);
			DMA -> CCR5 |= ((Copy_pstructDMAChannelConfig -> enableTCInt) << 1);

			if( (Copy_pstructDMAChannelConfig -> dataTransferType) == DMA_MEM_TO_MEM)
			{
				SET_BIT(DMA -> CCR5, 14);
			}
			else
			{
				DMA -> CCR5 |= ((Copy_pstructDMAChannelConfig -> dataTransferType) << 4);
			}

			break;

		case DMA_CHANNEL6:

			DMA -> CCR6 = 0;
			DMA -> CCR6 |= ((Copy_pstructDMAChannelConfig -> channelPriority) << 12);
			DMA -> CCR6 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 8);
			DMA -> CCR6 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 10);
			DMA -> CCR6 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 6);
			DMA -> CCR6 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 7);
			DMA -> CCR6 |= ((Copy_pstructDMAChannelConfig -> enableTCInt) << 1);

			if( (Copy_pstructDMAChannelConfig -> dataTransferType) == DMA_MEM_TO_MEM)
			{
				SET_BIT(DMA -> CCR6, 14);
			}
			else
			{
				DMA -> CCR6 |= ((Copy_pstructDMAChannelConfig -> dataTransferType) << 4);
			}

			break;

		case DMA_CHANNEL7:

			DMA -> CCR7 = 0;
			DMA -> CCR7 |= ((Copy_pstructDMAChannelConfig -> channelPriority) << 12);
			DMA -> CCR7 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 8);
			DMA -> CCR7 |= ((Copy_pstructDMAChannelConfig -> dataSize) << 10);
			DMA -> CCR7 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 6);
			DMA -> CCR7 |= ((Copy_pstructDMAChannelConfig -> incrementMode) << 7);
			DMA -> CCR7 |= ((Copy_pstructDMAChannelConfig -> enableTCInt) << 1);

			if( (Copy_pstructDMAChannelConfig -> dataTransferType) == DMA_MEM_TO_MEM)
			{
				SET_BIT(DMA -> CCR7, 14);
			}
			else
			{
				DMA -> CCR7 |= ((Copy_pstructDMAChannelConfig -> dataTransferType) << 4);
			}

			break;

		default:
			Local_errorState = STD_TYPES_NOK;
			break;
	}

	return Local_errorState;
}

u8 DMA_u8DMAChannelTransfer(u8 Copy_u8ChannelNumber, u32 Copy_u32SrcAddress, u32 Copy_u32DesAddress, u16 Copy_u16NumberOfTransfers)
{
	u8 Local_errorState = STD_TYPES_NOK;

	switch(Copy_u8ChannelNumber)
	{
		case DMA_CHANNEL1:

			/*Setting the number of transfers*/
			DMA -> CNDTR1 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR1, 14))
			{
				DMA -> CPAR1 = Copy_u32SrcAddress;
				DMA -> CMAR1 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR1, 4))
				{
					DMA -> CMAR1 = Copy_u32SrcAddress;
					DMA -> CPAR1 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR1 = Copy_u32SrcAddress;
					DMA -> CMAR1 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR1, 0);

			break;

		case DMA_CHANNEL2:

			/*Setting the number of transfers*/
			DMA -> CNDTR2 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR2, 14))
			{
				DMA -> CPAR2 = Copy_u32SrcAddress;
				DMA -> CMAR2 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR2, 4))
				{
					DMA -> CMAR2 = Copy_u32SrcAddress;
					DMA -> CPAR2 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR2 = Copy_u32SrcAddress;
					DMA -> CMAR2 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR2, 0);

			break;

		case DMA_CHANNEL3:

			/*Setting the number of transfers*/
			DMA -> CNDTR3 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR3, 14))
			{
				DMA -> CPAR3 = Copy_u32SrcAddress;
				DMA -> CMAR3 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR3, 4))
				{
					DMA -> CMAR3 = Copy_u32SrcAddress;
					DMA -> CPAR3 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR3 = Copy_u32SrcAddress;
					DMA -> CMAR3 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR3, 0);

			break;

		case DMA_CHANNEL4:

			/*Setting the number of transfers*/
			DMA -> CNDTR4 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR4, 14))
			{
				DMA -> CPAR4 = Copy_u32SrcAddress;
				DMA -> CMAR4 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR4, 4))
				{
					DMA -> CMAR4 = Copy_u32SrcAddress;
					DMA -> CPAR4 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR4 = Copy_u32SrcAddress;
					DMA -> CMAR4 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR4, 0);

			break;

		case DMA_CHANNEL5:

			/*Setting the number of transfers*/
			DMA -> CNDTR5 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR5, 14))
			{
				DMA -> CPAR5 = Copy_u32SrcAddress;
				DMA -> CMAR5 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR5, 4))
				{
					DMA -> CMAR5 = Copy_u32SrcAddress;
					DMA -> CPAR5 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR5 = Copy_u32SrcAddress;
					DMA -> CMAR5 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR5, 0);

			break;

		case DMA_CHANNEL6:

			/*Setting the number of transfers*/
			DMA -> CNDTR6 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR6, 14))
			{
				DMA -> CPAR6 = Copy_u32SrcAddress;
				DMA -> CMAR6 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR6, 4))
				{
					DMA -> CMAR6 = Copy_u32SrcAddress;
					DMA -> CPAR6 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR6 = Copy_u32SrcAddress;
					DMA -> CMAR6 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR6, 0);

			break;

		case DMA_CHANNEL7:

			/*Setting the number of transfers*/
			DMA -> CNDTR7 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR7, 14))
			{
				DMA -> CPAR7 = Copy_u32SrcAddress;
				DMA -> CMAR7 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR7, 4))
				{
					DMA -> CMAR7 = Copy_u32SrcAddress;
					DMA -> CPAR7 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR7 = Copy_u32SrcAddress;
					DMA -> CMAR7 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR7, 0);

			break;
	}

	return Local_errorState;
}

u8 DMA_u8DMAChannelTransfer_busyWait(u8 Copy_u8ChannelNumber, u32 Copy_u32SrcAddress, u32 Copy_u32DesAddress, u16 Copy_u16NumberOfTransfers)
{
	u8 Local_errorState = STD_TYPES_OK;

	switch(Copy_u8ChannelNumber)
	{
		case DMA_CHANNEL1:

			/*Setting the number of transfers*/
			DMA -> CNDTR1 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR1, 14))
			{
				DMA -> CPAR1 = Copy_u32SrcAddress;
				DMA -> CMAR1 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR1, 4))
				{
					DMA -> CMAR1 = Copy_u32SrcAddress;
					DMA -> CPAR1 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR1 = Copy_u32SrcAddress;
					DMA -> CMAR1 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR1, 0);

			break;

		case DMA_CHANNEL2:

			/*Setting the number of transfers*/
			DMA -> CNDTR2 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR2, 14))
			{
				DMA -> CPAR2 = Copy_u32SrcAddress;
				DMA -> CMAR2 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR2, 4))
				{
					DMA -> CMAR2 = Copy_u32SrcAddress;
					DMA -> CPAR2 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR2 = Copy_u32SrcAddress;
					DMA -> CMAR2 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR2, 0);

			break;

		case DMA_CHANNEL3:

			/*Setting the number of transfers*/
			DMA -> CNDTR3 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR3, 14))
			{
				DMA -> CPAR3 = Copy_u32SrcAddress;
				DMA -> CMAR3 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR3, 4))
				{
					DMA -> CMAR3 = Copy_u32SrcAddress;
					DMA -> CPAR3 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR3 = Copy_u32SrcAddress;
					DMA -> CMAR3 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR3, 0);

			break;

		case DMA_CHANNEL4:

			/*Setting the number of transfers*/
			DMA -> CNDTR4 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR4, 14))
			{
				DMA -> CPAR4 = Copy_u32SrcAddress;
				DMA -> CMAR4 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR4, 4))
				{
					DMA -> CMAR4 = Copy_u32SrcAddress;
					DMA -> CPAR4 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR4 = Copy_u32SrcAddress;
					DMA -> CMAR4 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR4, 0);

			break;

		case DMA_CHANNEL5:

			/*Setting the number of transfers*/
			DMA -> CNDTR5 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR5, 14))
			{
				DMA -> CPAR5 = Copy_u32SrcAddress;
				DMA -> CMAR5 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR5, 4))
				{
					DMA -> CMAR5 = Copy_u32SrcAddress;
					DMA -> CPAR5 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR5 = Copy_u32SrcAddress;
					DMA -> CMAR5 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR5, 0);

			break;

		case DMA_CHANNEL6:

			/*Setting the number of transfers*/
			DMA -> CNDTR6 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR6, 14))
			{
				DMA -> CPAR6 = Copy_u32SrcAddress;
				DMA -> CMAR6 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR6, 4))
				{
					DMA -> CMAR6 = Copy_u32SrcAddress;
					DMA -> CPAR6 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR6 = Copy_u32SrcAddress;
					DMA -> CMAR6 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR6, 0);

			break;

		case DMA_CHANNEL7:

			/*Setting the number of transfers*/
			DMA -> CNDTR7 = Copy_u16NumberOfTransfers;

			/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA -> CCR7, 14))
			{
				DMA -> CPAR7 = Copy_u32SrcAddress;
				DMA -> CMAR7 = Copy_u32DesAddress;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA -> CCR7, 4))
				{
					DMA -> CMAR7 = Copy_u32SrcAddress;
					DMA -> CPAR7 = Copy_u32DesAddress;
				}
				else
				{
					DMA -> CPAR7 = Copy_u32SrcAddress;
					DMA -> CMAR7 = Copy_u32DesAddress;
				}
			}

			/*Enable channel*/
			SET_BIT(DMA -> CCR7, 0);

			break;
	}

	/*Polling over TC flag*/
	while(! (GET_BIT(DMA -> ISR, (1 + (4*(Copy_u8ChannelNumber - 1))) )));

	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR, (1 + (4*(Copy_u8ChannelNumber - 1))) );

	return Local_errorState;
}

u8 DMA_u8DMASetCallBack(u8 Copy_u8ChannelNumber, void (*pf) (void))
{
	u8 Local_errorState = STD_TYPES_OK;

	Global_pfArr[Copy_u8ChannelNumber - 1] = pf;

	return Local_errorState;
}

/**************************************** Handlers ****************************************/

void DMA1_Channel1_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR, 1);

	if(Global_pfArr[0] != NULL)
	{
		Global_pfArr[0]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel2_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR, 5);

	if(Global_pfArr[1] != NULL)
	{
		Global_pfArr[1]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel3_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR, 9);

	if(Global_pfArr[2] != NULL)
	{
		Global_pfArr[2]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel4_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR, 13);

	if(Global_pfArr[3] != NULL)
	{
		Global_pfArr[3]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel5_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR, 17);

	if(Global_pfArr[4] != NULL)
	{
		Global_pfArr[4]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel6_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR, 21);

	if(Global_pfArr[5] != NULL)
	{
		Global_pfArr[5]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel7_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR, 25);

	if(Global_pfArr[6] != NULL)
	{
		Global_pfArr[6]();
	}
	else
	{
		/*Do nothing*/
	}
}
