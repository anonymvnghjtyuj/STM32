#include "stdio.h"
#include "reg51.h"
#include "INTRINS.H"
#include "led.h"
#include "delay.h"



void forward_flow_led(void)
{
	unsigned int i;
	P2=0xfe;
	for(i=0;i<8;i++)
	{
		led_delay(10000);
		P2=_crol_(P2,1);
	}
	
}

void left_led(void)
{
	
		P2=0x0f;
		led_delay(10000);
		P2=0xf0;
		led_delay(10000);
		
}

void blink(void)
{
	P2=0xff;
	led_delay(10000);
	P2=0x00;
	led_delay(10000);
}

void right_led(void)
{
		P2=0xf0;
		led_delay(10000);
		P2=0x0f;
		led_delay(10000);
}

void reset_led(void)
{
	P2=0xff;
}

void control_speed_led(unsigned int speed)
{
	unsigned int i;
	P2=0xfe;

	for(i=0;i<8;i++)
	{
		led_delay(speed);
		P2=_crol_(P2,1);
	}
}
