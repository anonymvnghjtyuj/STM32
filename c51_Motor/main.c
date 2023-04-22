#include "reg51.h"
#include <INTRINS.H>
#include "led.h"
#include "key.h"
#include "delay.h"
#include "Digital_tube.h"
#include "motor.h"
#include "led.h"

extern int High_width ;
extern int Add_Value;
extern int Reduce_Value;

 void main(void)
{
	
	int key_flag;
	
	Timer_Init();
	
	while(!(key_flag = Key_scan()));	//	我发现一个问题就是如果这个Key_scan里面没有匹配的选项，他就会默认传回一个0；
	
	while(1)
	{
			
			switch(key_flag)
			{
				case 1:
						do
						{
							Motor_Start();
							show(High_width);
							key_flag = Key_scan();
						}while(key_flag != 2 && key_flag != 3 && key_flag != 4 && key_flag != 5 && key_flag != 6);
						break;
						
				case 2:
						do
						{
							Motor_Stop();
							show(High_width);
							key_flag = Key_scan();
						}while(key_flag != 1 && key_flag != 3 && key_flag != 4 && key_flag != 5 && key_flag != 6);
						break;
						
				case 3:
						do
						{
							Motor_Back();
							show(High_width);
							key_flag = Key_scan();
						}while(key_flag != 2 && key_flag != 1 && key_flag != 4 && key_flag != 5 && key_flag != 6);
						break;
						
				case 4:
						do
						{
							Motor_Start();
							show(High_width);
							key_flag = Key_scan();
						}while(key_flag != 2 && key_flag != 3 && key_flag != 1 && key_flag != 5 && key_flag != 6);
						break;
						
				case 5:
						do
						{
							if(Add_Value == 1)
							{
									High_width += 5;
								if(High_width > 100)
								{
									High_width = 50;
								}
								Add_Value = 0;
							}
							LED(High_width);
							show(High_width);
							key_flag = Key_scan();
						}while(key_flag != 2 && key_flag != 3 && key_flag != 1 && key_flag != 4 && key_flag != 6);

					break;
				
				case 6:
						do
						{
							if(Reduce_Value == 1)
							{
								High_width -= 5;
								if(High_width < 0)
								{
									High_width = 50;
								}
								Reduce_Value = 0;
							}
							LED(High_width);
							show(High_width);
							key_flag = Key_scan();
						}while(key_flag != 2 && key_flag != 3 && key_flag != 1 && key_flag != 4 && key_flag != 5);
						break;
			}
			
		show(High_width);
	 }
}


//#include "reg51.h"
//#include "intrins.h"
//#include "Digital_tube.h"
//#include "led.h"
//#include "timer.h"
//		
//sbit key_inc = P1^7;
//sbit key_dec = P1^6;
//sbit key_dir = P1^5;
//sbit key_on = P1^4;
//sbit DIR = P3^0;
//sbit PWM = P3^1;


//void delay(uint);
//int High_width = 50;


// void main(void)
//{
//	Timer_Init();
//	
//	while(1)
//	{
//	if(key_on == 0)
//	  {
//		 if(key_dir == 0)
//		 { 
//				DIR=1;
//			   PWM=1;
//			   delay(High_width);
//			   PWM=0;
//			   delay(100-High_width);
//			}	        
//	     else
//			 {  
//					 DIR=0;
//					 PWM=1;
//					 delay(High_width);
//					 PWM=0;
//					 delay(100-High_width);
//				}
//					show(High_width);
//		}
//		 if(key_dec == 0)
//			{
//				delay(12000);
//				if(key_dec == 0)
//				{
//						 if(High_width == 0)High_width = 100;
//						else
//						High_width = High_width - 1;
//						while(key_dec == 0);
//				}					
//			}

//		 if(key_inc == 0)
//			{
//				delay(12000);
//				if(key_inc==0)
//				{
//					if(High_width==100)High_width=0;
//					else
//					High_width=High_width+1;
//					while( key_inc==0 );
//				}
//			}
//			LED(High_width);
//			show(High_width);

//	   }
//}

//void delay(uint j)
//{
//	for(;j>0;j--)
//	{
//		_nop_();
//	}
//}





