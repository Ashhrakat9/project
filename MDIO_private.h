/********************************************/
/*	Author		: Ashrakat Khaled	   		*/ 
/*	SWC			: DIO						*/
/*	Layer		: MCAL						*/
/*	Version		: 1.1						*/
/*	Date		: December 2, 2023			*/
/*	Last Edit	: N/A						*/
/********************************************/


#ifndef _MDIO_PRIVATE_H_
#define _MDIO_PRIVATE_H_

	typedef struct
	{
		const u8 PIN;
		u8 DDR;
		u8 PORT;
	}GPIO_t;
	    
	#define GPIOA ((volatile GPIO_t*)0X39)
	#define GPIOB ((volatile GPIO_t*)0X36)
	#define GPIOC ((volatile GPIO_t*)0X33)
	#define GPIOD ((volatile GPIO_t*)0X30)
	

#endif 
