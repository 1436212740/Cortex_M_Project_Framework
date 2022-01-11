/*
 * @Author: xiaohu
 * @Version: V1.0
 * @Date: 2022-01-07 13:36:06
 * @LastEditTime: 2022-01-07 14:22:35
 * @Brief:  
 */

#include "led.h"

/**
 * @bried:  LED初始化  
 * @para:   None
 * @retval: None
 */
void F_Led_Init(void)
{
  F_Led_GPIO_Init();
  F_LedOff();
}

/**
 * @bried:  LED开
 * @para:   None
 * @retval: None
 */
void F_LedOn(void)
{
  GPIO_SetBits(LED_RED_GPIO, LED_RED_PIN);
}


/**
 * @bried:  LED关
 * @para:   None
 * @retval: None
 */
void F_LedOff(void)
{
  GPIO_ResetBits(LED_RED_GPIO, LED_RED_PIN);
}
