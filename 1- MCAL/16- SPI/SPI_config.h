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
#ifndef __SPI_SPI_CONFIG_H__
#define __SPI_SPI_CONFIG_H__


/*									 
-------------------------------------------------------------- 
!-				 Available Options 
-------------------------------------------------------------- 
*/ 

/**=================================================
 * @defgroup: SPI_1 Configuration Parameters
 *=================================================
 */
 
 // TODO: To be optimized
 /** @defgroup: Slaves Select Pins */
 #define SPI1_SLAVE1_PORT   (PORTA_ID)
 #define SPI1_SLAVE1_PIN    (PIN_0)

/**
 * @brief: CLock bus idle state
 * @def: Configuration Parameters
 * - SPI1_CLK_POLARITY_HIGH
 * - SPI1_CLK_POLARITY_LOW
 * -------------------------------------------------
 */
#define SPI1_CLK_POLARITY       (SPI1_CLK_POLARITY_LOW)
/**-------------------------------------------------
 * @brief:  CLock bus w/r
 * @def: Configuration Parameters
 * - SPI1_CLK_PHASE_FIRSTxCLK
 *------>@note: Read then Write.
 * - SPI1_CLK_PHASE_SECONDxCLK
 *------>@note: Write then Read.
 * -------------------------------------------------
 */
#define SPI1_CLK_PHASE          (SPI1_CLK_PHASE_SECONDxCLK)
/**-------------------------------------------------
 * @brief: Periphral prescaler
 * @def: Configuration Parameters
 * - SPI1_PRESCALER_DIV2
 * - SPI1_PRESCALER_DIV4
 * - SPI1_PRESCALER_DIV8
 * - SPI1_PRESCALER_DIV16
 * - SPI1_PRESCALER_DIV32
 * - SPI1_PRESCALER_DIV64
 * - SPI1_PRESCALER_DIV128
 * - SPI1_PRESCALER_DIV256
 * -------------------------------------------------
 */
#define SPI1_PRESCALER          (SPI1_PRESCALER_DIV2)
/**-------------------------------------------------
 * @brief: Device N2N Relation
 * @def: Configuration Parameters
 * - SPI1_MODE_MASTER
 * - SPI1_MODE_SLAVE
 * -------------------------------------------------
 */
#define SPI1_MODE               (SPI1_MODE_MASTER)
/**-------------------------------------------------
 * @brief: CLock bus idle state
 * @def: Configuration Parameters
 * - SPI1_DATA_SIZE_8
 * - SPI1_DATA_SIZE_16
 * -------------------------------------------------
 */
#define SPI1_DATA_SIZE          (SPI1_DATA_SIZE_8)
/**-------------------------------------------------
 * @brief: Transmitting data order
 * @def: Configuration Parameters
 * - SPI1_DATA_ORDER_MSB
 * - SPI1_DATA_ORDER_LSB
 * -------------------------------------------------
 */
#define SPI1_DATA_ORDER         (SPI1_DATA_ORDER_MSB)
/**-------------------------------------------------
 * @brief: Device peripheral state
 * @def: Configuration Parameters
 * - SPI1_STATE_DISABLE
 * - SPI1_STATE_ENABLE
 * -------------------------------------------------
 */
#define SPI1_STATE              (SPI1_STATE_ENABLE)

/**=================================================
 * @defgroup: SPI_2 Configuration Parameters
 *=================================================
 */

// TODO
						
#endif /* __SPI_SPI_CONFIG_H__ */
