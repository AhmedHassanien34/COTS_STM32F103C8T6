/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    27 MARCH 2023	    	        		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 CAN									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef CAN_PRIVATE_H
#define CAN_PRIVATE_H

typedef void (*CAN_Interrupt_Callbacks)(void);/**  CAN Operating Mode **/


#define CAN_MODE_NORMAL           			  ((u32)(0x0))                        			       /*!< Normal mode   */
#define CAN_MODE_LOOPBACK        		 	  ((u32)(0x1<<30))                					   /*!< Loopback mode BIT 30 < 0x40000000 > */
#define CAN_MODE_SILENT            			  ((u32)(0x1<<31))                					   /*!< Silent mode  BIT 31 < 0x80000000 > */
#define CAN_MODE_SILENT_LOOPBACK  			  ((u32)(CAN_MODE_LOOPBACK | CAN_MODE_SILENT)) 	 	   /*!< Loopback combined with silent mode */


/*******************   BoudRate Definition     ***********************/
enum BITRATE{CAN_50KBPS, CAN_100KBPS, CAN_125KBPS, CAN_250KBPS, CAN_500KBPS, CAN_800KBPS, CAN_1MBPS};

typedef const struct
{
	u8 TS2;
	u8 TS1;
	u8 BRP;
} CAN_BitTimingConfig;

/******** BoudRate value rating to table at web site {http://www.bittiming.can-wiki.info/}
 * 1. select ST Microelectronics bxCAN
 * 2. put freq with 36Mhz (APB1 freq)
 * 3. click Request Table						        ***********************************/
CAN_BitTimingConfig CAN_bitRateConfig[7] = {{2, 13, 45}, {2, 15, 20}, {2, 13, 18}, {2, 13, 9}, {2, 15, 4},{2, 12, 3}, {2, 15, 2}};


/*******************   Register Definition     ***********************/

/** Controller Area Network TxMailBox **/

typedef struct
{
  volatile u32 TIR;
  volatile u32 TDTR;
  volatile u32 TDLR;
  volatile u32 TDHR;

} CAN_TxMailBox_TypeDef;

/** Controller Area Network FIFOMailBox **/

typedef struct
{
  volatile u32 RIR;
  volatile u32 RDTR;
  volatile u32 RDLR;
  volatile u32 RDHR;
} CAN_FIFOMailBox_TypeDef;

/** Controller Area Network FilterRegister **/

typedef struct
{
  volatile u32 FR1;
  volatile u32 FR2;
} CAN_FilterRegister_TypeDef;

/** Controller Area Network  **/
typedef struct
{
	volatile u32 MCR;
	volatile u32 MSR;
	volatile u32 TSR;
	volatile u32 RF0R;
	volatile u32 RF1R;
	volatile u32 IER;
	volatile u32 ESR;
	volatile u32 BTR;
	u32 RESERVED0[88];
	CAN_TxMailBox_TypeDef TxMailBox[3];
    CAN_FIFOMailBox_TypeDef FIFOMailBox[2];
    u32  RESERVED1[12];
    volatile u32 FMR;
    volatile u32 FM1R;
    u32  RESERVED2;
    volatile u32 FS1R;
    u32  RESERVED3;
    volatile u32 FFA1R;
    u32  RESERVED4;
    volatile u32 FA1R;
    u32  RESERVED5[8];
    CAN_FilterRegister_TypeDef FilterBankRegister[14];

}CAN_t;

/*******************   BASE Address Definition    *********************/
#define CAN_BASE_ADDRESS	0x40006400 		//define the boundary address of CAN
#define CAN			((volatile CAN_t *) CAN_BASE_ADDRESS)





#endif /* CAN_PRIVATE_H */
