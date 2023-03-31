#include "stdio.h"
#include "reg51.h"
#include "INTRINS.H"
#include "key.h"
#include "delay.h"


sbit L1=P1^0;	//¶¨ÒåÁĞÏß
sbit L2=P1^1;
sbit L3=P1^2;

//¼üÅÌ½ÓP1¶Ë¿Ú

/*
unsigned char key_scan(void)
{
		uchar code_h;
		uchar code_l;
		P2=0xf0;	// ¸ß4Î»×÷ÎªÊä³ö£¬µÍ4Î»×÷ÎªÊäÈë
		if((P1&0xf0)!=0xf0)	//¼ì²â°´¼ü°´ÏÂ  
		{
				key_delay();	//ÑÓ³ÙÏû¶¶10ms
				if((P1&0xf0)!=0xf0)	//ÔÙ´Î¼ì²âÊÇ·ñÓĞ°´¼ü°´ÏÂ
						code_h=0xfe;
				while((code_h&0x10)!=0x10)	//ÅĞ¶ÏÊÇ·ñÉ¨µ½ÁË×îºóÒ»ĞĞ, ÎÒ¸Ğ¾õÕâ¸öÅĞ¶ÏÓĞµãÎÊÌ£¬ÒÒò´ËÎÒ×ö³öÒ»Ğ©¸ü¸Äâ
				{
					P1=code_h;
					if((P1&0xf0)!=0xf0)	//ÓĞÈË°´ÏÂ°´¼ü
					{
							code_l=(P1&0xf0|0x0f);	// ±£Áô¸ßÎ»£¬µÍÎ»ÖÃ1
							return ((~code_h)+(~code_l)); 	//¼üÖµ=ĞĞÉ¨ÃèÖµ+ÁĞÉ¨ÃèÖµ
					
					else
					{
							code_h=(code_h<<1)|0x01;	//ĞĞÉ¨Ãè×óÒÆ£¬×¼±¸É¨ÃèÏÂÒ»ĞĞ
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


