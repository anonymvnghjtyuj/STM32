#include "led.h"
#include "delay.h"
#include "timer.h"
#include "reg51.h"

sbit Led = P3^2;

extern int Start;

int a;

void LED(int High_width)
{
	if(10 >= High_width)
	{
		for(a = 0;a < 5;a++)
		{
			Led = 0;
			delay(5000);
			Led = 1;
			delay(5000);
		}
	}
	
	if(High_width >= 90)
	{
		TR0 = 1; 
	}
	
	if(Start == 1)
	{
			Start = 0;
			for(a = 0;a < 5;a++)
			{
				Led = 0;
				delay(5000);
				Led = 1;
				delay(5000);
			}
	
	}
	
}