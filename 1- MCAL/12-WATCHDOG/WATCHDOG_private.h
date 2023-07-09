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
#ifndef _WATCHDOG_PRIVATE_H
#define _WATCHDOG_PRIVATE_H


/*
----------------------------------------------------------------------------------------------------
!-                                          REGISTER FILE
----------------------------------------------------------------------------------------------------
*/

typedef struct
{
    u32 volatile KR;
    u32 volatile PR;
    u32 volatile RLR;
    u32 volatile SR;
}ST_IWDTRegisters_t;

#define IWDT    ( (ST_IWDTRegisters_t volatile * const) (0x40003000) )

typedef struct
{
    u32 volatile CR;
    u32 volatile CFR;
    u32 volatile SR;
}ST_WWDTRegisters_t;

#define WWDT    ( (ST_WWDTRegisters_t volatile * const) (0x40002C00) )

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/
#define WWDT_EQ(millis, mul) ( (((millis * 36000.0)/(4096 * mul))-1) )

/** @defgroup: IWDT Defines */
#define IWDT_ACCESS_KEY     (0x5555U)
#define IWDT_START_KEY      (0xCCCCU)
#define IWDT_STOP_KEY       (0xAAAAU)

/** @defgroup: IWDT Prescaler */
#define IWDT_PRESCALER_4    (0x00U)
#define IWDT_PRESCALER_8    (0x01U)
#define IWDT_PRESCALER_16   (0x02U)
#define IWDT_PRESCALER_32   (0x03U)
#define IWDT_PRESCALER_64   (0x04U)
#define IWDT_PRESCALER_128  (0x05U)
#define IWDT_PRESCALER_256  (0x06U)

/** @defgroup: WWDT Prescaler */
#define WWDT_PRESCALER_1    (0x00U)
#define WWDT_PRESCALER_2    (0x01U)
#define WWDT_PRESCALER_4    (0x02U)
#define WWDT_PRESCALER_8    (0x03U)


/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/



#endif /* _WATCHDOG_PRIVATE_H */
