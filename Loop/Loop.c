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
 * @bried:  10ms执行函数  
 * @para:   None
 * @retval: None
 */
void F_Time_10ms_Func(void)
{
	
}

/**
 * @bried:  100ms执行函数  
 * @para:   None
 * @retval: None
 */
void F_Time_100ms_Func(void)
{
	
}


/**
 * @bried:  副时钟循环执行函数(优先级最低) 
 * @para:   None
 * @retval: NOne
 */
void F_TimeRun(void)
{
  if(sLoopTime.Time_10ms)   {sLoopTime.Time_10ms--;F_Time_10ms_Func();}
  if(sLoopTime.Time_100ms)  {sLoopTime.Time_100ms--; F_Time_100ms_Func();}
}

/**
 * @bried:  副时钟来源(放置于1ms中断中(最高优先级))
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
 * @bried:  总循环函数(只给main.c调用)
 * @para:   None
 * @retval: None
 */
void F_Loop(void)
{
  //=======底层驱动初始化=======
  F_Led_Init();
  //=======应用层初始化=========
	
  F_LoopInterruptPriority();  //优先级设置
  F_SystickConfig();          //系统时钟设置
  while (1)
  {
    F_TimeRun();  //副时钟执行函数
	//=======主循环执行===========
  
  }
}

