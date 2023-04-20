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

void int_T0() interrupt 1	//	���ɶ�ʱ������0.1ms���ն�Ȼ�����ӳ�100�δﵽ�ӳ�0.1s��Ч��
{

	TH0=(65536-1000)/256;
	TL0=(65536-1000)%256;
	
}


