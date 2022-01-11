/*
 * @Author: xiaohu
 * @Version: V1.0
 * @Date: 2022-01-06 10:50:20
 * @LastEditTime: 2022-01-10 18:17:47
 * @Brief:  硬件接口配置文件(目前未设置硬件版本对应文件)
 */

#ifndef __PORT_CONFIG_H__
#define __PORT_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f10x.h"

//================================================
//=======================LED======================
//================================================
//-----------------------GPIO---------------------
#define LED_RED_GPIO_CLK    RCC_APB2Periph_GPIOB
#define LED_RED_PIN         GPIO_Pin_9
#define LED_RED_GPIO        GPIOB




#ifdef __cplusplus
}
#endif

#endif
