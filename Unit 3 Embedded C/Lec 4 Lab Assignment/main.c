/*
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 Learn-in-depth
 Eng. Yara Ashraf
 Baremetal SW on TM4C123 ARM CortexM4
*/

#define SYSCTL_RCGC2_R 	(*((volatile unsigned long *)0x400FE108))
#define GPIO_PORTF_DATA_R	(*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R	(*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R	(*((volatile unsigned long *)0x4002551C))

int main (void)
{
	SYSCTL_RCGC2_R = 0x00000020;
	//delay to make sure GPIOF is up and runnning

	volatile unsigned long delay_count=0; //volatile to prevent optimization
	for(delay_count; delay_count < 200 ; delay_count++);
	GPIO_PORTF_DIR_R |= 1<<3; //to set direction of pin3 as output
	GPIO_PORTF_DEN_R |= 1<<3; //to enable pin3

	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;
		for(delay_count; delay_count < 200000 ; delay_count++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_count; delay_count < 200000 ; delay_count++);

	}

	return 0;
}
