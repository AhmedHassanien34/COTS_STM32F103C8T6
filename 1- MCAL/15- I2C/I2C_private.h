/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    23 MARCH 2023	    	        		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 I2C									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef _I2C_PRIVATE_H
#define _I2C_PRIVATE_H


/*
----------------------------------------------------------------------------------------------------
!-                                          REGISTER FILE
----------------------------------------------------------------------------------------------------
*/

#define I2C1_BASE_ADDRESS  ( (0x40015800) )
#define I2C2_BASE_ADDRESS  ( (0x40015400) )

typedef struct
{
    u32 volatile CR[2];
    u32 volatile OAR1;
    u32 volatile OAR2;
    u32 volatile DR;
    u32 volatile SR[2];
    u32 volatile CCR;
    u32 volatile TRISE;
}ST_I2C_REGISTERS_t;

#define I2C1   ( ((ST_I2C_REGISTERS_t volatile *) (I2C1_BASE_ADDRESS)) )
#define I2C2   ( ((ST_I2C_REGISTERS_t volatile *) (I2C2_BASE_ADDRESS)) )

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/

#define NUM_OF_I2C 2

typedef void (*I2C_CallBackFunctionFormat)(void);

/** @defgroup: Registers bits */
enum I2C_CR1
{
    PE          = 0,
    SMBUS       = 1,
    SMBTYPE     = 3,
    ENARP       = 4,
    ENPEC       = 5,
    ENGC        = 6,
    NOSTRETCH   = 7,
    START       = 8,
    STOP        = 9,
    ACK         = 10,
    POS         = 11,
    PEC         = 12,
    ALERT       = 13,
    SWRST       = 15
};

enum I2C_CR2
{
    FREQS   = 0,
    FREQE   = 5,
    ITERREN = 8,
    ITEVTEN = 9,
    ITBUFEN = 10,
    DMAEN   = 11,
    LAST    = 12
};

enum I2C_OAR1
{
    ADD0    = 0,
    ADDS    = 1,    /** @note: Address Start bit */
    ADDE    = 7,    /** @note: Address End bit */
    ADD8    = 8,
    ADD9    = 9,
    ADDMODE = 15
};

enum I2C_OAR2
{
    ENDUAL = 0,
    ADD2S   = 1,    /** @note: Address Start bit */
    ADD2E   = 7,    /** @note: Address End bit */
};

enum I2C_SR1
{
    SB          = 0,
    ADDR        = 1,
    BTF         = 2,
    ADD10       = 3,
    STOPF       = 4,
    RXNE        = 6,
    TXE         = 7,
    BERR        = 8,
    ARLO        = 9,
    AF          = 10,
    OVR         = 11,
    PECERR      = 12,
    TIMEOUT     = 13,
    SMBALERT    = 14
};

enum I2C_SR2
{
    MSL           = 0,
    BUSY          = 1,
    TRA           = 2,
    GENCALL       = 4,
    SMBDEFAULT    = 5,
    SMBHOST       = 6,
    DUALF         = 7,
    PECS          = 8,
    PECE          = 9
};

enum I2C_CCR
{
    CCRS = 0,
    CCRE = 11,
    DUTY = 14,
    F_S  = 15
};

enum I2C_TRIS
{
    TRISES  = 0,
    TRISEE  = 5
};


/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/
/** @defgroup: User configuration functions */
static void voidSetState(u8 Copy_u8I2Cid, u8 Copy_u8State);
static void voidSetBusSpeed(u8 Copy_u8I2Cid, u8 Copy_u8Speed);
static void voidSetMode(u8 Copy_u8I2Cid, u8 Copy_u8Mode);
static void voidSetAddressMode(u8 Copy_u8I2Cid, u8 Copy_u8Mode);
static void voidSetSpeedMode(u8 Copy_u8I2Cid, u8 Copy_u8Mode);
static void voidSetACK(u8 Copy_u8I2Cid, u8 Copy_u8State);
static void voidSetPEC(u8 Copy_u8I2Cid, u8 Copy_u8State);
static void voidSetARP(u8 Copy_u8I2Cid, u8 Copy_u8State);
static void voidSetSTRETCH(u8 Copy_u8I2Cid, u8 Copy_u8State);
/** @defgroup: Developer configuration functions */
static void voidSetCCR(u8 Copy_u8I2Cid, u8 Copy_u8Mode);
static void voidSetTRISE(u8 Copy_u8I2Cid, u8 Copy_u8Mode);
static void voidSetConfigMode(u8 Copy_u8I2Cid, u8 Copy_u8Mode);

#endif /* _USART_PRIVATE_H */
