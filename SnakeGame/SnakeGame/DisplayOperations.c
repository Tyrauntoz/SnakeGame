#include "DisplayOperations.h"

void StartDisplay()
{
	PORTB = 0b00111111;
	rsLow();
	rwLow();
	
	ResetHigh();
	eHigh();

	cs1High();
	cs2High();

	WriteData();
}

void TurnOffDisplay()
{
	PORTB &= 0b1111110;
}

void cs2High()
{
	PORTD |= 0b00000001;
}

void cs2Low()
{
	PORTD &= 0b11111110;
}

void cs1High()
{
	PORTD |= 0b00000010;
}

void cs1Low()
{
	PORTD &= 0b11111101;
}

void ResetHigh()
{
	PORTD |= 0b00000100;
}

void ResetLow()
{
	PORTD &= 0b11111011;
}

void rwHigh()
{
	PORTD |= 0b00001000;
}

void rwLow()
{
	PORTD &= 0b11110111;
}

void rsHigh()
{
	PORTD |= 0b00010000;
}

void rsLow()
{
	PORTD &= 0b11101111;
}

void eHigh()
{
	PORTD |= 0b00100000;
}

void eLow()
{
	PORTD &= 0b11011111;
}

void WriteData()
{
	eLow();
	eHigh();
}

void Screen1()
{
	cs1Low();
	cs2High();
}

void Screen2()
{
	cs1High();
	cs2Low();
}

void SetPixel(char in)
{
	rsHigh();
	rwLow();
	PORTB = in;
	WriteData();
}

void WipeScreen()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			SetX(i);
			SetY(j);
			rsHigh();
			rwLow();
			
			PORTB = 0b00000000;
			WriteData();
		}
	}
}

void SetX(int x)
{
	rsLow();
	rwLow();
	PORTB = 0b10111000 | x;
	WriteData();
}

void SetY(int y)
{
	rwLow();
	rsLow();
	PORTB = 0b01000000 | y;
	WriteData();
}

