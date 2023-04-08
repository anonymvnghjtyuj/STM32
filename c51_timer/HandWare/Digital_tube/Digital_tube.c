#include "reg51.h"
#include <INTRINS.H>
#include "Digital_tube.h"
#include "timer.h"
#include "delay.h"
#include "key.h"
unchar code discode[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};	//	0~9的数字段码表，不带小数点


extern int Setting_status;
extern int hour,minute,second;


struct Date{
	unchar time;
	unchar Wen_xuan;
} select_day[8] = {{0xf9,0x01},{0xc0,0x02},{0xbf,0x04},{0x99,0x08},{0xc0,0x10},{0xbf,0x20},{0xb0,0x40},{0xa4,0x80}};

	
int Show_time(int Addstatus,int time_value)
{
			unchar i,j = 0x80;
	
		
			switch(Addstatus)	//	按键1按下第一次开始计时，第二次暂停计时，第三次秒表清零
			{
				case 1:
				{			
					select_day[0].time=discode[time_value];
						select_day[1].time=0xbf;
						select_day[2].time=discode[second % 10];
						select_day[3].time=discode[second / 10];
						select_day[4].time=0xbf;
						select_day[5].time=discode[minute % 10];
						select_day[6].time=discode[minute / 10];
						select_day[7].time=discode[hour % 10];
						
						for(i=0;i<8;i++)
						{
							P1 = select_day[i].Wen_xuan ;
							P0 = select_day[i].time ;
							delay(3);
						}
				
					
				}
					break;
				
				case 2:
					TR0 = 0;
					{
						select_day[0].time=discode[time_value];
						select_day[1].time=0xbf;
						select_day[2].time=discode[second % 10];
						select_day[3].time=discode[second / 10];
						select_day[4].time=0xbf;
						select_day[5].time=discode[minute % 10];
						select_day[6].time=discode[minute / 10];
						select_day[7].time=discode[hour % 10];
						
						for(i=0;i<8;i++)
						{
							P1 = select_day[i].Wen_xuan ;
							P0 = select_day[i].time ;
							delay(3);
						}
					}
					break;
					
//					case 3:
//				{
//					hour = 0;
//					minute = 0;
//					second = 0;
//					
//					for(i=0;i<8;i++)
//					{
//						j = _crol_(j,1);
//						if(j == 0x02 || j == 0x10)
//						{
//							P0=0xbf;
//						}
//						if(j == 0x04)
//						{
//							P0 = 0xc0;
//						}
//						else
//						{
//							P0 = 0xc0;
//						}	
//						P1=j;
//						delay(6);
//					}
					
					
				
//				}
//					break;
			}
				
	return  0;
}



void Show_date(int Setting_status,int change_value,int select_value)
{
				unchar i;
	
//				key_value = key_scan();
//				if(key_value==4)
//				{
//					Setting_status ++;
//					if(Setting_status > 4)
//					{
//						Setting_status = 0;
//					}
//					select_value = 0;
//					change_value = 0;
//				}
//					
//				else if(key_value == 3)
//				{
//						select_value ++;
//						if(select_value >= 3)
//						{
//							select_value = 1;
//						}
//				}
//				
//				else if(key_value == 1)
//				{
//						change_value +=1;
//				}
//				else if(key_value == 2)
//				{
//						change_value -=1;
//				}
//					
	
		if(Setting_status == 1)
		{
			if(select_value == 1)
			{
				select_day[0].time=discode[0+change_value];
			}
			else if(select_value == 2)
			{
				select_day[1].time=discode[0+change_value];
			}
		}
		
		else if(Setting_status == 2)
		{
			if(select_value == 1)
			{
				select_day[3].time=discode[0+change_value];
			}
			else if(select_value == 2)
			{
				select_day[4].time=discode[0+change_value];
			}
		}
		else if(Setting_status == 3)
		{
			if(select_value == 1)
			{
				select_day[6].time=discode[0+change_value];
			}
			else if(select_value == 2)
			{
				select_day[7].time=discode[0+change_value];
			}
		}
	
			for(i=0;i<8;i++)
		{
				P1 = select_day[i].Wen_xuan ;
				P0 = select_day[i].time ;
				delay(3);
		}
		
}



//for(i=0;i<8;i++)
//					{
//						j = _crol_(j,1);
//						if(j == 0x01)
//					{
//						P0 = discode[time_value];//P2 = discode[1];
//					}
//					else if(j == 0x02)
//					{
//						P0=0xbf;
//					}
//					else if(j == 0x04)
//					{
//						P0 = discode[second % 10];//P2 = discode[2];
//					}
//					else if(j == 0x08)
//					{
//						P0 = discode[second / 10];//P2 = discode[3];
//					}
//					else if(j == 0x10)
//					{
//						P0=0xbf;
//					}
//					else if(j == 0x20)
//					{
//						P0 = discode[minute % 10];//P2 = discode[4];
//					}
//					else if(j == 0x40)
//					{
//						P0 = discode[minute / 10];//P2 = discode[5];
//					}
//					else if(j == 0x80)
//					{
//						P0=discode[hour % 10];
//					}
//						P1=j;
//						key_delay(5000);
//					}



//select_day[0].time=discode[time_value];
//					select_day[1].time=0xbf;
//					select_day[2].time=discode[second % 10];
//					select_day[3].time=discode[second / 10];
//					select_day[4].time=0xbf;
//					select_day[5].time=discode[minute % 10];
//					select_day[6].time=discode[minute / 10];
//					select_day[7].time=discode[hour % 10];
//					for(i=0;i<8;i++)
//					{
//						P1 = select_day[i].Wen_xuan ;
//						P0 = select_day[i].time ;
//						delay(3);
//					}

//for(i=0;i<8;i++)
//					{
//						j = _crol_(j,1);
//						if(j == 0x01)
//					{
//						P0 = discode[time_value];//P2 = discode[1];
//					}
//					else if(j == 0x02)
//					{
//						P0=0xbf;
//					}
//					else if(j == 0x04)
//					{
//						P0 = discode[second % 10];//P2 = discode[2];
//					}
//					else if(j == 0x08)
//					{
//						P0 = discode[second / 10];//P2 = discode[3];
//					}
//					else if(j == 0x10)
//					{
//						P0=0xbf;
//					}
//					else if(j == 0x20)
//					{
//						P0 = discode[minute % 10];//P2 = discode[4];
//					}
//					else if(j == 0x40)
//					{
//						P0 = discode[minute / 10];//P2 = discode[5];
//					}
//					else if(j == 0x80)
//					{
//						P0=discode[hour % 10];
//					}
//						P1=j;
//						key_delay(5000);
//					}



