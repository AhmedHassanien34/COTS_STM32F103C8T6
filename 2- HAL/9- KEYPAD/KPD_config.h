/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    5 APRIL 2023	 		           		*************/
/**************************		Layer:   HAL								   	*************/
/**************************		SWC:	 KEYPAD									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_


#define KPD_PORT   GPIOA

#define   KPD_COLUMN0_PIN         GPIO_PIN0
#define   KPD_COLUMN1_PIN         GPIO_PIN0
#define   KPD_COLUMN2_PIN         GPIO_PIN2
#define   KPD_COLUMN3_PIN         GPIO_PIN3

#define   KPD_ROW0_PIN            GPIO_PIN4
#define   KPD_ROW1_PIN            GPIO_PIN5
#define   KPD_ROW2_PIN            GPIO_PIN6
#define   KPD_ROW3_PIN            GPIO_PIN7


#define KPD_ARR_VAL                  {{1,2,3,4},{5,2,3,4},{6,2,3,4},{13,2,3,4}}





#define KPD_NO_PRESSED_KEY       0xff




#endif /* KPD_CONFIG_H_ */
