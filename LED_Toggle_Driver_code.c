/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Varad Mahatme
 * @brief          : Basic driver code for blinking onboard LED LD2
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

//Find out where the LED is located
//Locate port
//Locate pin
//Configure them as needed
//Give output as needed


#define PERIPH_BASE					(0x40000000UL)

#define AHB1PERIPH_OFFSET 			(0x0020000UL)
#define AHB2PERIPH_OFFSET 			(0x08000000UL)

#define AHB1PERIPH_BASE				(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define AHB2PERIPH_BASE				(PERIPH_BASE + AHB2PERIPH_OFFSET)

#define RCC_OFFSET					(0x00001000UL)
#define RCC_BASE					(AHB1PERIPH_BASE + RCC_OFFSET)

#define GPIOB_OFFSET				(0x00000400UL)
#define GPIOC_OFFSET				(0x00000800UL)

#define GPIOB_BASE					(AHB2PERIPH_BASE + GPIOB_OFFSET)
#define GPIOC_BASE					(AHB2PERIPH_BASE + GPIOC_OFFSET)

#define AHB1EN_R_OFFSET				(0x00000048UL)
#define AHB2EN_R_OFFSET				(0x0000004CUL)
#define RCC_AHB1ENR					(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))
#define RCC_AHB2ENR					(*(volatile unsigned int *)(RCC_BASE + AHB2EN_R_OFFSET))



#define MODE_R_OFFSET				(0X00000000UL)
#define GPIOB_MODER					(*(volatile unsigned int *)(GPIOB_BASE + MODE_R_OFFSET))


#define OD_R_OFFSET					(0x014UL)
#define GPIOB_ODR					(*(volatile unsigned int *)(GPIOB_BASE + OD_R_OFFSET))


#define GPIOBEN						(1U<<1)
#define GPIOCEN						(1U<<2)
#define PIN7 						(1U<<7)
#define LED_PB7_PIN						PIN7



int main(void)
{
	/*Enable clock access to GPIOB and GPIOC*/
	RCC_AHB2ENR |= GPIOBEN;
	RCC_AHB2ENR |= GPIOCEN;

	/*Set PB7 as op pin*/
	GPIOB_MODER |=  (1<<14);		//Set bit 14 to 1
	GPIOB_MODER &= ~(1<<15);		//Set bit 15 to 0

	while(1)
	{
		//set PB7 as high
//		GPIOB_ODR |= LED_PB7_PIN;
		for(int i = 0; i <= 500000; i++)
		{
			//do nothing
		}
		GPIOB_ODR ^= LED_PB7_PIN;

	}

}





