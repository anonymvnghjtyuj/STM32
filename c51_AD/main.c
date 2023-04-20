#include "reg51.h"
#include <INTRINS.H>
#include "led.h"
#include "key.h"
#include "delay.h"
#include "Digital_tube.h"


extern int Key1_status;
extern int Key2_status;
extern int key_time;

sbit select1 = P3^5;
sbit select2 = P3^6;
sbit select3 = P3^7;

void main()
{
	//unchar code discodes[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};	//	要改为共阴极数码管，带小数点
  //unint r;
	key_Init();
	DA0832_Init();
	//Square();
	
	while(1)
	{
			
		if(Key2_status == 1)
		{
			while(1)
			{
				Start_ADC0808();
				if(Key1_status == 1)
				{
					break;
				}
			}	
		}
		
		if(Key1_status == 1)
		{
			while(1)
			{
				switch(key_time)
				{
					case 1:
					{
						do
						{
							SIN();
							if(Key2_status == 1)
			  		{
							break;
						}
						}while(key_time == 1);
					}
					case 2:
					{
						Square();
						do
						{
							if(Key2_status == 1)
						{
							break;
						};
						}while(key_time == 2);
					}
				}
				Key1_status = 0;
				if(Key2_status == 1)
				{
					break;
				}
			}
				
		}
		
		
			
	}
		
}

/*



if(key_time == 1)
				{
					SIN();
				}
*/

