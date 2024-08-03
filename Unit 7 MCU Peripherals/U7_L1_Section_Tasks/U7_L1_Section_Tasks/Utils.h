/*
 * Utils.h
 *
 * Created: 8/3/2024 11:28:59 PM
 *  Author: HP
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(reg,bit)	(reg|=(1<<bit))
#define CLEAR_BIT(reg,bit)	(reg&=~(1<<bit))
#define TOGGLE_BIT(reg,bit) (reg^=(1<<bit))
#define READ_BIT(reg,bit)	((reg>>bit)&1)


#endif /* UTILS_H_ */