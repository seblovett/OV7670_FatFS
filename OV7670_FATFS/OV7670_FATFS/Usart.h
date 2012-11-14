/*
 * Usart.h
 *
 * Created: 25/10/2012 22:25:14
 *  Author: hslovett
 */ 


#ifndef USART_H_
#define USART_H_

#include "Config.h"
#include <stdio.h>
#include <avr/io.h>
#define USART0_BITRATE 57600
#define UBBR F_CPU/16/USART0_BITRATE-1

void USART0_Init ();
void Usart_SendChar(char data);
unsigned char Usart_Receive( void );
int Usart_printf(char var, FILE *stream);
void Usart_get_line (char *buff, int len);
// void USART0_SendChar( unsigned char data );
// unsigned char USART0_Receive( void );
// void USART0_SendString(char str[]);

#endif /* USART_H_ */