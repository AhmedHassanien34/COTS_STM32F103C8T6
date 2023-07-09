/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    25 MARCH 2023	    	        		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 SPI									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


/********************************************************************************************/
/* Include libraries                                                                        */
/********************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/********************************************************************************************/
/* Include Component Files                                                                  */
/********************************************************************************************/
#include "GPIO_Interface.h"
#include "SPI_private.h" 
#include "SPI_config.h" 
#include "SPI_interface.h" 

/*									 
-------------------------------------------------------------- 
!-				 Global Variables 
-------------------------------------------------------------- 
*/ 
/** @defgroup: SPI 1 Global Variables */
static SPI_CallBackFunction_t G_SPICallBackFunction[NUM_OF_SPI] = {NULL};

/*									 
-------------------------------------------------------------- 
!-				 Public Function Implementation 
-------------------------------------------------------------- 
*/ 

/**
 * @defgroup: SPI 1 Public Functions
 */
void SPI1_voidInit(void)
{
/** @def: General ST-Optional configuration */
    /* Set the Software Slave Select Management Mode */
    BIT_SET(SPI1->CR[0], SSM);
    /* Set the Slave Select pin as high (No choosen slave) */
    BIT_SET(SPI1->CR[0], SSI);
	  /* Enable the slave select pin */
	//BIT_SET(SPI1->CR[1], SSOE);  // TODO:
	
	// TODO: To be optimized
	DIO_voidSetPinStatus(SPI1_SLAVE1_PORT, SPI1_SLAVE1_PIN, DIO_OUTPUT_PUSHPULL_50MHZ);
	DIO_voidSetPin(SPI1_SLAVE1_PORT, SPI1_SLAVE1_PIN);
/**---------------------------------
 * @defgroup: SPI1_CLK_POLARITY
 */
#if   (SPI1_CLK_POLARITY == SPI1_CLK_POLARITY_LOW)
    BIT_CLR(SPI1->CR[0], CPOL);
#elif (SPI1_CLK_POLARITY == SPI1_CLK_POLARITY_HIGH)
    BIT_SET(SPI1->CR[0], CPOL);
#else
    #warning ("Invalid Config Selection!")
    /** @def: Set default value */
    BIT_CLR(SPI1->CR[0], CPOL);
#endif
/**---------------------------------
 * @defgroup: SPI1_CLK_PHASE
 */
#if   (SPI1_CLK_PHASE == SPI1_CLK_PHASE_FIRSTxCLK)
    BIT_CLR(SPI1->CR[0], CPHA);
#elif (SPI1_CLK_PHASE == SPI1_CLK_PHASE_SECONDxCLK)
    BIT_SET(SPI1->CR[0], CPHA);
#else
    #warning ("Invalid Config Selection!")
    /** @def: Set default value */
    BIT_SET(SPI1->CR[0], CPHA);
#endif
 /**---------------------------------
 * @defgroup: SPI1_PRESCALER
 */
    SPI1->CR[0] &= (u32) (~(0b111 << 3u));
    SPI1->CR[0] |= (u32) (SPI1_PRESCALER << 3u);
/**---------------------------------
 * @defgroup: SPI1_MODE
 */
#if   (SPI1_MODE == SPI1_MODE_SLAVE)
    BIT_CLR(SPI1->CR[0], MSTR);
#elif (SPI1_MODE == SPI1_MODE_MASTER)
    BIT_SET(SPI1->CR[0], MSTR);
#else
    #error ("Invalid Config Selection!")
#endif
/**---------------------------------
 * @defgroup: SPI1_DATA_SIZE
 */
#if   (SPI1_DATA_SIZE == SPI1_DATA_SIZE_8)
    BIT_CLR(SPI1->CR[0], DFF);
#elif (SPI1_DATA_SIZE == SPI1_DATA_SIZE_16)
    BIT_SET(SPI1->CR[0], DFF);
#else
    #warning ("Invalid Config Selection!")
    /** @def: Set default value */
     BIT_CLR(SPI1->CR[0], DFF);
#endif
/**---------------------------------
 * @defgroup: SPI1_DATA_ORDER
 */
#if   (SPI1_DATA_ORDER == SPI1_DATA_ORDER_MSB)
    BIT_CLR(SPI1->CR[0], LSBFIRST);
#elif (SPI1_DATA_ORDER == SPI1_DATA_ORDER_LSB)
    BIT_SET(SPI1->CR[0], LSBFIRST);
#else
    #warning ("Invalid Config Selection!")
    /** @def: Set default value */
     BIT_CLR(SPI1->CR[0], LSBFIRST);
#endif
/**---------------------------------
 * @defgroup: SPI1_STATE
 */
#if   (SPI1_STATE == SPI1_STATE_DISABLE)
    BIT_CLR(SPI1->CR[0], SPE);
#elif (SPI1_STATE == SPI1_STATE_ENABLE)
    BIT_SET(SPI1->CR[0], SPE);
#else
    #warning ("Invalid Config Selection!")
    /** @def: Set default value */
     BIT_CLR(SPI1->CR[0], SPE);
#endif
}/** @end SPI1_voidInit */

