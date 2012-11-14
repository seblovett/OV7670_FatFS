/*
 * Config.c
 * 
 * Contains Global Methods and initialisations
 * 
 * Created: 25/10/2012 21:59:06
 *  Author: hslovett
 */ 

#include "Config.h"

void IO_Init(void)
{
	//initialise timer 0 to interrupt every 10 ms
	TIMSK0 |= (1 << OCIE0A);
	TCCR0A |= (1 << WGM01);
	OCR0A = 117; //10ms interrupt at 12MHz
	TCCR0B |= (1 << CS02) | (1 << CS00);
	sei();
}