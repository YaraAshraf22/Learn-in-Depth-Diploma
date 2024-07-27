/*
 * U6_Lec4_Lab3_AVR.c
 *
 * Created: 7/20/2024 12:31:42 AM
 * Author : HP
 */ 


#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>


//PortD Registers
#define IO_Base 0x20
#define IO_DDRD		*(volatile unsigned int*)(IO_Base + 0x11)
#define IO_PORTD	*(volatile unsigned int*)(IO_Base + 0x12)

//Interrupt Registers
#define INT_MCUCR	*(volatile unsigned int*)(IO_Base + 0x35)
#define INT_MCUCSR	*(volatile unsigned int*)(IO_Base + 0x34)
#define INT_GICR	*(volatile unsigned int*)(IO_Base + 0x3B)

//Other Macros
#define SET_BIT(reg,bit)	reg|=(1<<bit)
#define CLEAR_BIT(reg,bit)	reg&=~(1<<bit)
#define TOGGLE_BIT(reg,bit)	reg^=(1<<bit)
#define READ_BIT(reg,bit)   ((reg&(1<<bit))>>bit)

int main ()
{
	//configure PD5,6,7 as o/p pins
	//DDRD |= (7<<5);
	SET_BIT(IO_DDRD,5);
	SET_BIT(IO_DDRD,6);
	SET_BIT(IO_DDRD,7);

	//Interrupts

	//Interrupt sense control
	//INT0, MCUCR Bit 1, 0 – ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0
	//MCUCR |=(0b01<<0); //any logical change
	SET_BIT(INT_MCUCR,0);
	CLEAR_BIT(INT_MCUCR,1);

	//INT1, MCUCR Bit 3, 2 – ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0
	//MCUCR |=(0b11<<2); //rising edge
	SET_BIT(INT_MCUCR,2);
	SET_BIT(INT_MCUCR,3);

	//INT2, MCUCSR Bit 6 – ISC2: Interrupt Sense Control 2
	//MCUCSR &=~(1<<6); //falling edge
	CLEAR_BIT(INT_MCUCSR,6);

	//Enable External INT
	//Bit 6 – INT0: External Interrupt Request 0 Enable
	//GICR |=(1<<6);
	SET_BIT(INT_GICR,6);
	//Bit 7 – INT1: External Interrupt Request 1 Enable
	//GICR |=(1<<7);
	SET_BIT(INT_GICR,7);
	//Bit 5 – INT2: External Interrupt Request 2 Enable
	//GICR |=(1<<5);
	SET_BIT(INT_GICR,5);

	//Enable Global Interrupt
	//Bit 7 – I: Global Interrupt Enable
	sei();

	//SREG |=(1<<7);

	while(1)
	{
		//PORTD&=~(7<<5);
		CLEAR_BIT(IO_PORTD,5);
		CLEAR_BIT(IO_PORTD,6);
		CLEAR_BIT(IO_PORTD,7);
		_delay_ms(1000);
	}

	return 0;
}

ISR(INT0_vect)
{
	//PORTD|=(1<<5);
	SET_BIT(IO_PORTD,5);
	_delay_ms(1000);
}
ISR(INT1_vect)
{
	//PORTD|=(1<<6);
	SET_BIT(IO_PORTD,6);
	_delay_ms(1000);
}
ISR(INT2_vect)
{
	//PORTD|=(1<<7);
	SET_BIT(IO_PORTD,7);
	_delay_ms(1000);
}




