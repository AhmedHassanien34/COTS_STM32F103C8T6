/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    18 February 2023	            		*************/
/**************************		Layer:   HAL								   	*************/
/**************************		SWC:	 LED_MATRIX								*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef LEDMAT_CONFIG_H
#define LEDMAT_CONFIG_H

/* Configure PINS And PORT For ROW */
#define LEDMAT_ROW0_PIN				GPIOA,0
#define LEDMAT_ROW1_PIN				GPIOA,1
#define LEDMAT_ROW2_PIN				GPIOA,2
#define LEDMAT_ROW3_PIN				GPIOA,3
#define LEDMAT_ROW4_PIN				GPIOA,4
#define LEDMAT_ROW5_PIN				GPIOA,5
#define LEDMAT_ROW6_PIN				GPIOA,6
#define LEDMAT_ROW7_PIN				GPIOA,7

/* Configure PINS And PORT For COLUMN */
#define LEDMAT_COL0_PIN				GPIOB,0
#define LEDMAT_COL1_PIN				GPIOB,1
#define LEDMAT_COL2_PIN				GPIOB,5
#define LEDMAT_COL3_PIN				GPIOB,6
#define LEDMAT_COL4_PIN				GPIOB,7
#define LEDMAT_COL5_PIN				GPIOB,8
#define LEDMAT_COL6_PIN				GPIOB,9
#define LEDMAT_COL7_PIN				GPIOB,10

/* Configure Frame Move Time (in ms) */
#define LEDMAT_FRAME_MOVE_TIME		200



#endif
/********************************************************************************************/
/* END OF FILE: LEDMAT_config.h                                                             */
/********************************************************************************************/
