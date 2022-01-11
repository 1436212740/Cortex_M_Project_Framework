/*
 * @Author: xiaohu
 * @Version: V1.0
 * @Date: 2022-01-07 11:13:32
 * @LastEditTime: 2022-01-10 18:18:12
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

//===============MCU������=================
#include "gpio.h"
#include "uart.h"
#include "time.h"

//===============Loop��������===============
#include "Loop.h"

#ifdef __cplusplus
}
#endif

#endif
