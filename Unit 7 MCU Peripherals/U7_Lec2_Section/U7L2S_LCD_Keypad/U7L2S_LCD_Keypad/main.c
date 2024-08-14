/*
 * U7L2S_LCD_Keypad.c
 *
 * Created: 8/11/2024 2:37:22 AM
 * Author : HP
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include "util/delay.h"
#include "LCD_Driver/LCD.h"
#include "Keypad_Driver/Keypad.h"

int main(void)
{
   LCD_INIT();
   _delay_ms(10);
   KEYPAD_INIT();
  // LCD_CUSTOM_CHAR();
   char pressed_key;
    while (1) 
    {
		pressed_key = KEYPAD_GET_CHAR();
		switch(pressed_key)
		{
			case '!':
			{
				LCD_CLEAR();
				break;
			}
			case 'N':
			{
				break;
			}
			default:
			{
				LCD_WRITE_CHAR(pressed_key);
				break;
			}
		}
    }
}

