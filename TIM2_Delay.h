/***************************************************************************
* �ļ���          : TIM2_Delay.h
* ����            : ʹ��TIM2��ʱ�����бȽϾ�ȷ����ʱ����
* �汾��          : v1.0
* ����            : ����
* ����            : 2018/3/20
* ������־        :
* ����         �汾      ����                ��������
* 2018/3/20    v0.1      ����              �����ļ�
* 2018/4/10    v1.0      ����              ��������������ע�ͣ�����
***************************************************************************/

#ifndef _TIM2_DELAY_H_
#define _TIM2_DELAY_H_

#include <iostm8s103f3.h>

void TIM2_Init(void);                   //��ʱ����ʼ��
void DelayUs(unsigned int us);          //us����ʱ
void DelayMs(unsigned int ms);          //ms����ʱ

#endif