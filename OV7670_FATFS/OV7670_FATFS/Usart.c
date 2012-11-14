/*
 * Usart.c
 *
 * Created: 25/10/2012 22:25:04
 *  Author: hl13g10@ecs.soton.ac.uk
 */ 


#include "Usart.h"


void USART0_Init()
{
	uint16_t ubrr = UBBR;
	//Set baud rate
	UBRR0H = (unsigned char)(ubrr >>8);
	UBRR0L = (unsigned char)ubrr ;
	//Enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	UCSR0C = 0x06; //set asynchronous, no parity, one stop bit, 8 bit transfer.
	
	//UCSR0B |= (1 << RXCIE0) | (1 << TXCIE0); //set RX and TX interrupt on
}
void Usart_SendChar(char data) 
{
    // Wait for empty transmit buffer
    while ( !(UCSR0A & (1 << UDRE0)) );
    // Start transmission
    UDR0 = data; 
}
unsigned char Usart_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Get and return received data from buffer */
	return UDR0;
}
int Usart_printf(char var, FILE *stream) {
    // translate \n to \r for br@y++ terminal
    if (var == '\n') Usart_SendChar('\r');
    Usart_SendChar(var);
    return 0;
}

void Usart_get_line (char *buff, int len)
{
	char c;
	int i = 0;


	for (;;) {
		c = Usart_Receive();
		if (c == '\r') break;
		if ((c == '\b') && i) {
			i--;
			Usart_SendChar(c);
			continue;
		}
		if (c >= ' ' && i < len - 1) {	/* Visible chars */
			buff[i++] = c;
			Usart_SendChar(c);
		}
	}
	buff[i] = 0;
	Usart_SendChar('\n');
}