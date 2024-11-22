/********************************************/
/*	Author		: Ashrakat Khaled	   		*/ 
/*	SWC			: DIO						*/
/*	Layer		: MCAL						*/
/*	Version		: 1.1						*/
/*	Date		: December 2, 2023			*/
/*	Last Edit	: N/A						*/
/********************************************/


#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

#define MDIO_PORTA 	0
#define MDIO_PORTB 	1
#define MDIO_PORTC 	2
#define MDIO_PORTD 	3

#define MDIO_INPUT			0
#define MDIO_OUTPUT			1
#define MDIO_INPUT_PULLUP	2

#define MDIO_LOW	0
#define MDIO_HIGH	1
#define MDIO_TOGGLE	2


/* PORT ACCESS  */
void MDIO_voidSetPortDirection(u8 ARG_u8Port, u8 ARG_u8Direction);
void MDIO_voidSetPortValue(u8 ARG_u8Port,u8 ARG_u8Value);
u8 MDIO_u8GetPortValue(u8 ARG_u8Port);

/*   PIN ACCESS   */
void MDIO_voidSetPinDirection(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8Direction);
void MDIO_voidSetPinValue(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8Value);
u8 MDIO_u8GetPinValue(u8 ARG_u8Port, u8 ARG_u8Pin);


#endif