/*
 * stm32f407gpio_driver.h
 *
 *  Created on: 30-Sep-2020
 *      Author: Training
 */

#ifndef INC_STM32F407GPIO_DRIVER_H_
#define INC_STM32F407GPIO_DRIVER_H_

#include "stm32f407xx.h"
#include<stdint.h>

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;


typedef struct
{
	GPIO_REGDEF_t			*pGPIOx;
	GPIO_PinConfig_t 	GPIO_PinConfig;
}GPIO_Handle_t;



// GPIO_PinNumber of GPIOs


#define GPIO_Pin_No_0    0
#define GPIO_Pin_No_1    1
#define GPIO_Pin_No_2    2
#define GPIO_Pin_No_3    3
#define GPIO_Pin_No_4    4
#define GPIO_Pin_No_5    5
#define GPIO_Pin_No_6    6
#define GPIO_Pin_No_7    7
#define GPIO_Pin_No_8    8
#define GPIO_Pin_No_9    9
#define GPIO_Pin_No_10   10
#define GPIO_Pin_No_11   11
#define GPIO_Pin_No_12   12
#define GPIO_Pin_No_13   13
#define GPIO_Pin_No_14   14
#define GPIO_Pin_No_15   15


//GPIO_PinMode of GPIOs
#define GPIO_Pin_Mode_Input		0
#define GPIO_Pin_Mode_Output	1
#define GPIO_Pin_Mode_Alternate	2
#define GPIO_Pin_Mode_Analog	3



//GPIO_PinSpeed of GPIOs

#define GPIO_Pin_Low_Speed  		0
#define GPIO_Pin_Medium_Speed  		1
#define GPIO_Pin_HIGH_Speed  		2
#define GPIO_Pin_VERYHIGH_Speed  	3

//GPIO_PinOPType of GPIOs
#define GPIO_PinOPType_PushPull		0
#define GPIO_PinOPType_OpenDrain	1


//GPIO_PinPuPdControl of GPIOs

#define GPIO_PinPuPdControl_No			0
#define GPIO_PinPuPdControl_PullUp		1
#define GPIO_PinPuPdControl_PullDown	2
//#define GPIO_PinPuPdControl_Reserved	3

//GPIO_PinAltFunMode of GPios
//#define GPIO_AltFunMode_AF0			0
//#define GPIO_AltFunMode_AF1			1
//#define GPIO_AltFunMode_AF2			2
//#define GPIO_AltFunMode_AF3			3
//#define GPIO_AltFunMode_AF4			4
//#define GPIO_AltFunMode_AF5			5
//#define GPIO_AltFunMode_AF6			6
//#define GPIO_AltFunMode_AF7			7
//#define GPIO_AltFunMode_AF8			8
//#define GPIO_AltFunMode_AF9			9
//#define GPIO_AltFunMode_AF10		    10
//#define GPIO_AltFunMode_AF11		    11
//#define GPIO_AltFunMode_AF12		    12
//#define GPIO_AltFunMode_AF13		    13
//#define GPIO_AltFunMode_AF14		    14
//#define GPIO_AltFunMode_AF15		    15

void GPIO_Init(GPIO_Handle_t *GPIOHandle);

void GPIO_DInit(GPIO_REGDEF_t *pGPIOx);

void GPIO_Periclkcntrl(GPIO_REGDEF_t *pGPIOx, uint8_t EnorDi);

uint8_t GPIO_ReadFromInputPin(GPIO_REGDEF_t *pGPIOX,uint8_t PinNo);

uint16_t GPIO_ReadFromInputPort(GPIO_REGDEF_t *pGPIOX);

void GPIO_WriteToOutputPin(GPIO_REGDEF_t *pGPIOX,uint8_t PinNo,uint8_t value);

void GPIO_WriteToOutputPort(GPIO_REGDEF_t *pGPIOX,uint16_t value);

void GPIO_ToggleOutputPin(GPIO_REGDEF_t *pGPIOX,uint8_t PinNo);


#endif /* INC_STM32F407GPIO_DRIVER_H_ */
