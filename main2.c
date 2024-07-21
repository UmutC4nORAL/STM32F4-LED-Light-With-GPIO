#include "stm32f4xx.h"                  // Device header
int main (){
	volatile int i; // set volatile int
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_GPIOAEN; // Set D and A ports clock
	GPIOD->MODER |= GPIO_MODER_MODER15_0; // Set pin 15 of D port to output mode
	GPIOA->MODER &= ~GPIO_MODER_MODER0; // Set pin 0 of A port to digital input mode (not needed)
	while(1){
		if( GPIOA->IDR & GPIO_IDR_ID0){ // Check is button clicked
		GPIOD->ODR |= GPIO_ODR_OD15; // Light on blue LED
		for(i=0;i<1000000;i++); // Wait
		GPIOD->ODR &= ~GPIO_ODR_OD15; // Light off blue LED
		}
	}
}
