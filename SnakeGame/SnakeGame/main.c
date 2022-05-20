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
long GetSeed();
void GetRotation(int x, int y);
uint16_t ADCRead(uint8_t direction);
void GameOver();
void DrawScore();
char Reverse(char out);
void UpdateScore();
void DrawNumber(char in);
char lost = 0;

char game[16][16]; //värde 0 = tom, 1 - 240 är snake delar, 241 = pickup, 242 - 246 snake huvud (alla rotationer).

uint8_t x = 1;
uint8_t y = 0;
uint8_t posX = 5;
uint8_t posY = 8;
char lastPosX;
char lastPosY;
char rotation = 0;
char lastRotation = 0;
char nextRotation = 0;
int ttl = 3;
int delay = 60;
int points = 0;

int joystickY = 600;
int joystickX = 600;
int jsDeadZoneY = 150;
int jsDeadZoneX = 150;

int main(void)
{
	Init();
	StartDisplay();
	
	WipeScreen();
	Screen2();
	
	SnakeInit();
	AddFood();
	
	DrawScore();
	UpdateScore();
	
	while (1)
	{
		if (lost == 0)
		{
			
			for (int i = 0; i < 5; i++)
			{
				_delay_ms(1);
				GetRotation(0, 1);
				if (rotation != lastRotation)
				{
					nextRotation = rotation;
				}
			}
			
			if (((rotation + 2) % 4) == lastRotation)
			{
				rotation = lastRotation;
			}
			lastRotation = rotation;
			Update();
			Draw();
		}
		else
		{
			_delay_ms(100);
			Draw();
		}
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
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			game[i][j]++;
		}
	}
	
	ttl++;
	
	points++;
	UpdateScore();
}

void AddFood()
{
	char xSpawn = random() % 16;
	char ySpawn = random() % 16;
	game[xSpawn][ySpawn] = 241;
}

uint16_t ADCRead(uint8_t direction)
{
	ADMUX = (ADMUX & 0b11111000) | direction;
	
	ADCSRA |= 1 << ADSC;
	while (ADCSRA & (1 << ADSC))
	{}
	return ADC;
}

void GetRotation(int x, int y)
{
	int currentX = ADCRead(x);
	int currentY = ADCRead(y);
	
	if (currentX > joystickX + jsDeadZoneX)
	{
		rotation = 3;
	}
	else if (currentY < joystickX - jsDeadZoneX)
	{
		rotation = 0;
	}
	else if (currentX < joystickY - jsDeadZoneY)
	{
		rotation = 1;
	}
	else if (currentY > joystickY + jsDeadZoneY)
	{
		rotation = 2;
	}
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
	
	if (posX >= 16 || posX < 0 || posY >= 16 || posY < 0) //out of bounds
	{
		GameOver();
	}
	
	if (game[posX][posY] > 0 && game[posX][posY] <= ttl) //ran into self
	{
		GameOver();
	}
	
	
	if ((game[posX][posY] == 241))	//add food
	{
		AddPart();
		AddFood();
	}
	if (lost == 0)
	{
		for (int x = 0; x < 16; x++)
		{
			for (int y = 0; y < 16; y++)
			{
				if ((game[x][y] > 0 && game[x][y] <= 240) )
				{
					game[x][y]--;
				}
				
				game[lastPosX][lastPosY] = ttl;
				game[posX][posY] = 250 + rotation;
			}
		}
	}
}

