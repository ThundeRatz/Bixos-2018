#include <avr/io.h>
#include "motors.h"
#include "utils.h"

/* inicializa os motores */
void motors_init() {
    DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB4);
    DDRD |= (1 << PD6) | (1 << PD7);

    /* enables */
    PORTB |= (1 << PB4); 
    PORTD |= (1 << PD7);

     /* Fast PWM sem prescaler */
    TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1);
    TCCR0B |= (1 << CS00);

    /* Fast PWM 8 bit sem prescaler - Timer 1 é de 16 bits */
    TCCR1A |= (1 << WGM10) | (1 << COM1A1) | (1 << COM1B1);
    TCCR1B |= (1 << WGM12) | (1 << CS10);

    /* Fast PWM sem prescaler */
    TCCR2A |= (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);
    TCCR2B |= (1 << CS20);
}

/* seta velocidades dos motores (esquerda, direita) */
void motors(int velL, int velR) {
    if (velR >= 0) {
        velR = constrain(velR, 0, 255);
        OCR1A = 0;
        OCR0A = velR;
    } else {
        velR = abs(velR);
        velR = constrain(velR, 0, 255);
        OCR0A = 0;
        OCR1A = velR;
    }

    if (velL >= 0) {
        velL = constrain(velL, 0, 255);
        OCR1B = 0;
        OCR2A = velL;
    } else {
        velL = abs(velL);
        velL = constrain(velL, 0, 255);
        OCR2A = 0;
        OCR1B = velL;
    }
    /*
        Registradores:
        OCR0A, OCR1AL, OCR1AH, OCR1BL, OCR1BH, OCR2A
        motorDir1 = PB3 - 2A
        motorDir2 = PB2 - 1B
        motorEsq1 = PB1 - 1A
        motorEsq2 = PD6 - 0A
    */
}
