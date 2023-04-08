#include "stdio.h"
#include "delay.h"
#include "reg51.h"

void delay(unsigned int time)
{
	unsigned int j;
	while(time--)
	{
		for(j=0;j<200;j++);
	}
}

void key_delay(unsigned int time)
{
	
	while(time--)
	{
		;
	}
}