void Draw()
{
	Screen1();
	
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

void DrawScore()
{
	Screen2();

	/*for (char x = 0; x < 4; x++)
	{
		SetX(x);
		SetY(50);
		
		for (int y = 8; y >= 0; y--)
		{
			char toWrite = 0;
			for (char i = 0; i < 8; i++)
			{
				toWrite += (high[y][x*8 + i] << i);
			}
			
			SetPixel(toWrite);
		}
	}*/
	
	for (char x = 0; x < 5; x++)
	{
		SetX(x);
		SetY(20);
		
		for (int y = 8; y >= 0; y--)
		{
			char toWrite = 0;
			for (char i = 0; i < 8; i++)
			{
				toWrite += (score[y][x*8 + i] << i);
			}
			
			SetPixel(toWrite);
		}
	}
	
	for (char x = 0; x < 8; x++)
	{
		SetX(x);
		SetY(0);
		SetPixel(0xFF);
	}
}

void UpdateScore()
{
	Screen2();
	int temp = points;
	
	for (int x = 6; x >= 0; x--)
	{
		SetX(x);
		SetY(7);
		
		if (x == 6 || x == 5)
		{
			DrawNumber(0);
		}
		else{
			int r = points / pow(10, 4-x);
			r = r % 10;
			
			DrawNumber(r);
		}
		
	}
}

void DrawNumber(char in)
{
	char toWrite = 0;
	switch(in)
	{
		case 0:
			for (int y = 8; y >= 0; y--)
			{
				toWrite = 0;
				for (char i = 0; i < 8; i++)
				{
					toWrite += (zero[y][i] << i);
				}
				
				SetPixel(toWrite);
			}
			break;
		case 1:
			for (int y = 8; y >= 0; y--)
			{
				toWrite = 0;
				for (char i = 0; i < 8; i++)
				{
					toWrite += (one[y][i] << i);
				}
				
				SetPixel(toWrite);
			}
			break;
		case 2:
			for (int y = 8; y >= 0; y--)
			{
				toWrite = 0;
				for (char i = 0; i < 8; i++)
				{
					toWrite += (two[y][i] << i);
				}
				
				SetPixel(toWrite);
			}
			break;
		case 3:
			for (int y = 8; y >= 0; y--)
			{
				toWrite = 0;
				for (char i = 0; i < 8; i++)
				{
					toWrite += (three[y][i] << i);
				}
				
				SetPixel(toWrite);
			}
			break;
		case 4:
			for (int y = 8; y >= 0; y--)
			{
				toWrite = 0;
				for (char i = 0; i < 8; i++)
				{
					toWrite += (four[y][i] << i);
				}
				
				SetPixel(toWrite);
			}
			break;
		case 5:
			for (int y = 8; y >= 0; y--)
			{
				toWrite = 0;
				for (char i = 0; i < 8; i++)
				{
					toWrite += (five[y][i] << i);
				}
				
				SetPixel(toWrite);
			}
			break;
		case 6:
			for (int y = 8; y >= 0; y--)
			{
				toWrite = 0;
				for (char i = 0; i < 8; i++)
				{
					toWrite += (six[y][i] << i);
				}
				
				SetPixel(toWrite);
			}
			break;
		case 7:
			for (int y = 8; y >= 0; y--)
			{
				toWrite = 0;
				for (char i = 0; i < 8; i++)
				{
					toWrite += (seven[y][i] << i);
				}
				
				SetPixel(toWrite);
			}
			break;
		case 8:
			for (int y = 8; y >= 0; y--)
			{
				toWrite = 0;
				for (char i = 0; i < 8; i++)
				{
					toWrite += (eight[y][i] << i);
				}
				
				SetPixel(toWrite);
			}
			break;
		case 9:
			for (int y = 8; y >= 0; y--)
			{
				toWrite = 0;
				for (char i = 0; i < 8; i++)
				{
					toWrite += (nine[y][i] << i);
				}
				
				SetPixel(toWrite);
			}
			break;
		default:
			for (int y = 8; y >= 0; y--)
			{
				toWrite = 0;
				for (char i = 0; i < 8; i++)
				{
					toWrite += (empty[y][i] << i);
				}
				
				SetPixel(toWrite);
			}
			break;
	}
}

// 0b00101010 0b01010100

void Init()
{
	DDRA = 0x0;
	DDRB |= 0b11111111;
	DDRD |= 0b11111111;
	
	PORTD |= 0b10000000;
	
	ADMUX |= 0b01000000;
	ADCSRA |= 0b10000101; //prescaler 128 32?
	//ADMUX |= 0b01000001;
	//ADCSRA |= 0b10000101;
	
	srandom(GetSeed());
}

long GetSeed()
{
	long seed = 0;
	seed += ADCRead(0);
	seed += ADCRead(1);
	
	return seed;
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
	else if (id == 245)
	{
		for(int i = 3; i >= 0; i--)
		{
			out = out << 1;
			out += fill2[row][i];
		}
	}
	return out;
}

void GameOver()
{
	lost = 1;
	
	for (int x = 0; x < 16; x++)
	{
		for (int y = 0; y < 16; y++)
		{
			game[x][y] = gameOver[x][y];
		}
	}
}