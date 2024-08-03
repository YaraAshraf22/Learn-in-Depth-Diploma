/*
 * U7_L1_Section_Tasks.c
 *
 * Created: 8/4/2024 1:52:26 AM
 * Author : HP
 */ 

#define F_CPU 8000000UL
#include "MemoryMap.h"
#include "Utils.h"
#include <util\delay.h>

#include <avr/interrupt.h>



int main(void)
{
	//Set LED PINs (LED0-2 > PD5-7) as o/p
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
	
	//Relay1 > Buzzer > PD4 as o/p
	SET_BIT(DDRD,4);
	
	//Set pins as (PB0-1	> PD0-1) i/p
	CLEAR_BIT(DDRD,0);
	CLEAR_BIT(DDRD,1);
	//Disable Pull up
	CLEAR_BIT(PORTD,0);
	CLEAR_BIT(PORTD,1);
	
	//INT0 > PD2 > PB2
	//INT0 Rising edge
	SET_BIT(INT_MCUCR,0);
	SET_BIT(INT_MCUCR,1);
	//INT0 Enable
	SET_BIT(INT_GICR,6);
	//Global INT EN
	SET_BIT(INT_SREG,7);
	
	int count=0;
	
	while (1)
	{
		//Task1
		if(READ_BIT(PIND,0))
		{
			SET_BIT(PORTD,5);
			_delay_ms(300);
			SET_BIT(PORTD,6);
			_delay_ms(300);
			SET_BIT(PORTD,7);
			_delay_ms(300);
			CLEAR_BIT(PORTD,7);
			_delay_ms(300);
			CLEAR_BIT(PORTD,6);
			_delay_ms(300);
			CLEAR_BIT(PORTD,5);
		}
		//Task2
		if(READ_BIT(PIND,1))
		{
			count++;
			switch(count)
			{
				case 1:
				{
					SET_BIT(PORTD,5);
					break;
				}
				case 2:
				{
					SET_BIT(PORTD,6);
					break;
				}
				case 3:
				{
					SET_BIT(PORTD,7);
					break;
				}
			}
			_delay_ms(1000);
			if(count==3)
			{
				count=0;
				CLEAR_BIT(PORTD,5);
				CLEAR_BIT(PORTD,6);
				CLEAR_BIT(PORTD,7);
			}
		}
	}
}

//Task3
ISR(INT0_vect)
{
	SET_BIT(PORTD,4);
	_delay_ms(1000);
	CLEAR_BIT(PORTD,4);
}

