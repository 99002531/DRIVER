/*
 * 00ledtoggle.c
 *
 *  Created on: 01-Oct-2020
 *      Author: Training
 */


#include "stm32f407gpio_driver.h"
#include<stdio.h>
void delay()
{
	for(uint32_t i=0;i<50000;i++);
}
int main(void)
{
	GPIO_Handle_t GPIO_led;
	GPIO_led.pGPIOx =GPIOD;
	GPIO_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_Pin_No_15;
	//GPIO_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_Pin_No_12;
	GPIO_led.GPIO_PinConfig.GPIO_PinMode= GPIO_Pin_Mode_Output;
	GPIO_led.GPIO_PinConfig.GPIO_PinSpeed=GPIO_Pin_VERYHIGH_Speed;
	GPIO_led.GPIO_PinConfig.GPIO_PinOPType=GPIO_PinOPType_PushPull;
	GPIO_led.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_PinPuPdControl_No	;
	GPIO_Periclkcntrl(GPIOD, ENABLE);
	GPIO_Init(&GPIO_led);


		GPIO_Handle_t GPIOUserSwitch;
		GPIOUserSwitch.pGPIOx = GPIOA;
		GPIOUserSwitch.GPIO_PinConfig.GPIO_PinNumber = GPIO_Pin_No_0;
		GPIOUserSwitch.GPIO_PinConfig.GPIO_PinMode = GPIO_Pin_Mode_Input;
		GPIOUserSwitch.GPIO_PinConfig.GPIO_PinOPType = GPIO_PinOPType_PushPull;
		GPIOUserSwitch.GPIO_PinConfig.GPIO_PinSpeed = GPIO_Pin_VERYHIGH_Speed;
		GPIOUserSwitch.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_PinPuPdControl_No;
		GPIO_Periclkcntrl(GPIOA, ENABLE);
		GPIO_Init(&GPIOUserSwitch);
		uint8_t temp =  (GPIO_ReadFromInputPin(GPIOA, GPIO_Pin_No_0));
		//printf("%d",temp);

		if (temp == 1)
			GPIO_WriteToOutputPin(GPIOD, GPIO_Pin_No_15, ENABLE);
		else
			GPIO_WriteToOutputPin(GPIOD, GPIO_Pin_No_15, DISABLE);
		//delay();



return 0;
}
