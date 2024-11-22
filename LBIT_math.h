/********************************************/
/*	Author		: Ashrakat Khaled	   		*/ 
/*	SWC			: Bit Math					*/
/*	Layer		: Library					*/
/*	Version		: 1.0						*/
/*	Date		: December 1, 2023			*/
/*	Last Edit	: N/A						*/
/********************************************/



#ifndef _LBIT_MATH_H_
#define _LBIT_MATH_H_

#define SET_BIT(Reg,Bit) Reg |= (1<<Bit)
#define CLEAR_BIT(Reg,Bit) Reg &= ~(1<<Bit)
#define TOGGLE_BIT(Reg,Bit) Reg ^= (1<<Bit)
#define GET_BIT(Reg,Bit) ((Reg>>Bit)&1)

#endif