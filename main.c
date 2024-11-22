/*
 * main.c
 *
 *  Created on: Dec 9, 2023
 *      Author: dell1
 */

#define F_CPU 8000000UL
#include <util/delay.h>

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MDIO_interface.h"

#define HLCD_DATA_PORT	MDIO_PORTA
#define HLCD_CTRL_PORT	MDIO_PORTB
#define HLCD_RS_PIN		0
#define HLCD_RW_PIN		1
#define HLCD_EN_PIN		2

void HLCD_voidInit(void);
void HLCD_voidWriteCmd(u8 ARG_u8Cmd);
void HLCD_voidWriteChar(char ARG_charChar);
void HLCD_voidClearScreen(void);

int main(void)
{
	HLCD_voidInit();
	HLCD_voidWriteChar('A');
	HLCD_voidWriteChar('s');
	HLCD_voidWriteChar('h');
	HLCD_voidWriteChar('r');
	HLCD_voidWriteChar('a');
	HLCD_voidWriteChar('k');
	HLCD_voidWriteChar('a');
	HLCD_voidWriteChar('t');
	while(1);
	return 0;
}

void HLCD_voidInit(void)
{
	MDIO_voidSetPortDirection(HLCD_DATA_PORT, 0xFF);
	MDIO_voidSetPinDirection(HLCD_CTRL_PORT, HLCD_RS_PIN, MDIO_OUTPUT);
	MDIO_voidSetPinDirection(HLCD_CTRL_PORT, HLCD_RW_PIN, MDIO_OUTPUT);
	MDIO_voidSetPinDirection(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_OUTPUT);
	_delay_ms(30);
	HLCD_voidWriteCmd(0x3F);	//Function Set Command
	_delay_us(40);
	HLCD_voidWriteCmd(0x0F);	//Display on off control command
	_delay_us(40);
	HLCD_voidClearScreen();
	HLCD_voidWriteCmd(0x06);	//Entry Mode Command
	_delay_us(40);
}

void HLCD_voidWriteCmd(u8 ARG_u8Cmd)
{
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, MDIO_LOW);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN, MDIO_LOW);
	MDIO_voidSetPortValue(HLCD_DATA_PORT, ARG_u8Cmd);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_HIGH);
	_delay_us(1);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);
}

void HLCD_voidWriteChar(char ARG_charChar)
{
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, MDIO_HIGH);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN, MDIO_LOW);
	MDIO_voidSetPortValue(HLCD_DATA_PORT, ARG_charChar);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_HIGH);
	_delay_us(1);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);
}

void HLCD_voidClearScreen(void)
{
	HLCD_voidWriteCmd(0x01);
	_delay_ms(2);
}
