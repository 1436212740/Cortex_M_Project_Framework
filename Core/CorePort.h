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

//===============C���Ի�����===============
#include <stdint.h>		//������������
#include <stdbool.h>	//Bool��������
#include <string.h>		//��������,��,�ַ����麯��
#include <stdlib.h>		//��������,��,ͨ�ù��ߺ���
#include <stdio.h>		//��������,��,�����������

//===============MCU��====================
#include "stm32f10x.h"

//===============Loop��������===============
#include "Loop.h"

//===============MCU��ײ������νӿ�=================
#include "gpio.h"
#include "uart.h"
#include "time.h"

//===============���ڴ˴�����Ӳ�����========
//#define LOAD_BOARD_
//===============Ӳ���˿�ƥ���ļ�============
#include "PortConfig.h"


#ifdef __cplusplus
}
#endif

#endif
