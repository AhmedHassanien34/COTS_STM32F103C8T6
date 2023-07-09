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
#ifndef CAN_CONFIG_H
#define CAN_CONFIG_H



/** CAN  configuration structure definition **/

 /*!< This parameters can be set to ENABLE or DISABLE. */
#define AutoRetransmission           ENABLE
#define AutoBussOff                  ENABLE
#define AutoWakeUp                   DISABLE
#define TimeTriggeredMode            DISABLE
#define ReceiveFifoLocked            DISABLE
#define TransmitFifoPriority         DISABLE

/********** option : 
 * 					 CAN_MODE_NORMAL
 * 					 CAN_MODE_LOOPBACK
 * 					 CAN_MODE_SILENT
 * 					 CAN_MODE_SILENT_LOOPBACK
 	 	 	 	 	 	 	 	 	 	 	 	 **********************************/
#define MODE			 CAN_MODE_NORMAL
/********** option : CAN_50KBPS
 * 					 CAN_100KBPS
 * 					 CAN_125KBPS
 * 					 CAN_250KBPS
 * 					 CAN_500KBPS
 * 					 CAN_800KBPS,
 * 					 CAN_1MBPS
 	 	 	 	 	 	 	 	 	 	 	 	 *************************/
#define BOUDRATE		CAN_500KBPS


#endif /* CAN_CONFIG_H */
