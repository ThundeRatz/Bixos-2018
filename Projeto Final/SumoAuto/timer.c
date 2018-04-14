#include <avr/interrupt.h>
#include "timer.h"

volatile uint32_t timer;

ISR(TIMER0_OVF_vect) {
    timer += 32;
}

/* inicializa o timer */
void timer_init() {
    if (((TCCR0A & 0xFF) == 0) && ((TCCR0B & 0xFF) == 0))  // timer 0 nao inicializado 
        TCCR0B = (1 << CS00);  // sem prescaler
    TIMSK0 |= 1 << TOIE0;
    sei();
    timer = 0;
}

/* retorna o tempo que passou desde o incio do programa em microssegundos */
uint32_t get_tick() {
    return timer * 10;
}
