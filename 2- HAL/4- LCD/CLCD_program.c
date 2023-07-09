/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    19 February 2023	            		*************/
/**************************		Layer:   HAL								   	*************/
/**************************		SWC:	 CLCD									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "STK_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"




void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , LOW);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , LOW);

	MSTK_voidSetBusyWaitUS(10);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , HIGH);

	MSTK_voidSetBusyWaitUS(5);

	GPIOA_ODR &= 0xff0f;
	GPIOA_ODR |= (Copy_u8Command & 0x00f0);

	MSTK_voidSetBusyWaitUS(10);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , LOW);

	MSTK_voidSetBusyWaitUS(20);


	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , HIGH);

	MSTK_voidSetBusyWaitUS(5);

	GPIOA_ODR &= 0xff0f;
	GPIOA_ODR |= ((Copy_u8Command << 4) & 0x00f0);

	MSTK_voidSetBusyWaitUS(10);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , LOW);



}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , HIGH);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , LOW);

	MSTK_voidSetBusyWaitUS(10);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , HIGH);

	MSTK_voidSetBusyWaitUS(5);

	GPIOA_ODR &= 0xff0f;
	GPIOA_ODR |= (Copy_u8Data & 0x00f0);

	MSTK_voidSetBusyWaitUS(10);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , LOW);

	MSTK_voidSetBusyWaitUS(20);


	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , HIGH);

	MSTK_voidSetBusyWaitUS(5);

	GPIOA_ODR &= 0xff0f;
	GPIOA_ODR |= ((Copy_u8Data << 4) & 0x00f0);

	MSTK_voidSetBusyWaitUS(10);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , LOW);

}

void CLCD_voidInit(void)
{
	MSTK_voidSetBusyWaitMS(20);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , LOW);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , LOW);

	MSTK_voidSetBusyWaitUS(10);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , HIGH);

	MSTK_voidSetBusyWaitUS(5);

	GPIOA_ODR &= 0xff0f;
	GPIOA_ODR |= 0x30;

	MSTK_voidSetBusyWaitUS(10);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , LOW);


	MSTK_voidSetBusyWaitMS(10);



	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , LOW);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , LOW);

	MSTK_voidSetBusyWaitUS(10);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , HIGH);

	MSTK_voidSetBusyWaitUS(5);

	GPIOA_ODR &= 0xff0f;
	GPIOA_ODR |= 0x30;

	MSTK_voidSetBusyWaitUS(10);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , LOW);


	MSTK_voidSetBusyWaitMS(1);



	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , LOW);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , LOW);

	MSTK_voidSetBusyWaitUS(10);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , HIGH);

	MSTK_voidSetBusyWaitUS(5);

	GPIOA_ODR &= 0xff0f;
	GPIOA_ODR |= 0x30;

	MSTK_voidSetBusyWaitUS(10);
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , LOW);




	MSTK_voidSetBusyWaitMS(1);



	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , LOW);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , LOW);

	MSTK_voidSetBusyWaitUS(10);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , HIGH);

	MSTK_voidSetBusyWaitUS(5);

	GPIOA_ODR &= 0xff0f;
	GPIOA_ODR |= 0x20;

	MSTK_voidSetBusyWaitUS(10);

	MGPIO_voidSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , LOW);



	CLCD_voidSendCommand(0x2C);
	MSTK_voidSetBusyWaitMS(5);

	CLCD_voidSendCommand(0x0C);
	MSTK_voidSetBusyWaitMS(5);

	CLCD_voidSendCommand(0x01);
	MSTK_voidSetBusyWaitMS(5);

	CLCD_voidSendCommand(0x02);
	MSTK_voidSetBusyWaitMS(5);

}

void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter = 0;
	while(Copy_pcString[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGoToXY(u8 Copy_u8XPos , u8 Copy_u8YPos)
{
	u8 Local_u8Adress;
	if(Copy_u8XPos == 0)
	{
		Local_u8Adress = Copy_u8YPos;
	}
	else if(Copy_u8XPos == 1)
	{
		Local_u8Adress = Copy_u8YPos + 0x40;
	}
	CLCD_voidSendCommand(Local_u8Adress + 128);
}


void CLCD_voidWriteNumber(u32 Copy_u32Number)
{
	u32 Local_u32Reserved=1;

	while(Copy_u32Number!=0)
	{
		Local_u32Reserved=Local_u32Reserved*10 + Copy_u32Number%10;
		Copy_u32Number/=10;
	}
	do
	{
		CLCD_voidSendData((Local_u32Reserved%10)+'0');
		Local_u32Reserved/=10;
	}
	while(Local_u32Reserved!=1);
}

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber , u8 Copy_u8XPos , u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAdress = 0;
	u8 Local_u8Iterator;

	Local_u8CGRAMAdress = Copy_u8PatternNumber * 8;
	CLCD_voidSendCommand(Local_u8CGRAMAdress + 64);

	for(Local_u8Iterator = 0 ; Local_u8Iterator < 8 ; Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}

	CLCD_voidGoToXY(Copy_u8XPos , Copy_u8YPos);
	CLCD_voidSendData(Copy_u8PatternNumber);
}
