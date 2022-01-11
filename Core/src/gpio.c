/*
 * @Author: xiaohu
 * @Version: V1.0
 * @Date: 2022-01-06 10:40:27
 * @LastEditTime: 2022-01-07 14:13:45
 * @Brief:  
 */
#include "gpio.h"

/**
 * @bried:  LEDµƒGPIO≈‰÷√
 * @para:   None
 * @retval: None
 */
void F_Led_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd(LED_RED_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin = LED_RED_PIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(LED_RED_GPIO, &GPIO_InitStructure);
}
