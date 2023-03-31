#include "reg51.h"
#include <INTRINS.H>
#include "led.h"
#include "key.h"
#include "delay.h"
#include <REGX51.H>

unsigned char dis[7]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82};	

void main()
{
	static unsigned char key_value;
	unsigned int speed=10000;
	

	while(1)
	{
		
		P2=0xff;
		P0=dis[0];
		
		key_value=key_scan();
		
		
		switch(key_value)
		{
			case 1:
			{
				P0=dis[1];
				//left_led(key_value);
				while(1)
				{
					left_led();
					key_value=key_scan();
					if((key_value==2)||(key_value==3)||(key_value==4)||(key_value==5)||(key_value==6))
					{
						break;
					}
				}
			}
			break;
			case 2:
			{
				P0=dis[2];
				while(1)
				{
					right_led();
					key_value=key_scan();
					if((key_value==5)||(key_value==3)||(key_value==4)||(key_value==1)||(key_value==6))
					{
						break;
					}
				}
			}
			break;
			case 3:
			{
				P0=dis[3];
				while(1)
				{
					blink();
					key_value=key_scan();
					if((key_value==2)||(key_value==5)||(key_value==4)||(key_value==1)||(key_value==6))
					{
						break;
					}
				}
				
			}
			break;
			case 4:
			{
				P0=dis[4];
				//forward_flow_led();
				while(1)
				{
					forward_flow_led();
					key_value=key_scan();
					if((key_value==2)||(key_value==3)||(key_value==5)||(key_value==1)||(key_value==6))
					{
						break;
					}
				}
			}
			break;
			case 5:
			{
				P0=dis[5];
				while(1)
				{
					speed=speed-100;
					control_speed_led(speed);
					key_value=key_scan();
					if((key_value==2)||(key_value==3)||(key_value==4)||(key_value==1)||(key_value==6))
					{
						break;
					}
				}
			}
			break;
			case 6:
			{
				P0=dis[0];
				while(1)
				{
					reset_led();
					key_value=key_scan();
					if((key_value==2)||(key_value==3)||(key_value==4)||(key_value==1)||(key_value==6))
					{
						break;
					}
				}
			}
			break;
			default:
			{
				P0=dis[0];
				reset_led();
			}
		}		
		
		
		
		
	}
}
