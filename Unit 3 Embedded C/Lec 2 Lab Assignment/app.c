//For VersitilePB Board

#include "uart.h"

unsigned char string_buffer[100] = "Learn-in-depth:Yara";
unsigned char const string_buffer_2[100] = "to create a rodata section";

void main(void)
{
	Uart_Send_String(string_buffer);
}