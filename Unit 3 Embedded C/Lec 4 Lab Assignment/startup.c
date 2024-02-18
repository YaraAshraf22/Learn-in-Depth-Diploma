//startup.c
//Eng. Yara

#include <stdint.h>

void Reset_Handler ();
extern int main (void);

void Default_Handler ()
{
	Reset_Handler ();
}

void NMI_Handler () __attribute__ ((weak, alias ("Default_Handler")));
void H_fault_Handler () __attribute__ ((weak, alias ("Default_Handler")));


//reserving 1024 bytes located by .bss using unintialized global array of 256 elements (256*4=1024)
//Static to limit scope to this file only
static unsigned long stack_top[256];

//Method 1] using global unint array
/*uint32_t vectors[] __attribute__((section(".vectors"))) = {
	
	(uint32_t) &stack_top[0]+ sizeof(stack_top),
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,

};*/

//Method 2] using global array of constant pointers to function takes anything and returns void
//Per acrchitecture pointer size is 32bit so equivalent to method 1 in size

void (* const g_p_fn_Vectors[]) () __attribute__((section(".vectors"))) = {

	(void (*)()) ((unsigned long)stack_top+ sizeof(stack_top)),
	//below  are not casted as they are already def as func takes anything and returns void

	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler,

};

extern unsigned int _E_text ;
extern unsigned int _S_Data ;
extern unsigned int _E_Data ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;

void Reset_Handler ()
{
	//copy .data section from flash to sram
	unsigned int DATA_size = (unsigned char*)&_E_Data - (unsigned char*)&_S_Data ;
	unsigned char* P_src = (unsigned char*)&_E_text ;
	unsigned char* P_dst = (unsigned char*)&_S_Data ;	
	int i;
	for (i=0; i< DATA_size ; i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++) ;
	}
	//init .bss section in SRAM = 0
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	P_dst = (unsigned char*)&_S_bss;
	for (i=0; i< bss_size ; i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0 ;
	}
	//jump to main()
	
	main();
}