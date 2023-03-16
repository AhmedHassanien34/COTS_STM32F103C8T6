/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    9 march 2023	 		           		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 DMA									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

/**************************************** Interfacing macros ****************************************/

/*DMA Channels*/
#define DMA_CHANNEL1    (1)
#define DMA_CHANNEL2    (2)
#define DMA_CHANNEL3    (3)
#define DMA_CHANNEL4    (4)
#define DMA_CHANNEL5    (5)
#define DMA_CHANNEL6    (6)
#define DMA_CHANNEL7    (7)

/*Channels' priorities*/
#define DMA_PRI_LOW     (0)
#define DMA_PRI_MED     (1)
#define DMA_PRI_HIGH    (2)
#define DMA_PRI_VHIGH   (3)

/*Channel data size*/
#define DMA_DS_1BYTE    (0)
#define DMA_DS_2BYTES   (1)
#define DMA_DS_4BYTES   (2)

/*Channel data transfer type*/
#define DMA_PER_TO_MEM  (0)
#define DMA_MEM_TO_PER  (1)
#define DMA_MEM_TO_MEM  (2)

/*Channel enable/disable auto increment*/
#define DMA_DIS_AUTOINC (0)
#define DMA_EN_AUTOINC  (1)

/*Channel enable/disable TC interrupt*/
#define DMA_DIS_TCI     (0)
#define DMA_EN_TCI      (1)

/**************************************** typedefs ****************************************/

/*DMA Configuration structure*/
typedef struct
{
	u8 channelNumber;
	u8 channelPriority;
	u8 dataSize;
	u8 dataTransferType;
	u8 incrementMode;
	u8 enableTCInt;
}DMA_configStruct_t;

/**************************************** Functions' prototypes ****************************************/

/*This function is used to initialize a specific DMA channel*/
u8 DMA_u8DMAChannelInit(DMA_configStruct_t* Copy_pstructDMAChannelConfig);

/*This function is used to transfer data by DMA from source to destination (by interrupt)*/
u8 DMA_u8DMAChannelTransfer(u8 Copy_u8ChannelNumber, u32 Copy_u32SrcAddress, u32 Copy_u32DesAddress, u16 Copy_u16NumberOfTransfers);

/*This function is used to transfer data by DMA from source to destination (by polling)*/
u8 DMA_u8DMAChannelTransfer_busyWait(u8 Copy_u8ChannelNumber, u32 Copy_u32SrcAddress, u32 Copy_u32DesAddress, u16 Copy_u16NumberOfTransfers);

/*This function is used to set the call back function of a DMA channel*/
u8 DMA_u8DMASetCallBack(u8 Copy_u8ChannelNumber, void (*pf) (void));

#endif /* DMA_INTERFACE_H_ */
