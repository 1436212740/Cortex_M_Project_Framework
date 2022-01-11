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

#include "main.h"             //该文件主要用作时间结构体，不做其他函数调用
#include <stdint.h>		//基本数据类型
#include <stdbool.h>	//Bool数据类型

typedef struct 
{
  volatile uint32_t SysTime;           //系统运行时间
  uint16_t TimeCnt;           //计数时间
  uint16_t Time_10ms;           //运行10ms标志位
  uint16_t Time_100ms;          //运行100ms标志位
}Loop_Time_Typedef;
extern Loop_Time_Typedef sLoopTime;



//===========API===================
void F_Loop(void);            			//总执行函数
void F_LoopSecond_1ms(void);  			//副时钟来源
void F_SystickConfig(void);   			//系统时钟配置
void F_LoopInterruptPriority(void);	//中断优先级配置
void Delay_10us(uint32_t time_us);  //延时函数
void Delay_ms(uint32_t time_ms);    

#ifdef __cplusplus
}
#endif

#endif
