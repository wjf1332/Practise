#include "demo.h"
//--------------------------------------
// Version:		v1.1
// Data:	2018.4.16   12:48
//--------------------------------------
void i2c_demo(void)
{
	#define SIZE		8
	U8 i = 0;
	U8 sBuf[SIZE] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07};
	U8 rBuf[SIZE];

	Clock_Setting();
	Led_Init();
	UART_Init();
	LED2_ON;
	I2C_Init(STANDARD_MODE);
	
	UART_SendString((U8*)"I2C Demo!\r\n",0);
	while(1)
	{
		Delay(50);
		I2C_Send(0x60,sBuf,0x08);
		I2C_Recv(0x61,rBuf,0x08);
		
		for(i = 0; i < SIZE; i++)
		{
			if(sBuf[i] != rBuf[i])
			{
				LED2_OFF;
				while(1);
			}
		}
		//UART_SendHex((U8*)rBuf,0x08);
		//这个添加串口发送
		UART_SendHex((U8*)rBuf,0x02);
	}
}