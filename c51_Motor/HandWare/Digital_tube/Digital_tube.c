#include "reg51.h"
#include <INTRINS.H>
#include "Digital_tube.h"
#include "delay.h"

sbit sel1 = P2^0;
sbit sel2 = P2^1;
int i,num1,num2;

uchar code table[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void show(int num)
{
	
	num1 = num / 10;
	num2 = num % 10;
	
	for(i = 0;i < 2;i ++)
	{
		if(i == 0)
		{
			sel1 = 0;
			sel2 = 1;
			P0 = table[num1];
			delay(100);
			P0=0x0;
		}
		if(i == 1)
		{
			sel1 = 1;
			sel2 = 0;
			P0 = table[num2];
			delay(100);
			P0=0x0;
		}
	}
		
}


