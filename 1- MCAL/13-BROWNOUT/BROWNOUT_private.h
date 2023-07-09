/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    19 MARCH 2023	    	        		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 BROWNOUT								*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef _BROWNOUT_PRIVATE_H
#define _BROWNOUT_PRIVATE_H


/*
----------------------------------------------------------------------------------------------------
!-                                          REGISTER FILE
----------------------------------------------------------------------------------------------------
*/

typedef struct
{
    u32 volatile CR;
    u32 volatile CSR;
}ST_PWRRegister_t;

#define PWR ( (ST_PWRRegister_t volatile * const) (0x40007000) )

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/

enum PWRCR_BITS
{
    LPDS,
    PDDS,
    CWUF,
    CSBF,
    PVDE,
    PLS0,
    PLS1,
    DBP
};

enum PWRCSR_BITS
{
    WUF  = 0,
    SBF  = 1,
    PVD  = 2,
    EWUP = 8
};

/** @defgroup: BROWNOUT voltage detect threshold */
#define BROWNOUT_THRESHOLD_2v2  (000u)
#define BROWNOUT_THRESHOLD_2v3  (001u)
#define BROWNOUT_THRESHOLD_2v4  (010u)
#define BROWNOUT_THRESHOLD_2v5  (011u)
#define BROWNOUT_THRESHOLD_2v6  (100u)
#define BROWNOUT_THRESHOLD_2v7  (101u)
#define BROWNOUT_THRESHOLD_2v8  (110u)
#define BROWNOUT_THRESHOLD_2v9  (111u)
/** @defgroup: BROWNOUT State */
#define BROWNOUT_DISABLE        (0u)
#define BROWNOUT_ENABLE         (1u)
/** @defgroup: BROWNOUT Mode */
#define BROWNOUT_STOP_MODE      (0u)
#define BROWNOUT_STANDBY_MODE   (1u)
/** @defgroup: Set the regulator mode */
#define BROWNOUT_REGULATOR_ON   (0u)
#define BROWNOUT_REGULATOR_LOW  (1u)

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/



#endif /* _BROWNOUT_PRIVATE_H */
