#include "reg51.h"
#include "INTRINS.H"
#include "timer.h"

int Start;
int c = 0;
	
void Timer_Init(void)
{
	TMOD=0x01;	
	ET0=1;
	EA=1;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	PT0=0;
}

void int_T0() interrupt 1	
{

	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	c++;
	if(c == 100)
	{
		Start = 1;
		c = 0;
		TR0 = 0;
	}
	
	
}


