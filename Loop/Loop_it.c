/*
 * @Author: xiaohu
 * @Version: V1.0
 * @Date: 2022-01-08 11:18:24
 * @LastEditTime: 2022-01-11 15:53:39
 * @Brief:  
 */
#include "Loop.h"

/**
 * @bried:  ϵͳʱ��Դ����()
 * @para:   None
 * @retval: None
 */
void F_SystickConfig(void)
{
  #define SYS_TICK_TIMER
  //---------�δ���Ϊϵͳʱ��Դ--------
  #ifdef  SYS_TICK_TIMER
  SysTick_Config(720);    //10us����һ��ϵͳ�ж�
  #endif
}

/**
 * @bried:  us������ʱ����(��λΪ10us)
 * @para:   time_us--��ʱʱ��
 * @retval: None
 */
void Delay_10us(uint32_t time_us)
{
  uint32_t  before_time = sLoopTime.SysTime;
  uint32_t target = sLoopTime.SysTime + time_us;
  if(target>before_time)
    while(1)  { if(sLoopTime.SysTime>target)  return;  }
  else  //�������
  {
    while (1) { if(sLoopTime.SysTime<target) break; } 
    while (1) { if(sLoopTime.SysTime>target) return;}
  }
}

/**
 * @bried: ms������ʱ����(��λΪ1ms)
 * @para:  time_ms--��ʱʱ��
 * @retval:None
 */
void Delay_ms(uint32_t time_ms)
{
  Delay_10us(time_ms*100);
}


//===================================================================
//======================ϵͳ�ж�����==================================
//===================================================================
/**
 * @bried:  �����ж����ȼ�����
 * @para:   None
 * @retval: None
 */
void F_LoopInterruptPriority(void)
{
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);				//�ж����,4λ��ռ���ȼ� 0λ�����ȼ�

  NVIC_SetPriority(SysTick_IRQn, 1);    //ϵͳ���ȼ�
}

/**
 * @bried: ϵͳʱ���жϷ�����(10us)
 * @para:  None
 * @retval:None
 */
void SysTick_Handler(void)
{
  static uint8_t time_cnt=0;
  if(++time_cnt==100)     {time_cnt = 0;F_LoopSecond_1ms();}
  sLoopTime.SysTime ++;
}

