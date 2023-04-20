#include "stdio.h"
#include "reg51.h"
#include "INTRINS.H"
#include "key.h"
#include "delay.h"


int Key2_status = 0;
int Key1_status = 0;
int key_time;



void key_Init(void)
{
	EA=1;
	EX0=1;
	EX1=1;
	IT0=1;
	IT1=1;
	PX1=0;
	PX0=0;
}

/*
	�ȳ����������룬������ʹ�� KEY1ȥ�ӿ�������Ҳ���Ƶ�ʣ�Ȼ��KEY2�ͼ������Ҳ���Ƶ��
*/
//unsigned int key_scan(void)
//{
//	
//		P2=0xff;
//	if((P2 && 0xfe)!=0xfe)
//	{
//				key_delay(5000);
//		if((P2 && 0xfe)!=0xfe)
//		{
//				if(KEY1 == 0)
//			{
//					return 1;	// ����
//			}
//			else if(KEY2 == 0)
//			{
//				return 2;	//	����
//			}
//			else 
//			{
//				return 0;
//			}
//		}
//	
//	}
//	
//}

void int0() interrupt 0	//	DA���
{
	key_time++;
	Key1_status = 1;
	if(key_time >= 3)
	{
		key_time = 0;
	}
}

void int1() interrupt 2	//	AD����
{
	Key2_status = 1;
}

