#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "DisplayOperations.h"
#include "Graphics.h"

void Init();
void Draw();
char ReadPix(char id, char row);
void SnakeInit();
void AddPart();
void IsInBound();
void AddFood();

char game[16][16]; //värde 0 = tom, 1 - 240 är snake delar, 241 = pickup, 242 - 246 snake huvud (alla rotationer).

uint8_t x = 1;
uint8_t y = 0;
uint8_t posX = 5;
uint8_t posY = 8;
char lastPosX;
char lastPosY;
char rotation = 0;
int ttl = 3;

int main(void)
{
	Init();
	StartDisplay();
	
	WipeScreen();
	Screen2();
	
	SnakeInit();
	AddFood();
	
	char bajs = 0;
	
	while (1)
	{
		bajs++;
		if((bajs % 4) == 3)
		{
			rotation++;
			rotation %= 4;
		}
		Update();
		Draw();
		_delay_ms(60);
	}
}

void SnakeInit()
{
	for (int i = 0; i < 3; i++)
	{
		game[posX - i][posY] = ttl - i;
	}
}

void AddPart()
{
	ttl++;
}

void IsInBound()
{
	
}

void AddFood()
{
	game[rand() % 16][rand() % 16] = 241;
}

void Update()
{
	switch (rotation)
	{
		case 0:
			x = 1;
			y = 0;
		break;
		case 1:
			x = 0;
			y = 1;
		break;
		case 2:
			x = -1;
			y = 0;
		break;
		case 3:
			x = 0;
			y = -1;
		break;
		default:
			x = 1;
			y = 0;
		break;
	}
	
	lastPosX = posX;
	lastPosY = posY;
	posX += x;
	posY += y;
	
	for (int x = 0; x < 16; x++)
	{
		for (int y = 0; y < 16; y++)
		{
			//game[x][y] = BodyParts[x][y];
			if (game[x][y] > 0 && game[x][y] <= 240)
			{
				game[x][y]--;
			}
			
			game[lastPosX][lastPosY] = ttl;
			game[posX][posY] = 250 + rotation;
			
		}
	}
}

void Draw()
{
	Screen2();
	
	for (char x = 0; x < 8; x++)
	{
		SetX(x);
		SetY(0);
		for (char y = 0; y < 16; y++)
		{
			for (char i = 0; i < 4; i++)
			{
				char toWrite = ReadPix(game[x * 2][y], i);
				char add = ReadPix(game[(x * 2) + 1][y], i) << 4;
				toWrite += add;
				
				SetPixel(toWrite);
			}			
		}
	}
}

void Init()
{
	DDRA |= 0b11111111;
	DDRB |= 0b11111111;
	DDRD |= 0b11111111;
	
	PORTD |= 0b10000000;
	
	srand(time(NULL));
}

char ReadPix(char id, char row){
	char out = 0;
	if (id == 0)
	{
		for (int i = 3; i >= 0; i--)
		{
			out = out << 1;
			out += blank[row][i];
			
		}
	}
	else if (id >= 1 && id <= 240)
	{
		for(int i = 3; i >= 0; i--)
		{
			out = out << 1;
			out += fill[row][i];
		}
	}
	else if (id == 241)
	{
		for(int i = 3; i >= 0; i--)
		{
			out = out << 1;
			out += food[row][i];
		}
	}
	else if (id == (250 + 0))
	{
		for(int i = 3; i >= 0; i--)
		{
			out = out << 1;
			out += headEast[row][i];
		}
	}
	else if (id == (250 + 3))
	{
		for(int i = 3; i >= 0; i--)
		{
			out = out << 1;
			out += headNorth[row][i];
		}
	}
	else if (id == (250 + 2))
	{
		for(int i = 3; i >= 0; i--)
		{
			out = out << 1;
			out += headWest[row][i];
		}
	}
	else if (id == (250 + 1))
	{
		for(int i = 3; i >= 0; i--)
		{
			out = out << 1;
			out += headSouth[row][i];
		
		}
	}
	
	return out;
}