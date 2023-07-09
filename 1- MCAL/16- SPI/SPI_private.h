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
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef __SPI_SPI_PRIVATE_H__
#define __SPI_SPI_PRIVATE_H__


/*									 
-------------------------------------------------------------- 
!-				 Register File 
-------------------------------------------------------------- 
*/ 

typedef struct
{
    u32 volatile CR[2u];
    u32 volatile SR;
    u32 volatile DR;
    u32 volatile CRCPR;
    u32 volatile RXCRCR;
    u32 volatile TXCRCR;
    u32 volatile I2SCFGR;
    u32 volatile I2SPR;
}ST_SPIRegisters_t;

#define SPI1 ( (ST_SPIRegisters_t volatile * const) (0x40013000) )
#define SPI2 ( (ST_SPIRegisters_t volatile * const) (0x40003800) )

/*									 
-------------------------------------------------------------- 
!-				 Private Defines 
-------------------------------------------------------------- 
*/ 

#define NUM_OF_SPI 	(2u)
typedef void (*SPI_CallBackFunction_t)(u16);

enum CR1_BITS
{
    CPHA         = 0,
    CPOL         = 1,
    MSTR         = 2,
    BR0          = 3,
    BR1          = 4,
    BR2          = 5,
    SPE          = 6,
    LSBFIRST     = 7,
    SSI          = 8,
    SSM          = 9,
    RXONLY       = 10,
    DFF          = 11,
    CRCNEXT      = 12,
    CRCEN        = 13,
    BIDIOE       = 14,
    BIDIMODE     = 15
};

enum CR2_BITS
{
    RXDMAEN = 0,
    TXDMAEN = 1,
    SSOE    = 2,
    ERRIE   = 3,
    RXNEIE  = 4,
    TXEIE   = 5
};

enum SR_BITS
{
    RXNE     = 0,
    TXE      = 1,
    CHSIDE   = 2,
    UDR      = 3,
    CRCERR   = 4,
    MODF     = 5,
    OVR      = 6,
    BSY      = 7
};

enum I2SCFGR_BITS
{
    CHLEN    = 0,
    DATLEN   = 1,
    CKPOL    = 2,
    I2SSTD   = 4,
    PCMSY    = 6,
    I2SCFG   = 7,
    I2SE     = 8,
    I2SMOD   = 9
};

enum I2SPR_BITS
{
    ODD   = 8,
    MCKOE = 9
};

/**=================================================
 * @defgroup: SPI_1 Configuration Parameters
 *==================================================
 */
/** @defgroup: SPI1_CLK_POLARITY */
#define SPI1_CLK_POLARITY_HIGH      (0u)
#define SPI1_CLK_POLARITY_LOW       (1u)
/** @defgroup: SPI1_CLK_PHASE */
#define SPI1_CLK_PHASE_FIRSTxCLK    (0u)
#define SPI1_CLK_PHASE_SECONDxCLK   (1u)
/** @defgroup: SPI1_PRESCALER */
#define SPI1_PRESCALER_DIV2         (0u)
#define SPI1_PRESCALER_DIV4         (1u)
#define SPI1_PRESCALER_DIV8         (2u)
#define SPI1_PRESCALER_DIV16        (3u)
#define SPI1_PRESCALER_DIV32        (4u)
#define SPI1_PRESCALER_DIV64        (5u)
#define SPI1_PRESCALER_DIV128       (6u)
#define SPI1_PRESCALER_DIV256       (7u)
/** @defgroup: SPI1_MODE */
#define SPI1_MODE_MASTER            (0u)
#define SPI1_MODE_SLAVE             (1u)
/** @defgroup: SPI1_DATA_SIZE */
#define SPI1_DATA_SIZE_8            (0u)
#define SPI1_DATA_SIZE_16           (1u)
/** @defgroup: SPI1_DATA_ORDER */
#define SPI1_DATA_ORDER_MSB         (0u)
#define SPI1_DATA_ORDER_LSB         (1u)
/** @defgroup: SPI1_STATE */
#define SPI1_STATE_DISABLE          (0u)
#define SPI1_STATE_ENABLE           (1u)
/**=================================================
 * @defgroup: SPI_2 Configuration Parameters
 *==================================================
 */

/**=================================================
 * @defgroup: SPI_3 Configuration Parameters
 *==================================================
 */

/*									 
-------------------------------------------------------------- 
!-				 Private Functions Declaration 
-------------------------------------------------------------- 
*/ 


#endif /* __SPI_SPI_PRIVATE_H__ */
