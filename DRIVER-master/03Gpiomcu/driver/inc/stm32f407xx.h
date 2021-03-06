
 /* stm32f407xx.h
 *
 *  Created on: Sep 29, 2020
 *      Author: Training
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

//#include "stm32f407gpio_driver.h"
#include<stdint.h>
//base address of the memory
#define FLASH_BASEADDR   0x08000000U
#define SRAM1_BASEADDR   0x20000000U
#define SRAM2_BASEADDR   0x2001C000U
#define SRAM_BASEADDR   SRAM1_BASE_ADDR
#define ROM_BASEADDR     0x1FFF0000U

//base address of the bus
#define APB1_BASEADDR 0x40000000U
#define APB2_BASEADDR 0x40010000U
#define AHB1_BASEADDR 0x40020000U
#define AHB2_BASEADDR 0x50000000U

  //base address of the peripherals hanging on AHB1
#define GPIOA_BASEADDR 		(AHB1_BASEADDR + 0x00U)
#define GPIOB_BASEADDR 		(AHB1_BASEADDR + 0x400U)
#define GPIOC_BASEADDR 		(AHB1_BASEADDR + 0x800U)
#define GPIOD_BASEADDR 		(AHB1_BASEADDR + 0xC00U)
#define GPIOE_BASEADDR 		(AHB1_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR 		(AHB1_BASEADDR + 0x1400U)
#define GPIOG_BASEADDR 		(AHB1_BASEADDR + 0x1800U)
#define GPIOH_BASEADDR 		(AHB1_BASEADDR + 0x1C00U)
#define GPIOI_BASEADDR 		(AHB1_BASEADDR + 0x2000U)
#define GPIOJ_BASEADDR 		(AHB1_BASEADDR + 0x2400U)
#define GPIOK_BASEADDR 		(AHB1_BASEADDR + 0x2800U)
#define RCC_BASEADDR 		(AHB1_BASEADDR + 0x3800U)

//base address of the peripherals hanging on APB1
#define I2C1_BASEADDR   	(APB1_BASEADDR + 0x5400U)
#define I2C2_BASEADDR		(APB1_BASEADDR + 0x5800U)
#define I2C3_BASEADDR 		(APB1_BASEADDR + 0x5C00U)
#define SPI2_BASEADDR 		(APB1_BASEADDR + 0x3800U)
#define SPI3_BASEADDR 		(APB1_BASEADDR + 0x3C00U)
#define USART2_BASEADDR 	(APB1_BASEADDR + 0x4400U)
#define USART3_BASEADDR 	(APB1_BASEADDR + 0x4800U)
#define UART4_BASEADDR 		(APB1_BASEADDR + 0x4C00U)
#define UART5_BASEADDR 		(APB1_BASEADDR + 0x5000U)
#define UART7_BASEADDR 		(APB1_BASEADDR + 0x7800U)
#define UART8_BASEADDR 		(APB1_BASEADDR + 0x7C00U)

//base address of the peripherals hanging on APB2
#define SPI1_BASEADDR 		(APB2_BASEADDR + 0x3000U)
#define SPI4_BASEADDR 		(APB2_BASEADDR + 0x3400U)
#define SPI5_BASEADDR 		(APB2_BASEADDR + 0x5000U)
#define SPI6_BASEADDR 		(APB2_BASEADDR + 0x5400U)
#define USART1_BASEADDR 	(APB2_BASEADDR + 0x1000U)
#define USART6_BASEADDR 	(APB2_BASEADDR + 0x1400U)
#define EXTI_BASEADDR 		(APB2_BASEADDR + 0x3C00U)
#define SYSCFG_BASEADDR 	(APB2_BASEADDR + 0x3800U)



                           //Register structure of GPIO peripheral
typedef struct
{
volatile uint32_t MODER;
volatile uint32_t OTYPER;
volatile uint32_t OSPEEDR;
volatile uint32_t PUPDR;
volatile uint32_t IDR;
volatile uint32_t ODR;
volatile uint32_t BSRR;
volatile uint32_t LCKR;
volatile uint32_t AFR[2];

}GPIO_REGDEF_t;

#define GPIOA ((GPIO_REGDEF_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_REGDEF_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_REGDEF_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_REGDEF_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_REGDEF_t*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_REGDEF_t*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_REGDEF_t*)GPIOG_BASEADDR)
#define GPIOH ((GPIO_REGDEF_t*)GPIOH_BASEADDR)
#define GPIOI ((GPIO_REGDEF_t*)GPIOI_BASEADDR)
#define GPIOJ ((GPIO_REGDEF_t*)GPIOJ_BASEADDR)
#define GPIOK ((GPIO_REGDEF_t*)GPIOK_BASEADDR)



typedef struct
{
volatile uint32_t CR;
volatile uint32_t PLLCFGR;
volatile uint32_t CFGR;
volatile uint32_t CIR;
volatile uint32_t AHB1RSTR;
volatile uint32_t AHB2RSTR;
volatile uint32_t AHB3RSTR;
volatile uint32_t Reserved1;
volatile uint32_t APB1RSTR;
volatile uint32_t APB2RSTR;
volatile uint32_t Reserved2[2];
volatile uint32_t AHB1ENR;
volatile uint32_t AHB2ENR;
volatile uint32_t AHB3ENR;
volatile uint32_t Reserved3;
volatile uint32_t APB1ENR;
volatile uint32_t APB2ENR;
volatile uint32_t Reserved4[2];
volatile uint32_t AHB1LPENR;
volatile uint32_t AHB2LPENR;
volatile uint32_t AHB3LPENR;
volatile uint32_t Reserved5;
volatile uint32_t APB1LPENR;
volatile uint32_t APB2LPENR;
volatile uint32_t Reserved6[2];
volatile uint32_t BDCR;
volatile uint32_t CSR;
volatile uint32_t Reserved7[2];
volatile uint32_t SSCGR;
volatile uint32_t PLLI2SCFGR;
volatile uint32_t DCKCFGR;


}RCC_REGDEF_t;

#define RCC ((RCC_REGDEF_t*)RCC_BASEADDR)

/*********** CLOCK ENABLE MACROS ***************/
#define GPIOA_CLK_EN() (RCC->AHB1ENR |= (1<<0))
#define GPIOB_CLK_EN() (RCC->AHB1ENR |= (1<<1))
#define GPIOC_CLK_EN() (RCC->AHB1ENR |= (1<<2))
#define GPIOD_CLK_EN() (RCC->AHB1ENR |= (1<<3))
#define GPIOE_CLK_EN() (RCC->AHB1ENR |= (1<<4))
#define GPIOF_CLK_EN() (RCC->AHB1ENR |= (1<<5))
#define GPIOG_CLK_EN() (RCC->AHB1ENR |= (1<<6))
#define GPIOH_CLK_EN() (RCC->AHB1ENR |= (1<<7))
#define GPIOI_CLK_EN() (RCC->AHB1ENR |= (1<<8))
/***********************************************/

