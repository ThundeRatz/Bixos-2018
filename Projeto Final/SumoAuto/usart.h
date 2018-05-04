/**
 * usart.h
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

#ifndef _USART_H_
#define _USART_H_

#include <avr/io.h>
#include <stdio.h>

// Function prototypes
void usart_init();
void usart_putchar(char c, FILE* stream);
char usart_getchar(FILE* stream);

#endif
