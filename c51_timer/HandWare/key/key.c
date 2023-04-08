#include "stdio.h"
#include "reg51.h"
#include "INTRINS.H"
#include "key.h"
#include "delay.h"

int Key1_status = 0;
int Key2_status = 0;
int key_time;

sbit KEY1 = P2^0;
sbit KEY2 = P2^1;
sbit KEY3 = P2^2;
sbit KEY4 = P2^4;

void key_Init(void)
{
	EA=1;
	EX0=1;
	EX1=1;
	IT0=1;
	IT1=1;
	PX1=1;
	PX0=1;
}

/*
	通过这个函数我们控制年月日的增减，当按键3按下时，我们根据按下的次数控制是改变左边的还是右边数码管的值：1 左，2 右，3 左
	按键1按下就是增加值，按键2按下就是减少值，然后我们根据按键4按下的次数选择是改变年，月，日：1 年，2 月，3 日
*/
unsigned int key_scan(void)
{
	
		P2=0xff;
	if((P2 && 0xfe)!=0xfe)
	{
				key_delay(5		000);
		if((P2 && 0xfe)!=0xfe)
		{
				if(KEY1 == 0)
			{
					return 1;	// 增加
			}
			else if(KEY2 == 0)
			{
				return 2;	//	减少
			}
			else if(KEY3 == 0)		//	  改变两个数码管的哪一边
			{
				return 3;
			}
			else if(KEY4 == 0)	//	改变哪一个日期
			{
				return 4;
			}
			else 
			{
				return 0;
			}
		}
	
	}
	
}

void int0() interrupt 0 
{
	Key1_status = 1;
	key_time++;
}

void int1() interrupt 2
{
	Key2_status = 1;
}
