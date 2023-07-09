/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    21 MARCH 2023	    	        		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 FPEC									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef _FPEC_CONFIG_H
#define _FPEC_CONFIG_H

/*
----------------------------------------------------------------------------------------------------
!-                                      AVAILABLE OPTIONS
----------------------------------------------------------------------------------------------------
*/

/**
 * @brief: Genearl notes about FPEC
 * - Writing to the flash: By page.
 * - Erasing the flash: By Sector. (Multiple number of bytes)
 */

/**
 * @brief: Periphral latency ratio
 * @defgroup: Configuration Parameters
 *  @arg: FPEC_LATENCY_ZERO - (0 < SYS_CLK < 24)
 *  @arg: FPEC_LATENCY_ONE  - (24 < SYS_CLK < 48)
 *  @arg: FPEC_LATENCY_TWO  - (48 < SYS_CLK < 72)
 */
#define FPEC_LATENCY                (FPEC_LATENCY_ZERO)
/**
 * @brief: Flash memory page size.
 */
#define MEM_PAGE_SIZE               (1024u)

/**
 * @brief: Start address of the flash memory
 */
#define FLASH_MEM_START_ADDRESS     (0x08000000UL)

#endif /* _FPEC_CONFIG_H */









