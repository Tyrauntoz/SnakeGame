//https://www.eit.lth.se/fileadmin/eit/courses/datablad/Display/GDM12864H.pdf
//PORTB 0-7 = DB 0-7
//PORTD 0 = cs2, 1 = cs1, 2 = reset, 3 = read write, 4 = data & instruction, 5 = chip enable
#include <avr/io.h>
#define F_CPU 8000000UL
#ifndef DISPLAYOPERATIONS_H_
#define DISPLAYOPERATIONS_H_

void StartDisplay();
void TurnOffDisplay();

//lower display, 65-128
void cs2Low();
void cs2High();

//upper display, 0-64
void cs1Low();
void cs1High();

void ResetLow();
void ResetHigh();

void rwHigh();
void rwLow();

void rsHigh();
void rsLow();

void eHigh();
void eLow();

void WriteData();
void WaitForDisplay();
void ReadOn();
void ReadOff();
void Screen1();
void Screen2();

void SetX();
void SetY();
void SetPixel(char in);
void WipeScreen();


// e low skriver data till skärmen, high -> low = skriva data
#endif