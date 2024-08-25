/*
 * LCD.h
 *
 * Created: 8/11/2024 2:38:36 AM
 *  Author: HP
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_Data_PORT	PORTA
#define LCD_Data_DDR	DDRA
#define LCD_CTRL_PORT	PORTB
#define LCD_CTRL_DDR	DDRB

#define RS_SWITCH		1
#define RW_SWITCH		2
#define ENABLE_SWITCH	3
//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

//Data Shift 0 in 8-bit Mode - 4 in 4-bit Mode
#define DATA_SHIFT		4

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_INIT_4BIT_Mode							(0x02)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)


void LCD_INIT(void);
void LCD_WRITE_COMMAND (unsigned char command);
void LCD_WRITE_CHAR (unsigned char data);
void LCD_WRITE_STRING (char* data);
void LCD_BUSY(void);
void LCD_CLEAR(void);
void LCD_CUSTOM_CHAR(void);

#endif /* LCD_H_ */