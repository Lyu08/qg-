#include <regx52.h>

//定时器控制LED的闪烁

void Timer0_Routine() interrupt 1
{
	static unsigned int T0count=0;
	TL0 = 0x66;				//???????
	TH0 = 0xFC;	
	T0count++;
	
	if(T0count>=1000)
	{
		T0count=0;
		P2_0=~P2_0;
	}
}	


void main()
{
	Timer0_Init();
	while(1){

	}
}

