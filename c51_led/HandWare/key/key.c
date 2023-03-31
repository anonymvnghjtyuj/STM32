#include "stdio.h"
#include "reg51.h"
#include "INTRINS.H"
#include "key.h"
#include "delay.h"


sbit L1=P1^0;	//��������
sbit L2=P1^1;
sbit L3=P1^2;

//���̽�P1�˿�

/*
unsigned char key_scan(void)
{
		uchar code_h;
		uchar code_l;
		P2=0xf0;	// ��4λ��Ϊ�������4λ��Ϊ����
		if((P1&0xf0)!=0xf0)	//��ⰴ������  
		{
				key_delay();	//�ӳ�����10ms
				if((P1&0xf0)!=0xf0)	//�ٴμ���Ƿ��а�������
						code_h=0xfe;
				while((code_h&0x10)!=0x10)	//�ж��Ƿ�ɨ�������һ��, �Ҹо�����ж��е���̣�����������һЩ�����
				{
					P1=code_h;
					if((P1&0xf0)!=0xf0)	//���˰��°���
					{
							code_l=(P1&0xf0|0x0f);	// ������λ����λ��1
							return ((~code_h)+(~code_l)); 	//��ֵ=��ɨ��ֵ+��ɨ��ֵ
					
					else
					{
							code_h=(code_h<<1)|0x01;	//��ɨ�����ƣ�׼��ɨ����һ��
					}
				}
				
		}
		
		return 0;
}
*/

//unsigned char key_scan(void)
//{
//	uchar  temp;
//	uchar i;
//	P1=0x17;
//	for(i=0;i<2;i++)
//	{
//		if(L1==0)
//		{
//			if(i==0)
//			{
//				return 1;
//			}
//			else
//			{
//				return 2;
//			}
//		}
//		
//			else if(L2==0)
//			{
//					if(i==0)
//				{
//					return 3;
//				}
//				else
//				{
//					return 4;
//				}
//			}
//			
//			else if(L3==0)
//			{
//					if(i==0)
//				{
//					return 5;
//				}
//				else
//				{
//					return 6;
//				}	
//			}
//			main_delay(600);
//			temp=P1;
//			temp=temp|0x07;
//			temp=temp<<1;
//			temp=temp|0x07;
//			P1=temp;
//			
//		}
//	return 0;
//		
//}

sbit ROW1 = P1^3; // ?1
sbit ROW2 = P1^4; // ?2
sbit COL1 = P1^0; // ?1
sbit COL2 = P1^1; // ?2
sbit COL3 = P1^2; // ?3

unsigned char key;
unsigned char key_scan(void)
{
    unsigned char key_val = 0xff; 
    ROW1 = 0; 
    if (COL1 == 0) key_val = 1; 
    if (COL2 == 0) key_val = 2; 
    if (COL3 == 0) key_val = 3; 
    ROW1 = 1; 
    ROW2 = 0; 
    if (COL1 == 0) key_val = 4; 
    if (COL2 == 0) key_val = 5; 
    if (COL3 == 0) key_val = 6; 
    ROW2 = 1; 
    return key_val; 
}


