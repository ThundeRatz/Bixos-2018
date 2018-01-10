/**
 * Processo Seletivo 2017 - motors.c
 *
 * Equipe ThundeRatz de Robótica
 * 03/2017
 */

#include <avr/io.h>
#include "motors.h"

void motors_init() {
	//PWMS

    //PD3 = OC1A, PD5 = OC0B, PD6 = OC0A
    DDRD = (1 << PD3) | (1 << PD5) | (1 << PD6); //Configura PD3, PD5 e PD6 como saída
    //PB3 = MOSI/OC1B
    DDRB = (1 << PB3); //Configura PB3

	//Inicializa PWMs
    TCCR0A |= (1 << COM0A1) | (1 << COM0B1) | (1 << WGM00); //COM -> habilita como geradores de PWM. WGM modo fast PWM
    TCCR0B |= (1 << CS01); //Frequencia do timer das PWMs, Clk/8
    MOTDT = MOTDF = 0; // Motores comecam zerados

    TCCR2A |= (1 << COM2A1) | (1 << COM2B1) | (1 << WGM20);
    TCCR2B |= (1 << CS21);
    MOTET = MOTEF = 0;
}

void motors(int16_t velE, int16_t velD) {
	if (velE < 0){
		MOTET = -velE;
		MOTEF = 0;
	} else {
		MOTET = 0;
		MOTEF = velE;
	}

	if (velD < 0){
		MOTDT = -velD;
		MOTDF = 0;
	} else {
		MOTDT = 0;
		MOTDF = velD;
	}
}
