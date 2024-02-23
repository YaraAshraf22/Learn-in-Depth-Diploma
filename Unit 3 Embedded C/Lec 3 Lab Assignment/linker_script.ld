/*
Learn-in-depth
Unit2_Lec3_Lab2
Eng. Yara Ashraf
*/

MEMORY
{
	flash (rx) : ORIGIN = 0x08000000 , LENGTH = 128K
	sram (rwx) : ORIGIN = 0X20000000 , LENGTH = 20K
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		_E_text = . ;
	} > flash
	.data :
	{
		_S_data = . ;
		*(.data)
		. = ALIGN(4);
		_E_data = . ;
	} > sram AT> flash
	.bss :
	{
		_S_bss = . ;
		*(.bss*)
		_E_bss = . ;
		. = . + 0x1000 ;
		_stack_top = . ;
	} > sram
}