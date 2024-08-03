/*
 * MemoryMap.h
 *
 * Created: 8/3/2024 11:28:25 PM
 *  Author: HP
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

//PORTD
#define PORTD	*((volatile unsigned char*)(0x32))
#define DDRD	*((volatile unsigned char*)(0x31))
#define PIND	*((volatile unsigned char*)(0x30))

//Interrupt
#define INT_MCUCR	*((volatile unsigned char*)(0x55))
#define INT_MCUCSR	*((volatile unsigned char*)(0x54))
#define INT_GICR	*((volatile unsigned char*)(0x5B))
#define INT_SREG	*((volatile unsigned char*)(0x5F))

#endif /* MEMORYMAP_H_ */