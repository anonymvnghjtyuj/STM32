#include "reg51.h"
#include <INTRINS.H>
#include "motor.h"
#include "delay.h"

sbit DIR = P3^0;
sbit PWM = P3^1;

int High_width = 50;

void Motor_Start(void)
{
				 DIR=0;
			   PWM=1;
			   delay(High_width);
			   PWM=0;
			   delay(100-High_width);
}

void Motor_Stop(void)
{
				 DIR=1;
			   PWM=1;
}

void Motor_Back(void)
{
				 DIR=1;
			   PWM=0;
			   delay(High_width);
			   DIR=0;
			   delay(100-High_width);
}



