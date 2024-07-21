#define RCC_AHB1ENR (*((volatile unsigned *)0x40023830))
#define GPIOD_MODER (*((volatile unsigned *)0x40020C00))
#define GPIOD_ODR (*((volatile unsigned *)0x40020C14))
#define GPIOA_IDR (*((volatile unsigned *)0x40020010))

int main(){
	volatile int i;
	RCC_AHB1ENR |= 1U << 0; // Activate AHB1 clock
	RCC_AHB1ENR |= 1U << 3; // Activate GPIO D port
	GPIOD_MODER |= 1U << 30; // Set pin 15 of GPIO D port to output mode
	while(1){
		if(GPIOA_IDR & (1U <<0)){ // Check pin 0 of GPIO A port
			GPIOD_ODR |= 1U << 15; // Light on blue LED
			for(i=0;i<1000000;i++);
			GPIOD_ODR &= ~(1U << 15); // Light off the blue LED
		}
	}
}
