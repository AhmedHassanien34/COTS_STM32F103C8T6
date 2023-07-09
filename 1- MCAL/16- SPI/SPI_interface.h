/**
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @defgroup: Header Guards */ 
#ifndef __SPI_SPI_INTERFACE_H__
#define __SPI_SPI_INTERFACE_H__


/*									 
-------------------------------------------------------------- 
!-				 Public Defines 
-------------------------------------------------------------- 
*/ 

enum SPI_ID
{
    SPI1_ID,
    SPI2_ID,
    SPI3_ID
};

#define SPI1_SendByte   SPI1_voidTransmitDataSync
#define SPI1_GetByte    SPI1_voidReceiveDataSync

/*									 
-------------------------------------------------------------- 
!-				 Public Functions Declaration 
-------------------------------------------------------------- 
*/ 

/** @defgroup: SPI 1 Public Functions */
void SPI1_voidInit(void);
void SPI1_voidTransmitDataSync(u16 Copy_u16Data);
void SPI1_voidReceiveDataSync(u16 *Address_u16Data);
void SPI1_voidSetCallBackFunction(void (*SPI1_CallBackFunction)(u16));

/** @defgroup: SPI 2 Public Functions */
void SPI2_voidInit(void);
void SPI2_voidTransmitDataSync(u8 Copy_u8Data);
void SPI2_voidReceiveDataSync(u8 Copy_u8Data);
void SPI2_voidSetCallBackFunction(void (*SPI2_CallBackFunction)(u16));


#endif /* __SPI_SPI_INTERFACE_H__ */