/*********** CLOCK DISABLE MACROS ***************/
#define GPIOA_CLK_DIS() (RCC->AHB1ENR |= ~(1<<0))
#define GPIOB_CLK_DIS() (RCC->AHB1ENR |= ~(1<<1))
#define GPIOC_CLK_DIS() (RCC->AHB1ENR |= ~(1<<2))
#define GPIOD_CLK_DIS() (RCC->AHB1ENR |= ~(1<<3))
#define GPIOE_CLK_DIS() (RCC->AHB1ENR |= ~(1<<4))
#define GPIOF_CLK_DIS() (RCC->AHB1ENR |= ~(1<<5))
#define GPIOG_CLK_DIS() (RCC->AHB1ENR |= ~(1<<6))
#define GPIOH_CLK_DIS() (RCC->AHB1ENR |= ~(1<<7))
#define GPIOI_CLK_DIS() (RCC->AHB1ENR |= ~(1<<8))
#endif /* INC_STM32F407XX_H_ */

/* some important macros
 */

#define ENABLE			1
#define DISABLE			0
#define SET				ENABLE
#define RESET			DISABLE
#define GPIO_Pin_Set	SET
#define GPIO_Pin_Reset	RESET

//1 RESET     0 DO NOT DO RESET

#define GPIOA_REG_RESET() 	do {(RCC->AHB1RSTR  |= 1<<0); (RCC->AHB1RSTR &= ~(1<<0)); }while(0)

#define GPIOB_REG_RESET()	do {(RCC->AHB1RSTR  |= 1<<1); (RCC->AHB1RSTR &= ~(1<<1)); }while(0)

#define GPIOC_REG_RESET()	do {(RCC->AHB1RSTR  |= 1<<2); (RCC->AHB1RSTR &= ~(1<<2)); }while(0)

#define GPIOD_REG_RESET()	do {(RCC->AHB1RSTR  |= 1<<3); (RCC->AHB1RSTR &= ~(1<<3)); }while(0)

#define GPIOE_REG_RESET()	do {(RCC->AHB1RSTR  |= 1<<4); (RCC->AHB1RSTR &= ~(1<<4)); }while(0)

#define GPIOF_REG_RESET()	do {(RCC->AHB1RSTR  |= 1<<5); (RCC->AHB1RSTR &= ~(1<<5)); }while(0)

#define GPIOG_REG_RESET()	do {(RCC->AHB1RSTR  |= 1<<6); (RCC->AHB1RSTR &= ~(1<<6)); }while(0)

#define GPIOH_REG_RESET()	do {(RCC->AHB1RSTR  |= 1<<7); (RCC->AHB1RSTR &= ~(1<<7)); }while(0)

#define GPIOI_REG_RESET()	do {(RCC->AHB1RSTR  |= 1<<8); (RCC->AHB1RSTR &= ~(1<<8)); }while(0)


