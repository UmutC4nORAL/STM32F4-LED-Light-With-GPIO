#define RCC_AHB1ENR (*((volatile unsigned *)0x40023830))
#define GPIOD_MODER (*((volatile unsigned *)0x40020C00))
#define GPIOD_ODR (*((volatile unsigned *)0x40020C14))
#define GPIOA_IDR (*((volatile unsigned *)0x40020010))

int main(){
	volatile int i;
	RCC_AHB1ENR |= 1U << 0;
	RCC_AHB1ENR |= 1U << 3;
	GPIOD_MODER |= 1U << 30;
	while(1){
		if(GPIOA_IDR & (1U <<0)){
			GPIOD_ODR |= 1U << 15;
			for(i=0;i<1000000;i++);
			GPIOD_ODR &= ~(1U << 15);
		}
	}
}
