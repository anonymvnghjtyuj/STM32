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

void int_T0() interrupt 1	//	先由定时器设置0.1ms的终端然后再延迟100次达到延迟0.1s的效果
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
	else if(second < 59)	//	计时秒 
	{
		second ++;
		Add_value = 0; 
	}
	else if(minute < 59)	// 计时分
	{
		minute ++ ;
		second = 0;
	}
	else if(hour < 59)	//	计算时
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


