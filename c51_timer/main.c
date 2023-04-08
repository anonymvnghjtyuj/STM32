#include "reg51.h"
#include <INTRINS.H>
#include "led.h"
#include "key.h"
#include "delay.h"
#include "Digital_tube.h"
#include "timer.h"

extern int Key1_status;
extern int Key2_status;
extern int Add_value;
extern int key_time;
int Setting_status=0;

void main()
{
	unchar code discodes[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};	//	0~9的数字段码表，不带小数点
	int i,j=0x80;
	int key_value;
	int change_value = 0;
	int select_value =0 ;
	key_scan();
	Timer_Init();
	key_Init();
	
	
	while(1)
	{
		
		if(Key2_status==1)
		{
			
			while(1)
			{
				key_value = key_scan();
				if(key_value==4)
				{
					Setting_status ++;
					if(Setting_status > 4)
					{
						Setting_status = 0;
					}
					select_value = 0;
					change_value = 0;
				}
					
				else if(key_value == 3)
				{
						select_value ++;
						if(select_value >= 3)
						{
							select_value = 1;
						}
				}
				else if(key_value == 1)
				{
						change_value +=1;
				}
				else if(key_value == 2)
				{
						change_value -=1;
				}
						
				Show_date(Setting_status,select_value,change_value);
				Key2_status=0;
				if(Key1_status==1)
				{
					break;
				}
			}
				
		}
		

		if(Key1_status==1)
		{
			TR0=1;
			while(1)
			{
				if(key_time==3)	 //	第三次按下的时候，按键次数清零，时间清零
				{
					for(i=0;i<8;i++)
					{
						j = _crol_(j,1);
						if(j == 0x02 || j == 0x10)
						{
							P0=0xbf;
						}
						if(j == 0x04)
						{
							P0 = 0xc0;
						}
						else
						{
							P0 = 0xc0;
						}	
						delay(100);
					}
					
					key_time=0;
					Add_value=0;
				}
				Show_time(key_time,Add_value);//P2=discodes[Add_value];//Show_time(1,100);
				Key1_status=0;
				if(Key2_status==1)
				{
					break;
				}
			}
		}
			
	}
		
}



