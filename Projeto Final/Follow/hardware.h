#ifndef _HARDWARE_H
#define _HARDWARE_H

#include <avr/io.h>

#define MOTOR_LF	PB0
#define MOTOR_LEN	PB1
#define MOTOR_REN	PB2
#define MOTOR_LB	PB3
#define MOTOR_RF	PB4
#define MOTOR_RB	PB5

#define MOTOR_LPWM	OCR1A
#define MOTOR_RPWM	OCR1B

#define PORT_MOTOR	PORTB
#define DDR_MOTOR	DDRB

#define LED_BLUE	PD5
#define LED_RED		PD6
#define LED_YELLOW	PD7

#define PORT_LED	PORTD
#define DDR_LED		DDRD

#define BLUE 		0
#define RED 		1
#define YELLOW 		2

#define OFF			0
#define ON			1
#define TOGGLE 		2

#define BUTTON		PD4

#define PORT_BUTTON	PORTD
#define DDR_BUTTON	DDRD
#define PIN_BUTTON	PIND

void hardwareInit(void);
void ledControl(unsigned char color, unsigned char action);
unsigned char buttonPressed(void);

#endif /* _HARDWARE_H */