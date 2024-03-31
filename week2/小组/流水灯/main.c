#include <REGX52.H>
#include <INTRINS.H>

 void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
 {
     int j;   
     while(1)
    {
        P2=0xfe;   
        Delay500ms();
	for(j=0;j<8;j++)  
         {
            P2=P2<<1 | 0x01; 
            Delay500ms();
         }
     }
 }
