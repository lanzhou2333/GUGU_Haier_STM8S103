/***************************************************************************
* �ļ���          : UART.c
* ����            : UART�ĳ�ʼ��������������װ
* �汾��          : v1.0
* ����            : ����
* ����            : 2018/4/1
* ������־        :
* ����         �汾                ��������
* 2018/4/1    v0.1                 �����ļ�
* 2018/4/2    v0.2                 ʵ��UART1�Ļ������͡�����
* 2018/4/12   v1.0                 ���ƺ��������ӡ��޸�ע�� ����
***************************************************************************/

#include "UART.h"

/***************************************************************************
* ������          : UART1_Init
* ����            : UART1��ʼ��
* �������        : ��
* ���            : ��
* ����&����       : 2018/4/2 �� ���� ����
***************************************************************************/
void UART1_Init()
{
  //UART1��ʼ�� 
  //������ 9600bps У��λ�� ����λ8 ֹͣλ1
  UART1_CR1=0x00;
  UART1_CR2=0x00;
  UART1_CR3=0x00;
  unsigned int baud = 16000000 / BAUD_RATE;     //�趨������Ӧ�������봮��ʱ�ӵķ�Ƶ��
  
  //�������趨 ��дBRR2 , ��дBRR1
  UART1_BRR2 = ((unsigned char)((baud & 0xf000) >> 8)) | ((unsigned char)(baud & 0x000f));       //��д���ر��ʵĸ�4λ���4λ
  UART1_BRR1 = ((unsigned char)((baud & 0x0ff0) >> 4));                                          //��д���ر��ʵ��м�8λ
  
  //�������գ����ͣ��������ж�
  UART1_CR2=0x2c;
}

/***************************************************************************
* ������          : UART1_SendChar
* ����            : ʹ��UART1����1���ֽ�
* �������        : ����1��unsigned char c Ҫ���͵��ֽ�
* ���            : ��
* ����&����       : 2018/4/2 �� ���� ����
***************************************************************************/
void UART1_SendChar(unsigned char c)
{
  //�ȴ����ݷ��ͽ���
  while((UART1_SR & 0x80)==0x00);
  UART1_DR=c;
}

/***************************************************************************
* ������          : UART1_SendCharA
* ����            : ʹ��UART1���� length���ֽ�
* �������        : ����1��unsigned char* date Ҫ���͵��ֽ���������ֽڵ�ַ
                    ����2��Ҫ���͵��ֽ���
* ���            : ��
* ����&����       : 2018/4/2 �� ���� ����
***************************************************************************/
void UART1_SendCharA(unsigned char* data , unsigned char length)
{
  unsigned char datalen;
  for(datalen = 0 ; datalen < length ; datalen++)
    UART1_SendChar(data[datalen]);
}

/***************************************************************************
* ������          : UART1_SendString
* ����            : ʹ��UART1�����ַ���
* �������        : ����1��unsigned char* str Ҫ���͵��ַ���������'\0'��β
* ���            : ��
* ����&����       : 2018/4/6 �� ���� ����
***************************************************************************/
void UART1_SendString(unsigned char* str)
{
  unsigned char i = 0;
  while(str[i] != '\0')
    UART1_SendChar(str[i++]);
}