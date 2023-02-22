#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "usart3.h"
#include "esp8266.h"
#include "string.h"
#include "timer.h"
#include "led.h"
 
/*
��Ŀ����Ҫ���ݣ�STM32���ESP8266ģ������������ݽ���

ESP8266�����ӣ�USART3��PB10��PB11��

����ж����ݽ�����ȫ��
1�������˻��з���
2���������10ms�˶�û����һ�����ݣ�TIM7������10ms�Ķ�ʱ����
*/


 int main(void)
 {		
	char a[15];
	delay_init();	    	 			//��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 			//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 				//���ڳ�ʼ��Ϊ115200
	usart3_init(115200);	 				//���ڳ�ʼ��Ϊ115200
	LED_Init();
	 
	esp8266_start_trans();							//esp8266���г�ʼ�� 
	
	while(1)
	{
		if(USART3_RX_STA&0x8000)
		{
			printf("USART3_RX_BUF=%s\r\n",USART3_RX_BUF);
			sprintf(a,"%s",USART3_RX_BUF);
			printf("a=%s",a);
			if(strstr((const char*)a,"on"))  GPIO_ResetBits(GPIOB,GPIO_Pin_5);
				
			if(strstr((const char*)a,"off")) GPIO_SetBits(GPIOB,GPIO_Pin_5);
				
			USART3_RX_STA=0;
		}
	}
}

 
 

