/*
 * stm32f407gpio_driver.c
 *
 *  Created on: 30-Sep-2020
 *      Author: Training
 *
 */

//#include "stm32f407xx.h"
#include "stm32f407gpio_driver.h"
/*@brief description
 * @function-
 *
 * @parm1 -
 *
 * @parm2 -
 *
 * @parm3-
 *
 * @definition
 *
 * @designed by-
 *
 * @date and time
 *

 */
void GPIO_Init(GPIO_Handle_t *GPIOHandle)
{	//init mode

	uint32_t temp=0;
	temp=(GPIOHandle->GPIO_PinConfig.GPIO_PinMode<<(2*GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	(GPIOHandle->pGPIOx->MODER) &=~(2*0x3<<GPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	GPIOHandle->pGPIOx->MODER |=temp;


	//configure speed
	temp=0;
	temp=(GPIOHandle->GPIO_PinConfig.GPIO_PinSpeed<<(2*GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	(GPIOHandle->pGPIOx->OSPEEDR) &=~(2*0x3<<GPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	GPIOHandle->pGPIOx->OSPEEDR |=temp;

	//configure pull up or down
	temp=0;
	temp=(GPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl<<(2*GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	(GPIOHandle->pGPIOx->PUPDR) &=~(2*0x3<<GPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	GPIOHandle->pGPIOx-> PUPDR |=temp;

	//configure output type
	temp=0;
	temp=(GPIOHandle->GPIO_PinConfig.GPIO_PinOPType<<(GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	(GPIOHandle->pGPIOx->OTYPER) &=~(0x1<<GPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	GPIOHandle->pGPIOx-> OTYPER |=temp;

	//configure Alternating function

	uint8_t temp1=0;
	uint8_t temp2=0;
	temp1= (GPIOHandle->GPIO_PinConfig.GPIO_PinNumber) /8;
	temp2= (GPIOHandle->GPIO_PinConfig.GPIO_PinNumber) %8;
	(GPIOHandle->pGPIOx->AFR[temp1]) &=~(4*0xF<<temp2);
	GPIOHandle->pGPIOx->AFR[temp1] = (GPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode)<<(4*temp2);



}

/*@brief description
 * @function-
 *
 * @parm1 -
 *
 * @parm2 -
 *
 * @parm3-
 *
 * @definition
 *
 * @designed by-
 *
 * @date and time
 *

 */

void GPIO_DInit(GPIO_REGDEF_t *pGPIOx)
{
			if(pGPIOx==GPIOA)
				GPIOA_REG_RESET();
			else if(pGPIOx==GPIOB)
				GPIOB_REG_RESET();
			else if(pGPIOx==GPIOC)
				GPIOC_REG_RESET();
			else if(pGPIOx==GPIOD)
				GPIOD_REG_RESET();
			else if(pGPIOx==GPIOE)
				GPIOE_REG_RESET();
			else if(pGPIOx==GPIOF)
				GPIOF_REG_RESET();
			else if(pGPIOx==GPIOG)
				GPIOG_REG_RESET();
			else if(pGPIOx==GPIOH)
				GPIOH_REG_RESET();
			else if(pGPIOx==GPIOI)
				GPIOI_REG_RESET();
			else{}
}

/*@brief description
 * @function-
 *
 * @parm1 -
 *
 * @parm2 -
 *
 * @parm3-
 *
 * @definition
 *
 * @designed by-
 *
 * @date and time
 *

 */

void GPIO_Periclkcntrl(GPIO_REGDEF_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi==ENABLE)
	{
		if(pGPIOx==GPIOA)
			GPIOA_CLK_EN();
		else if(pGPIOx==GPIOB)
			GPIOB_CLK_EN();
		else if(pGPIOx==GPIOC)
			GPIOC_CLK_EN();
		else if(pGPIOx==GPIOD)
			GPIOD_CLK_EN();
		else if(pGPIOx==GPIOE)
			GPIOE_CLK_EN();
		else if(pGPIOx==GPIOF)
			GPIOF_CLK_EN();
		else if(pGPIOx==GPIOG)
			GPIOG_CLK_EN();
		else if(pGPIOx==GPIOH)
			GPIOH_CLK_EN();
		else if(pGPIOx==GPIOI)
			GPIOI_CLK_EN();
		else
		{}
	}
}


/*@brief description
 * @function-
 *
 * @parm1 -
 *
 * @parm2 -
 *
 * @parm3-
 *
 * @definition
 *
 * @designed by-
 *
 * @date and time
 *

 */
uint8_t GPIO_ReadFromInputPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNo)
{
	uint8_t val=0;
	val =(uint8_t)(pGPIOx->IDR>>PinNo) & (0x00000001);

	return val;
}

/*@brief description
 * @function-
 *
 * @parm1 -
 *
 * @parm2 -
 *
 * @parm3-
 *
 * @definition
 *
 * @designed by-
 *
 * @date and time
 *

 */

uint16_t GPIO_ReadFromInputPort(GPIO_REGDEF_t *pGPIOx)
{
	uint8_t val=0;
	val=(uint8_t)(pGPIOx->IDR);
	return val;
}


/*@brief description
 * @function-
 *
 * @parm1 -
 *
 * @parm2 -
 *
 * @parm3-
 *
 * @definition
 *
 * @designed by-
 *
 * @date and time
 *

 */

void GPIO_WriteToOutputPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNo,uint8_t value)
{
	if(value==GPIO_Pin_Set)
		pGPIOx->ODR  |= 1<<PinNo;
	else
		pGPIOx->ODR  &= ~(1<<PinNo);
}

/*@brief description
 * @function-
 *
 * @parm1 -
 *
 * @parm2 -
 *
 * @parm3-
 *
 * @definition
 *
 * @designed by-
 *
 * @date and time
 *

 */

void GPIO_WriteToOutputPort(GPIO_REGDEF_t *pGPIOx,uint16_t value)
{
	pGPIOx->ODR=value;
}

/*@brief description
 * @function-
 *
 * @parm1 -
 *
 * @parm2 -
 *
 * @parm3-
 *
 * @definition
 *
 * @designed by-
 *
 * @date and time
 *

 */

void GPIO_ToggleOutputPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNo)
{
	pGPIOx->ODR  ^= 1<<PinNo;
}

