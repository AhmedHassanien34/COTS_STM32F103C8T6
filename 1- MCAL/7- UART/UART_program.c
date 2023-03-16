/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    12 march 2023	 		           		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 Uart									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/




#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


/* USART1 */
void MUSART1_voidInit(void)
{
	MUSART1 -> BRR = UART_BOUDRATE;

	/* Enable RX */
	SET_BIT(MUSART1 -> CR1 , 2);

	/* Enable TX */
	SET_BIT(MUSART1 -> CR1 , 3);

	/* Enable USART */
	SET_BIT(MUSART1 -> CR1 , 13);

	/* clear status register */
	MUSART1 -> SR = 0;

}

void MUSART1_voidTransmit(u8 *ptr)
{
	u8 Local_u8Counter = 0;
	while(ptr[Local_u8Counter] != '\0')
	{
		MUSART1 -> DR = ptr[Local_u8Counter];

		/* wait till transmit is complete */
		while((GET_BIT((MUSART1 -> SR), 6)) == 0);
		Local_u8Counter++;
	}
}

void MUSART1_voidSendChar(u8 Copy_u8Data)
{
		MUSART1 -> DR = Copy_u8Data;

		/* wait till transmit is complete */
		while((GET_BIT((MUSART1 -> SR), 6)) == 0);
}

u8   MUSART1_u8Receive(void)
{
	u8 Local_s8ReceivedData = 0;
	while(((MUSART1 -> SR) & (1 << 5)) == 0);
	Local_s8ReceivedData = ((0xFF) & (MUSART1 -> DR)) ;

	return (Local_s8ReceivedData);
}


void MUSART1_voidReceiveBuffer(char *Copy_ptrBuffer , u8 Copy_SizeBuffer)
{
	u8 Local_u8Iterator = 0;


	for(Local_u8Iterator = 0; Local_u8Iterator < Copy_SizeBuffer; Local_u8Iterator++ )
	{
		Copy_ptrBuffer[Local_u8Iterator] = MUSART1_u8ReceiveTimeOut();
	}
}

u8   MUSART1_u8ReceiveTimeOut(void)
{
	u32 timeout = 0;
	char Local_s8ReceivedData = 0;
	while(((MUSART1 -> SR) & (1 << 5)) == 0)
	{
		timeout++;
		if(timeout == 10000)
		{
			Local_s8ReceivedData = 255;
			break;
		}
	}
	if(Local_s8ReceivedData == 0)
	{
		Local_s8ReceivedData = ((0xFF) & (MUSART1 -> DR)) ;
	}

	return (Local_s8ReceivedData);
}




/************************************************************************
 * **********************************************************************
 * **********************************************************************/

/* USART2 */
void MUSART2_voidInit(void)
{
	/*  Select baudrate      */
	/* 9600   BRR = 0x341    */
	/* 115200 BRR = 0x45    */
	MUSART2 -> BRR = 0x341;

	/* Enable RX */
	SET_BIT(MUSART2 -> CR1 , 2);

	/* Enable TX */
	SET_BIT(MUSART2 -> CR1 , 3);

	/* Enable USART */
	SET_BIT(MUSART2 -> CR1 , 13);

	/* clear status register */
	MUSART2 -> SR = 0;

}

void MUSART2_voidTransmit(u8 *ptr)
{
	u8 Local_u8Counter = 0;
	while(ptr[Local_u8Counter] != '\0')
	{
		MUSART2 -> DR = ptr[Local_u8Counter];

		/* wait till transmit is complete */
		while((GET_BIT((MUSART2 -> SR), 6)) == 0);
		Local_u8Counter++;
	}
}

void MUSART2_voidSendChar(u8 Copy_u8Data)
{
		MUSART2 -> DR = Copy_u8Data;

		/* wait till transmit is complete */
		while((GET_BIT((MUSART2 -> SR), 6)) == 0);
}

u8   MUSART2_u8Receive(void)
{
	u8 Local_s8ReceivedData = 0;
	while(((MUSART2 -> SR) & (1 << 5)) == 0);
	Local_s8ReceivedData = ((0xFF) & (MUSART2 -> DR)) ;

	return (Local_s8ReceivedData);
}


void MUSART2_voidReceiveBuffer(char *Copy_ptrBuffer , u8 Copy_SizeBuffer)
{
	u8 Local_u8Iterator = 0;


	for(Local_u8Iterator = 0; Local_u8Iterator < Copy_SizeBuffer; Local_u8Iterator++ )
	{
		Copy_ptrBuffer[Local_u8Iterator] = MUSART2_u8ReceiveTimeOut();
	}
}

u8   MUSART2_u8ReceiveTimeOut(void)
{
	u32 timeout = 0;
	char Local_s8ReceivedData = 0;
	while(((MUSART2 -> SR) & (1 << 5)) == 0)
	{
		timeout++;
		if(timeout == 10000)
		{
			Local_s8ReceivedData = 255;
			break;
		}
	}
	if(Local_s8ReceivedData == 0)
	{
		Local_s8ReceivedData = ((0xFF) & (MUSART2 -> DR)) ;
	}

	return (Local_s8ReceivedData);
}


/************************************************************************
 * **********************************************************************
 * **********************************************************************/

/* USART3 */
void MUSART3_voidInit(void)
{
	/*  Select baudrate      */
	/* 9600   BRR = 0x341    */
	/* 115200 BRR = 0x45    */
	MUSART3 -> BRR = 0x45;

	/* Enable RX */
	SET_BIT(MUSART3 -> CR1 , 2);

	/* Enable TX */
	SET_BIT(MUSART3 -> CR1 , 3);

	/* Enable USART */
	SET_BIT(MUSART3 -> CR1 , 13);

	/* clear status register */
	MUSART3 -> SR = 0;

}

void MUSART3_voidTransmit(u8 *ptr)
{
	u8 Local_u8Counter = 0;
	while(ptr[Local_u8Counter] != '\0')
	{
		MUSART3 -> DR = ptr[Local_u8Counter];

		/* wait till transmit is complete */
		while((GET_BIT((MUSART3 -> SR), 6)) == 0);
		Local_u8Counter++;
	}
}

u8   MUSART3_u8Receive(void)
{
	u8 Local_s8ReceivedData = 0;
	while(((MUSART3 -> SR) & (1 << 5)) == 0);
	Local_s8ReceivedData = ((0xFF) & (MUSART3 -> DR)) ;

	return (Local_s8ReceivedData);
}


void MUSART3_voidReceiveBuffer(char *Copy_ptrBuffer , u8 Copy_SizeBuffer)
{
	u8 Local_u8Iterator = 0;


	for(Local_u8Iterator = 0; Local_u8Iterator < Copy_SizeBuffer; Local_u8Iterator++ )
	{
		Copy_ptrBuffer[Local_u8Iterator] = MUSART3_u8ReceiveTimeOut();
	}
}

u8   MUSART3_u8ReceiveTimeOut(void)
{
	u32 timeout = 0;
	char Local_s8ReceivedData = 0;
	while(((MUSART3 -> SR) & (1 << 5)) == 0)
	{
		timeout++;
		if(timeout == 10000)
		{
			Local_s8ReceivedData = 255;
			break;
		}
	}
	if(Local_s8ReceivedData == 0)
	{
		Local_s8ReceivedData = ((0xFF) & (MUSART3 -> DR)) ;
	}

	return (Local_s8ReceivedData);
}
