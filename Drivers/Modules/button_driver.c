/*
 * button_driver.c
 *
 *  Created on: Jan 23, 2024
 *      Author: atzml
 */
#include "stm32f4xx_hal.h"


void Button_init(void){
	  RCC->AHB1ENR |= (1<<2);// BUTTON BUS

	  // BUTTON
	  GPIOC->MODER &= ~(1<<27);
	  GPIOC->MODER &= ~(1<<26);

	  GPIOC->OSPEEDR |= (1<<27);
	  GPIOC->OSPEEDR &= ~(1<<26);

	  GPIOC->OTYPER &= ~(1<<13);
}

int Button_state(){
	if (!(GPIOC->IDR & (1 << 13))) {
	    return 1;

	} else {
	    return 0;

	}

}
