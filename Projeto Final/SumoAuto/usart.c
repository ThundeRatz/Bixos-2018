/**
 * usart.c
 * Implementation of usart communication for
 * debugging purposes.
 *
 * Daniel Nery Silva de Oliveira
 * ThundeRatz Robotics Team - http://thunderatz.org
 *
 * 20 Apr 2016
 *
 * See http://www.appelsiini.net/2011/simple-usart-with-avr-libc
 */

#include <stdlib.h>
#include <ctype.h>
#include "usart.h"

// Baud Rate for serial communication
#define BAUD 9600
#include <util/setbaud.h>

static FILE usart_output = FDEV_SETUP_STREAM(usart_putchar, NULL, _FDEV_SETUP_WRITE);
static FILE usart_input = FDEV_SETUP_STREAM(NULL, usart_getchar, _FDEV_SETUP_READ);

// usart initialization
void usart_init() {
	// Configures baud rate, parity, etc
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

#if USE_2X
	UCSR0A |= (1 << U2X0);
#else
	UCSR0A &= ~(1 << U2X0);
#endif

	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8N1
	UCSR0B |= (1 << TXEN0) | (1 << RXEN0); // Activates transmission and reception

	stdout = &usart_output;
	stdin = &usart_input;
}

// Sends a byte (char)
void usart_putchar(char c, FILE* stream) {
	if (c == '\n')
        usart_putchar('\r', stream);

	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = c;
}

// Receives a byte (char)
char usart_getchar(FILE* stream) {
	while(!(UCSR0A & (1 << RXC0)));
	return UDR0;
}
