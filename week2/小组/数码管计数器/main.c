#include <regx52.h>
#include "Delay.h"


unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,
0x66,0x6D,0x7D,0x07,0x7F,0x6F};



unsigned int n=0;

void Nixie(unsigned char Location,Number)
{
	switch(Location)	
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=NixieTable[Number];	
	Delay(1);			
	P0=0x00;				//消影
}

void key()//通过检测独立按键计数
{
	 if(P3_1==0&&n<10)
	 {
	  Delay(20);
	  while(P3_1==0)
	  {
		n++;
		while(1)
		{
			if(n==10)
			{
				n=0;
			}
			Nixie(1,n);
		if(P3_1==1) break;
		}
	  }
	 while(!P3_1);
	 }
}

void main(){
	while(1){
		key();
	}
}

