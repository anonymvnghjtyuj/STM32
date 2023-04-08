#include "stdio.h"
#include "reg51.h"
#include "INTRINS.H"
#include "key.h"
#include "delay.h"

int Key1_status = 0;
int Key2_status = 0;
int key_time;

sbit KEY1 = P2^0;
sbit KEY2 = P2^1;
sbit KEY3 = P2^2;
sbit KEY4 = P2^4;

void key_Init(void)
{
	EA=1;
	EX0=1;
	EX1=1;
	IT0=1;
	IT1=1;
	PX1=1;
	PX0=1;
}

/*
	ͨ������������ǿ��������յ�������������3����ʱ�����Ǹ��ݰ��µĴ��������Ǹı���ߵĻ����ұ�����ܵ�ֵ��1 ��2 �ң�3 ��
	����1���¾�������ֵ������2���¾��Ǽ���ֵ��Ȼ�����Ǹ��ݰ���4���µĴ���ѡ���Ǹı��꣬�£��գ�1 �꣬2 �£�3 ��
*/
unsigned int key_scan(void)
{
	
		P2=0xff;
	if((P2 && 0xfe)!=0xfe)
	{
				key_delay(5		000);
		if((P2 && 0xfe)!=0xfe)
		{
				if(KEY1 == 0)
			{
					return 1;	// ����
			}
			else if(KEY2 == 0)
			{
				return 2;	//	����
			}
			else if(KEY3 == 0)		//	  �ı���������ܵ���һ��
			{
				return 3;
			}
			else if(KEY4 == 0)	//	�ı���һ������
			{
				return 4;
			}
			else 
			{
				return 0;
			}
		}
	
	}
	
}

void int0() interrupt 0 
{
	Key1_status = 1;
	key_time++;
}

void int1() interrupt 2
{
	Key2_status = 1;
}
