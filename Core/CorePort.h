/*
 * @Author: xiaohu
 * @Version: V1.0
 * @Date: 2022-01-07 11:13:32
 * @LastEditTime: 2022-01-21 09:46:08
 * @Brief:  
 */
#ifndef __CORE_PORT_H__
#define __CORE_PORT_H__

#ifdef __cplusplus
extern "C" {
#endif

//===============C语言基本库===============
#include <stdint.h>		//基本数据类型
#include <stdbool.h>	//Bool数据类型
#include <string.h>		//变量类型,宏,字符数组函数
#include <stdlib.h>		//变量类型,宏,通用工具函数
#include <stdio.h>		//变量类型,宏,输入输出函数

//===============MCU库====================
#include "stm32f10x.h"

//===============Loop驱动调用===============
#include "Loop.h"

//===============MCU与底层驱动衔接库=================
#include "gpio.h"
#include "uart.h"
#include "time.h"

//===============可在此处设置硬件库宏========
//#define LOAD_BOARD_
//===============硬件端口匹配文件============
#include "PortConfig.h"


#ifdef __cplusplus
}
#endif

#endif
