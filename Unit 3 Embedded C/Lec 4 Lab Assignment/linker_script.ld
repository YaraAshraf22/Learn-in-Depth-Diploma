/* linker script for Cortex M4
Eng. Yara
*/

MEMORY
{
	flash(rx) : ORIGIN = 0x00000000, LENGTH = 512M
	sram(rwx) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	.text : {
			*(.vectors*)
			*(.text*)
			*(.rodata)
			_E_text = . ;
	}> flash
	.data : {
			_S_Data = . ;
			*(.data)
			. = ALIGN(4) ;
			_E_Data = . ;
	}> sram AT> flash
	
	.bss : {
			_S_bss = . ; 
			*(.bss*)
			_E_bss = . ; 
	}> sram
}