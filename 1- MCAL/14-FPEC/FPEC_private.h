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
#ifndef _FPEC_PRIVATE_H
#define _FPEC_PRIVATE_H


/*
----------------------------------------------------------------------------------------------------
!-                                          REGISTER FILE
----------------------------------------------------------------------------------------------------
*/

typedef struct
{
    u32 volatile ACR;
    u32 volatile KEYR;
    u32 volatile OPTKEYR;
    u32 volatile SR;
    u32 volatile CR;
    u32 volatile AR;
    u32 volatile OBR;
    u32 volatile WRPR;
}ST_FPECRegisters_t;

#define FPEC   ( (ST_FPECRegisters_t volatile * const) (0x40022000) )

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/

typedef enum EN_FPECerrorState_t
{
    FLASH_WRITE_OK,
    HWORD_WRITE_OK,
    PAGE_ERASE_OK,
    MASS_ERASE_OK,
    NOK
}EN_FPECerrorState_t;

/** @defgroup: Keys used */
#define FPEC_ACCESS_KEY1    (0x45670123U)
#define FPEC_ACCESS_KEY2    (0xCDEF89ABU)
#define FPEC_ACCESS_RDPRT   (0x00A5U)

#define SET_MEM16(ADDRESS)         ( *((u16 volatile *) (ADDRESS)) )
#define GET_MEM16(ADDRESS)         ( *((u16 volatile *) (ADDRESS)) )
#define WRT_MEM16(ADDRESS, DATA)   ( SET_MEM16(ADDRESS) = (DATA))
#define DATA_ASSERT(ADDRESS, DATA) ( (GET_MEM16(ADDRESS) == (DATA)) )

enum ACR_BITS
{
    LATENCY0,
    LATENCY1,
    LATENCY2,
    HLFCYA,
    PRFTBE,
    PRFTBS
};

enum SR_BITS
{
    BSY      = 0,
    PGERR    = 1,
    WRPRTERR = 2,
    EOP      = 3
};

enum CR_BITS
{
    PG      = 0,
    PER     = 1,
    MER     = 2,
    OPTPG   = 4,
    OPTER   = 5,
    STRT    = 6,
    LOCK    = 7,
    OPTWRE  = 9,
    ERRIE   = 10,
    EOPIE   = 12
};

enum OBR_BITS
{
    OPTERR     = 0,
    RDPRT      = 1,
    WDG_SW     = 2,
    nRST_STOP  = 3,
    nRST_STDBY = 4
};

/** @defgroup: FPEC_LATENCY */
#define FPEC_LATENCY_ZERO (0u)
#define FPEC_LATENCY_ONE  (1u)
#define FPEC_LATENCY_TWO  (2u)

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

//static void voidUnlockFPEC(void);

//static EN_FPECerrorState_t
//FPEC_voidWriteHalfWord(u32 Copy_u32MemoryAddress, u16 Copy_u16Data);

#endif /* _FPEC_PRIVATE_H */
