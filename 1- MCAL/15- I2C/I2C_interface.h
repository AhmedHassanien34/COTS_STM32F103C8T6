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
#ifndef _I2C_INTERFACE_H
#define _I2C_INTERFACE_H

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/
/** @defgroup frequency bits */
#define I2C_CLOCK_2MHz      ( (u32)(0x02) )
#define I2C_CLOCK_3MHz      ( (u32)(0x03) )
#define I2C_CLOCK_4MHz      ( (u32)(0x04) )
#define I2C_CLOCK_5MHz      ( (u32)(0x05) )
#define I2C_CLOCK_6MHz      ( (u32)(0x06) )
#define I2C_CLOCK_7MHz      ( (u32)(0x07) )
#define I2C_CLOCK_8MHz      ( (u32)(0x08) )
#define I2C_CLOCK_9MHz      ( (u32)(0x09) )
#define I2C_CLOCK_10MHz     ( (u32)(0x0A) )
#define I2C_CLOCK_11MHz     ( (u32)(0x0B) )
#define I2C_CLOCK_12MHz     ( (u32)(0x0C) )
#define I2C_CLOCK_13MHz     ( (u32)(0x0D) )
#define I2C_CLOCK_14MHz     ( (u32)(0x0E) )
#define I2C_CLOCK_15MHz     ( (u32)(0x0F) )
#define I2C_CLOCK_16MHz     ( (u32)(0x10) )
#define I2C_CLOCK_17MHz     ( (u32)(0x11) )
#define I2C_CLOCK_18MHz     ( (u32)(0x12) )
#define I2C_CLOCK_19MHz     ( (u32)(0x13) )
#define I2C_CLOCK_20MHz     ( (u32)(0x14) )
#define I2C_CLOCK_21MHz     ( (u32)(0x15) )
#define I2C_CLOCK_22MHz     ( (u32)(0x16) )
#define I2C_CLOCK_23MHz     ( (u32)(0x17) )
#define I2C_CLOCK_24MHz     ( (u32)(0x18) )
#define I2C_CLOCK_25MHz     ( (u32)(0x19) )
#define I2C_CLOCK_26MHz     ( (u32)(0x1A) )
#define I2C_CLOCK_27MHz     ( (u32)(0x1B) )
#define I2C_CLOCK_28MHz     ( (u32)(0x1C) )
#define I2C_CLOCK_29MHz     ( (u32)(0x1D) )
#define I2C_CLOCK_30MHz     ( (u32)(0x1E) )
#define I2C_CLOCK_31MHz     ( (u32)(0x1F) )
#define I2C_CLOCK_32MHz     ( (u32)(0x20) )
#define I2C_CLOCK_34MHz     ( (u32)(0x21) )
#define I2C_CLOCK_35MHz     ( (u32)(0x22) )
#define I2C_CLOCK_36MHz     ( (u32)(0x23) )
#define I2C_CLOCK_37MHz     ( (u32)(0x24) )
#define I2C_CLOCK_38MHz     ( (u32)(0x25) )
#define I2C_CLOCK_39MHz     ( (u32)(0x26) )
#define I2C_CLOCK_40MHz     ( (u32)(0x27) )
#define I2C_CLOCK_41MHz     ( (u32)(0x28) )
#define I2C_CLOCK_42MHz     ( (u32)(0x29) )
#define I2C_CLOCK_43MHz     ( (u32)(0x2A) )
#define I2C_CLOCK_44MHz     ( (u32)(0x2B) )
#define I2C_CLOCK_45MHz     ( (u32)(0x2C) )
#define I2C_CLOCK_46MHz     ( (u32)(0x2D) )
#define I2C_CLOCK_47MHz     ( (u32)(0x2E) )
#define I2C_CLOCK_48MHz     ( (u32)(0x2F) )
#define I2C_CLOCK_49MHz     ( (u32)(0x30) )
#define I2C_CLOCK_50MHz     ( (u32)(0x31) )

#define I2C_CLOCK_MIN   (I2C_CLOCK_2MHz)
#define I2C_CLOCK_MAX   (I2C_CLOCK_50MHz)

enum I2C_ADDRESS_SET
{
    I2C_ADDRESS_0    = 0b00000000,
    I2C_ADDRESS_1    = 0b00000010,
    I2C_ADDRESS_2    = 0b00000100,
    I2C_ADDRESS_3    = 0b00000110,
    I2C_ADDRESS_4    = 0b00001000,
    I2C_ADDRESS_5    = 0b00001010,
    I2C_ADDRESS_6    = 0b00001100,
    I2C_ADDRESS_7    = 0b00001110,
    I2C_ADDRESS_8    = 0b00010000,
    I2C_ADDRESS_9    = 0b00010010,
    I2C_ADDRESS_10   = 0b00010100,
    I2C_ADDRESS_11   = 0b00010110
    /** @todo: to be continued if needed */
};

enum I2C_ID
{
    I2C1_ID,
    I2C2_ID
};

enum I2C_STATE
{
    I2C_DISABLE,
    I2C_ENABLE
};

enum I2C_MODE
{
    I2C_MASTER,
    I2C_SLAVE,
    I2C_SMBUS,
    I2C_PMBUS
};

enum I2C_ADDRESS_MODE
{
    I2C_7BIT_ADDR,
    I2C_10BIT_ADDR
};

enum I2C_SPEED_MODE
{
    I2C_SLOW_MODE,
    I2C_FAST_MODE
};

enum I2C_CONFIG_MODE
{
    I2C_WRITE,
    I2C_READ
};

enum I2C_ACK_STATE
{
    I2C_ACK_DISABLE,
    I2C_ACK_ENABLE
};

enum I2C_PEC_STATE
{
    I2C_PEC_DISABLE,
    I2C_PEC_ENABLE
};

enum I2C_SSTRETCH_STATE
{
    I2C_SSTRETCH_DISABLE,
    I2C_SSTRETCH_ENABLE
};

enum I2C_ARP_STATE
{
    I2C_ARP_DISABLE,
    I2C_ARP_ENABLE
};

/** @todo to be implemented */
typedef struct __attribute__((__packed__))
{
    u8 I2C_ID;
    u8 BUS_SPEED;
    u8 I2C_MODE;
    u8 ADDR_MODE;
    u8 SPEED_MODE;
    u8 ACK;
    u8 PEC;
    u8 ARP;
    u8 STRETCH;
}ST_I2CConfig_t;

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

void I2C_voidInit(const ST_I2CConfig_t *I2CConfig);

#endif /* _USART_INTERFACE_H */
