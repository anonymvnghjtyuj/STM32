#include "reg51.h"
#include "INTRINS.H"
#include "timer.h"


void Timer_Init(void)
{
	TMOD=0x01;	
	ET0=1;
	EA=1;
	TH0=(65536-1000)/256;
	TL0=(65536-1000)%256;
	PT0=0;
}

void int_T0() interrupt 1	//	先由定时器设置0.1ms的终端然后再延迟100次达到延迟0.1s的效果
{

	TH0=(65536-1000)/256;
	TL0=(65536-1000)%256;
	
}


