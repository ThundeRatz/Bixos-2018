#include <avr/interrupt.h>
#include "timer.h"

volatile uint32_t timer;

ISR(TIMER2_OVF_vect) {
    timer += 32;
}

/* inicializa o timer */
void timer_init() {
    TCCR2B = (1 << CS20);  // sem prescaler
    TIMSK2 |= 1 << TOIE2;
    sei();
    timer = 0;
}

/* retorna o tempo que passou desde o incio do programa em milissegundos */
uint32_t get_tick() {
    return timer / 1000;
}
