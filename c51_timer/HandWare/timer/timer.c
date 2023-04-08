#include "reg51.h"
#include "INTRINS.H"
#include "timer.h"

char i=100;
int Add_value=0;
int hour,minute,second;

sbit LED = P2^7;

void Timer_Init(void)
{
	TMOD=0x01;	
	ET0=1;
	EA=1;
	TH0=(65536-1000)/256;
	TL0=(65536-1000)%256;
	PT0=0;
}

void Timer_setting(void)
{
	
	TR0=1;
}

void int_T0() interrupt 1	//	���ɶ�ʱ������0.1ms���ն�Ȼ�����ӳ�100�δﵽ�ӳ�0.1s��Ч��
{

	TH0=(65536-1000)/256;
	TL0=(65536-1000)%256;
	i--;
	if(i<=0)
	{
		i=100;
		
	if(Add_value < 9)
	{
			Add_value++;
	}
	else if(second < 59)	//	��ʱ�� 
	{
		second ++;
		Add_value = 0; 
	}
	else if(minute < 59)	// ��ʱ��
	{
		minute ++ ;
		second = 0;
	}
	else if(hour < 59)	//	����ʱ
	{
		hour ++ ;
		minute = 0;
	}
 }	
	
	if(minute  >= 1 && 2 > minute)
	{
		if(5 > second)
			LED =! LED;
	}
	else
	{
		LED = 1;
	}
	
}


