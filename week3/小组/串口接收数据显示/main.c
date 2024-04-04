#include <regx52.h>
#include "Delay.h"
#include "UART.h"
#include <stdio.h>



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