#include "stdio.h"
#include "reg51.h"
#include "INTRINS.H"
#include "key.h"
#include "delay.h"


sbit key_dir = P1^5;
sbit key_on = P1^4;
sbit key_inc = P1^7;	//	Ôö¼Ó
sbit key_dec = P1^6;	//	¼õÉÙ

int Key1_time = 0;
int Key2_time = 0;
int Add_Value = 0;
int Reduce_Value = 0;

unsigned int Key_scan(void)
{
		
			if(key_on == 0)
			{
				delay(10000);
				if(key_on == 0)
				{
						Key1_time ++;
					if(Key1_time == 1)
					{
						return 1;
					}
					else if(Key1_time == 2)
					{
						return 2;
					}
					else if(Key1_time >= 3)
					{
						Key1_time = 1;
						return 1;
					}
				}
			}
			
		else	 if(key_dir == 0)
			{
				delay(10000);
				if(key_dir == 0)
				{
					 Key2_time ++;
					if(Key2_time == 1)
					{
						return 3;
					}
					else if(Key2_time == 2)
					{
						return 4;
					}
					else if(Key2_time > 3)
					{
						Key2_time = 1;
						return 3;
					}
				}
			}
			
			if(key_inc == 0)
			{
				delay(10000);
				if(key_inc == 0)
				{
						Add_Value = 1;
						return 5;
				}
			}
			
			if(key_dec == 0)
			{
				delay(10000);
				if(key_dec == 0)
				{
						Reduce_Value = 1;
						return 6;
				}
			}
			
		return 0;
	
}

