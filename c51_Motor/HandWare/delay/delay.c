#include "stdio.h"
#include "delay.h"
#include "reg51.h"
#include <INTRINS.H>

void delay(uint j)
{
	for(;j>0;j--)
	{
		_nop_();
	}
}


void key_delay(unsigned int time)
{
	
	while(time--)
	{
		;
	}
}

void delay_1ms(unsigned int count)
{
	uint i,j;
	for(i = 0;i < count;i++)
	for(j = 0;j < 120 ;j++);
}



