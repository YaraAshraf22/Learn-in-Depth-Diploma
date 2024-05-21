/*
 * main.c
 *
 *  Created on: May 16, 2024
 *      Author: HP
 */


#define F_CPU 8000000UL
#include "util/delay.h"
#include "avr/io.h"
#include "avr/interrupt.h"


int main ()
{
	//configure PD5,6,7 as o/p pins
	DDRD |= (7<<5);

	//Interrupts

	//Interrupt sense control
	//INT0, MCUCR Bit 1, 0 – ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0
	MCUCR |=(1<<0); //any logical change

	//INT1, MCUCR Bit 3, 2 – ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0
	MCUCR |=(3<<2); //rising edge

	//INT2, MCUCSR Bit 6 – ISC2: Interrupt Sense Control 2
	MCUCSR &=~(1<<6); //falling edge

	//Enable External INT
	//Bit 6 – INT0: External Interrupt Request 0 Enable
	GICR |=(1<<6);
	//Bit 7 – INT1: External Interrupt Request 1 Enable
	GICR |=(1<<7);
	//Bit 5 – INT2: External Interrupt Request 2 Enable
	GICR |=(1<<5);

	//Enable Global Interrupt
	//Bit 7 – I: Global Interrupt Enable
	SREG |=(1<<7);

	while(1)
	{
		PORTD&=~(7<<5);
		_delay_ms(1000);
	}

	return 0;
}

ISR(INT0_vect)
{
	PORTD|=(1<<5);
	_delay_ms(1000);
}
ISR(INT1_vect)
{
	PORTD|=(1<<6);
	_delay_ms(1000);
}
ISR(INT2_vect)
{
	PORTD|=(1<<7);
	_delay_ms(1000);
}
