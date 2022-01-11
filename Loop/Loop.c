/*
 * @Author: xiaohu
 * @Version: V1.0
 * @Date: 2022-01-08 11:18:15
 * @LastEditTime: 2022-01-11 15:54:41
 * @Brief:  
 */
#include "main.h"

Loop_Time_Typedef sLoopTime;

static  void F_TimeRun(void);

/**
 * @bried:  10msִ�к���  
 * @para:   None
 * @retval: None
 */
void F_Time_10ms_Func(void)
{
	
}

/**
 * @bried:  100msִ�к���  
 * @para:   None
 * @retval: None
 */
void F_Time_100ms_Func(void)
{
	
}


/**
 * @bried:  ��ʱ��ѭ��ִ�к���(���ȼ����) 
 * @para:   None
 * @retval: NOne
 */
void F_TimeRun(void)
{
  if(sLoopTime.Time_10ms)   {sLoopTime.Time_10ms--;F_Time_10ms_Func();}
  if(sLoopTime.Time_100ms)  {sLoopTime.Time_100ms--; F_Time_100ms_Func();}
}

/**
 * @bried:  ��ʱ����Դ(������1ms�ж���(������ȼ�))
 * @para:   None
 * @retval: None
 */
void F_LoopSecond_1ms(void)
{
  sLoopTime.TimeCnt ++;
  if(!(sLoopTime.TimeCnt%10))   sLoopTime.Time_10ms++;
  if(!(sLoopTime.TimeCnt%100))  sLoopTime.Time_100ms++;
  if(!(sLoopTime.TimeCnt%100))  sLoopTime.TimeCnt = 0;
}

/**
 * @bried:  ��ѭ������(ֻ��main.c����)
 * @para:   None
 * @retval: None
 */
void F_Loop(void)
{
  //=======�ײ�������ʼ��=======
  F_Led_Init();
  //=======Ӧ�ò��ʼ��=========
	
  F_LoopInterruptPriority();  //���ȼ�����
  F_SystickConfig();          //ϵͳʱ������
  while (1)
  {
    F_TimeRun();  //��ʱ��ִ�к���
	//=======��ѭ��ִ��===========
  
  }
}

