/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    17 march 2023	 		           		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 WATCHDOG								*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef _WATCHDOG_CONFIG_H
#define _WATCHDOG_CONFIG_H

/**
 * @brief: The Reload value calculation
 *       TIME(ms) * 32000
 *  RL = ----------------
 *       4 * 2^PS * 1000
 */
/**
 * @brief: The prescaler value for the counter
 * @def: Configuration Parameters
 * - IWDT_PRESCALER_4
 * - IWDT_PRESCALER_8
 * - IWDT_PRESCALER_16
 * - IWDT_PRESCALER_32
 * - IWDT_PRESCALER_64
 * - IWDT_PRESCALER_128
 * - IWDT_PRESCALER_256
 */
#define IWDT_PRESCALER_VALUE    (IWDT_PRESCALER_8)


/**
 * @brief: The Reload value calculation
 *               4096 * 2^PS 
 *  t_WWD(ms) = ------------- * (T[5:0]+1)
 *               F_PCLK(hz)
 *
 */
 
/**
 * @brief: The prescaler value for the counter
 * @def: Configuration Parameters
 * - WWDT_PRESCALER_1 
 * - WWDT_PRESCALER_2 
 * - WWDT_PRESCALER_4 
 * - WWDT_PRESCALER_8 
 */
#define WWDT_PRESCALER_VALUE    (WWDT_PRESCALER_8)

#endif /* _WATCHDOG_CONFIG_H */
