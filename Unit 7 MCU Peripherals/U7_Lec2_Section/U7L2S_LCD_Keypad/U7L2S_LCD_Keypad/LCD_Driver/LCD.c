/*
 * LCD.c
 *
 * Created: 8/11/2024 2:38:23 AM
 *  Author: HP
 */ 

#include "LCD.h"

void LCD_KICK(void)
{
	//To reset EN
	LCD_CTRL_PORT &=~(1<< ENABLE_SWITCH); 
	_delay_ms(30); // using Enable Cycle time in Bus timing characteristics in data sheet
	LCD_CTRL_PORT |= (1<< ENABLE_SWITCH);
}
void LCD_GOTO_XY(int line, int position)
{
	if(line==1)
	{
		if(position<16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if(line==2)
	{
		if(position<16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
	
}
void LCD_BUSY(void)
{
	//set port as input
	LCD_Data_DDR &= ~(0xFF << DATA_SHIFT); // D4-D7 if 4-bit mode on LCD
	//D7 as busy flag
	LCD_CTRL_PORT |= (1<< RW_SWITCH); //LCD in Read mode - busy
	LCD_CTRL_PORT &=~(1<< RS_SWITCH); //LCD in Command mode
	LCD_KICK();
	
	//set Data port as output
	LCD_Data_DDR |= (0xFF << DATA_SHIFT); 
	//RW=0 write to LCD Inst Register (RS=0)
	LCD_CTRL_PORT &=~(1<<RW_SWITCH); //turn off read mode

}
void LCD_INIT(void)
{
	_delay_ms(20);
	LCD_CTRL_DDR |= ((1<< RS_SWITCH) | (1<< RW_SWITCH) | (1<< ENABLE_SWITCH)); //output
	LCD_CTRL_PORT &=~ ((1<< RS_SWITCH) | (1<< RW_SWITCH) | (1<< ENABLE_SWITCH)); // off only turn on when needed
	LCD_Data_DDR = 0xFF; //output 
	
	_delay_ms(15);
	LCD_BUSY();
	LCD_CLEAR();
	
	#ifdef EIGHT_BIT_MODE
		LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE
		LCD_WRITE_COMMAND(LCD_INIT_4BIT_Mode); //init 4-bit mode
		LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES); // config for 2 lines for 4-bit mode
	#endif
	
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_WRITE_COMMAND (unsigned char command)
{
	LCD_BUSY();
	#ifdef EIGHT_BIT_MODE
		LCD_Data_PORT = command;
		//Write to Instruction Register
		LCD_CTRL_PORT &=~((1<<RS_SWITCH)|(1<<RW_SWITCH));
		LCD_KICK();
	#endif
	#ifdef FOUR_BIT_MODE
		LCD_Data_PORT = (LCD_Data_PORT & 0x0F) | (command & 0xF0);
		LCD_CTRL_PORT &=~((1<<RS_SWITCH)|(1<<RW_SWITCH));
		_delay_ms(1);
		LCD_KICK();
		LCD_Data_PORT = (LCD_Data_PORT & 0x0F) | (command << 4);
		LCD_CTRL_PORT &=~((1<<RS_SWITCH)|(1<<RW_SWITCH));
		_delay_ms(1);
		LCD_KICK();
	#endif
}

void LCD_WRITE_CHAR (unsigned char data)
{
	//LCD_BUSY();
	#ifdef EIGHT_BIT_MODE
		LCD_Data_PORT = data;
		//Writ to Data to LCD
		LCD_CTRL_PORT &=~(1<<RW_SWITCH);
		LCD_CTRL_PORT|=(1<<RS_SWITCH);
		LCD_KICK();
	#endif
	#ifdef FOUR_BIT_MODE
		LCD_Data_PORT = (LCD_Data_PORT & 0x0F) | (data & 0xF0);
		//RS=1 data mode & RW=0 to write
		LCD_CTRL_PORT|=(1<<RS_SWITCH);
		LCD_CTRL_PORT &=~(1<<RW_SWITCH);
		LCD_KICK();
		LCD_Data_PORT = (LCD_Data_PORT & 0x0F) | (data << 4);
		//RS=1 data mode & RW=0 write
		LCD_CTRL_PORT|=(1<<RS_SWITCH);
		LCD_CTRL_PORT &=~(1<<RW_SWITCH);
		LCD_KICK();
	#endif
}

void LCD_WRITE_STRING (char* data)
{
	int count =0;
	while(*data > 0)
	{
		count++;
		LCD_WRITE_CHAR(*data++);
		if(count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if(count == 32)
		{
			LCD_CLEAR();
			LCD_GOTO_XY(1,0);
			count=0;
		}
	}
}
void LCD_CLEAR(void)
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_CUSTOM_CHAR (void)
{
	LCD_WRITE_COMMAND(64); //write
	//Store new custom char in CGRAM
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(14);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_CHAR(2);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	//Print stored char
	LCD_WRITE_CHAR(0);
	_delay_ms(10);
}