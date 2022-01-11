/*
 * @Author: xiaohu
 * @Version: V1.0
 * @Date: 2022-01-08 11:18:24
 * @LastEditTime: 2022-01-11 15:53:39
 * @Brief:  
 */
#include "Loop.h"

/**
 * @bried:  系统时钟源配置()
 * @para:   None
 * @retval: None
 */
void F_SystickConfig(void)
{
  #define SYS_TICK_TIMER
  //---------滴答作为系统时钟源--------
  #ifdef  SYS_TICK_TIMER
  SysTick_Config(720);    //10us进入一次系统中断
  #endif
}

/**
 * @bried:  us级别延时函数(单位为10us)
 * @para:   time_us--计时时间
 * @retval: None
 */
void Delay_10us(uint32_t time_us)
{
  uint32_t  before_time = sLoopTime.SysTime;
  uint32_t target = sLoopTime.SysTime + time_us;
  if(target>before_time)
    while(1)  { if(sLoopTime.SysTime>target)  return;  }
  else  //计数溢出
  {
    while (1) { if(sLoopTime.SysTime<target) break; } 
    while (1) { if(sLoopTime.SysTime>target) return;}
  }
}

/**
 * @bried: ms级别延时函数(单位为1ms)
 * @para:  time_ms--计时时间
 * @retval:None
 */
void Delay_ms(uint32_t time_ms)
{
  Delay_10us(time_ms*100);
}


//===================================================================
//======================系统中断配置==================================
//===================================================================
/**
 * @bried:  工程中断优先级配置
 * @para:   None
 * @retval: None
 */
void F_LoopInterruptPriority(void)
{
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);				//中断组号,4位抢占优先级 0位副优先级

  NVIC_SetPriority(SysTick_IRQn, 1);    //系统优先级
}

/**
 * @bried: 系统时钟中断服务函数(10us)
 * @para:  None
 * @retval:None
 */
void SysTick_Handler(void)
{
  static uint8_t time_cnt=0;
  if(++time_cnt==100)     {time_cnt = 0;F_LoopSecond_1ms();}
  sLoopTime.SysTime ++;
}

