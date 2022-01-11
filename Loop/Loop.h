/*
 * @Author: xiaohu
 * @Version: V1.0
 * @Date: 2022-01-08 11:18:31
 * @LastEditTime: 2022-01-11 15:54:14
 * @Brief:  
 */
#ifndef __LOOP_H__
#define __LOOP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"             //���ļ���Ҫ����ʱ��ṹ�壬����������������
#include <stdint.h>		//������������
#include <stdbool.h>	//Bool��������

typedef struct 
{
  volatile uint32_t SysTime;           //ϵͳ����ʱ��
  uint16_t TimeCnt;           //����ʱ��
  uint16_t Time_10ms;           //����10ms��־λ
  uint16_t Time_100ms;          //����100ms��־λ
}Loop_Time_Typedef;
extern Loop_Time_Typedef sLoopTime;



//===========API===================
void F_Loop(void);            			//��ִ�к���
void F_LoopSecond_1ms(void);  			//��ʱ����Դ
void F_SystickConfig(void);   			//ϵͳʱ������
void F_LoopInterruptPriority(void);	//�ж����ȼ�����
void Delay_10us(uint32_t time_us);  //��ʱ����
void Delay_ms(uint32_t time_ms);    

#ifdef __cplusplus
}
#endif

#endif