void SPI1_voidTransmitDataSync(u16 Copy_u16Data)
{
    /* Set the slave select pin low - Start Communication */
	DIO_voidClrPin(SPI1_SLAVE1_PORT, SPI1_SLAVE1_PIN);

    /* Write the data to be transmitted */
    REG_WRT(SPI1->DR, Copy_u16Data);
		
	/* Wait for data to be transmitted */
	while( (0 == BIT_GET(SPI1->SR, TXE)) ) {;}

    /* Wait for data to be received */
    while( (0 == BIT_GET(SPI1->SR, RXNE)) ) {;}

    /* Wait the busy flag */
    while( (1 == BIT_GET(SPI1->SR, BSY)) ) {;}

    /* Set the slave select pin high */
    DIO_voidSetPin(SPI1_SLAVE1_PORT, SPI1_SLAVE1_PIN);
}/** @end SPI1_voidTransmitDataSync - Stop Communication */

void SPI1_voidReceiveDataSync(u16 *Address_u16Data)
{
    /* Wait for data to be received */
    while( (0 == BIT_GET(SPI1->SR, RXNE)) ) {;}

    *Address_u16Data = SPI1->DR;

    /* Wait the busy flag */
    while( (1 == BIT_GET(SPI1->SR, BSY)) ) {;}
}/** @end SPI1_voidReceiveDataSync */

void SPI1_voidSetCallBackFunction(SPI_CallBackFunction_t SPI1_CallBackFunction)
{
    if( (NULL != SPI1_CallBackFunction) )
    {
        G_SPICallBackFunction[SPI1_ID] = SPI1_CallBackFunction;
    }else{;}
}/** @end SPI1_voidSetCallBackFunction */

/**
 * @defgroup: SPI 2 Public Functions
 */
void SPI2_voidInit(void)
{

}/** @end SPI2_voidInit */

void SPI2_voidTransmitDataSync(u8 Copy_u8Data)
{

}/** @end SPI2_voidTransmitDataSync*/

void SPI2_voidReceiveDataSync(u8 Copy_u8Data)
{

} /** @end SPI2_voidReceiveDataSync */

void SPI2_voidSetCallBackFunction(SPI_CallBackFunction_t SPI2_CallBackFunction)
{
    if( (NULL != SPI2_CallBackFunction) )
    {
        G_SPICallBackFunction[SPI2_ID] = SPI2_CallBackFunction;
    }else{;}
}/** @end SPI2_voidSetCallBackFunction */

/*									 
-------------------------------------------------------------- 
!-				 Private Functions Implementation 
-------------------------------------------------------------- 
*/ 

void SPI1_IRQHandler(void)
{

}/** @end SPI1_IRQHandler */

void SPI2_IRQHandler(void)
{

}/** @end SPI2_IRQHandler */

void SPI3_IRQHandler(void)
{

}/** @end SPI3_IRQHandler */
