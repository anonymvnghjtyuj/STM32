#include "reg51.h"
#include <INTRINS.H>
#include "Digital_tube.h"
#include "delay.h"
#include "key.h"
#include "produce_wave.h"

sbit START = P3^0;
sbit OE = P3^4;
sbit EOC = P3^1;
sbit select1 = P3^5;
sbit select2 = P3^6;
sbit select3 = P3^7;

uint r;

//	先弄个整体框架，具体引脚随后再分配

uchar code discode[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};	//	共阴极数码管，带小数点
uchar b[4],c = 0x10;
static unsigned int addata = 0,i;

void show(void)
{
	
			select1 = 1;
			select2 = 0;
			select3 = 0;
			P0 =b[0];
			delay_1ms(15);
		  P0 = 0x0;
		
		
			select1 = 0;
			select2 = 1;
			select3 = 0;
			P0 =b[1];
			delay_1ms(15);
			P0 = 0x0;
		
			select1 = 0;
			select2 = 0;
			select3 = 1;
			P0 =b[2];		
			delay_1ms(15);
			P0 = 0x0;			
	
}

void Start_ADC0808(void)
{
	START = 0;
	START = 1;
	START = 0;
//	while(EOC == 0)
//	{
//		OE = 1; 
//	}
	while(1)
	{

		if(EOC == 1)
			break;
		OE = 1;
		addata = P1;
	//	addata = addata * 1.96;
		OE = 0;
		b[0] = discode[addata % 10];
		b[1] = discode[addata / 10 % 10];
		b[2] = discode[addata /100 % 10];
//		for(i = 0;i <= 20;i++ )
//		{
			show();
//	}
	}

}


