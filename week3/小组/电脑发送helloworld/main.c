#include <reg52.h>
#include <stdio.h>

//串口初始化
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

void Delay(unsigned int xms)	//@11.0592MHz	
{
	unsigned char data i, j;

	while(xms--)
	{
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

void main()
{
	UART_Init();
	while(1)
	{
		TI=1;
		puts("Helloworld");
		TI=0;

		Delay(1000);
	}
}