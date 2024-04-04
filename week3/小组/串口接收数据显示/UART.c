#include <regx52.h>
#include "Delay.h"
#include "UART.h"

void UART_Init(void)		//4800bps@11.0592MHz
{
	PCON |= 0x80;		
	SCON = 0x50;		
	TMOD &= 0x0F;		
	TMOD |= 0x20;		
	TL1 = 0xF4;			
	TH1 = 0xF4;			
	ET1 = 0;			
	TR1 = 1;			
}


void UART_SendByte(unsigned char byte){
	SBUF=byte;
	while(TI==0);//溢出标志位
//	TI==0;
}

void UART_SendString(unsigned char *str)  //串口发送字符串函数
{
    while(*str!='\0')     //判断字符串截止位则退出
	{
		UART_SendByte(*str);  
		str++;
	}
}