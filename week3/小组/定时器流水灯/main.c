#include <reg52.h>
#include <intrins.h>
#include "Timer0"

void Timer0_Routine() interrupt 1
{
	static unsigned int count=0;
	TL0 = 0x66;		
	TH0 = 0xFC;	
  count++;
	
	if(count>=1000)
	{
		count=0;
		P2 = _crol_(P2, 1);
	}
}	

void main(){
	Timer0_Init();
	P2=0xfe;
	while(1){
		
	}
}