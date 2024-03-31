#include <regx52.h>
#include "Delay.h"
#include "Timer0.h"

sbit Buzzer=P2^5;

void main(){
	Timer0_Init();
	while(1){
		
	}
}

void Timer0_Routine() interrupt 1
{
	TL0 = 0x66;				//???????
	TH0 = 0xFE;	
  Buzzer=!Buzzer;
}	