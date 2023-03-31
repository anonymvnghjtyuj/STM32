#include "stdio.h"
#include "delay.h"
#include "reg51.h"

void led_delay(unsigned int time)
{
	unsigned int j;
	for(j=0;j<time;j++)
	{
		;
	}
}

void main_delay(unsigned int time)	//主函数的延迟函数
{
	unsigned int j;
	for(j=0;j<time;j++)
	{
		;
	}
}

//void key_delay(void)
//{
//		uchar i;
//		for(i=0;i<200;i++)
//	{
//		;
//	}
//	
//}


