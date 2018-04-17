#ifndef TIMER_H
#define TIMER_H

#include <avr/io.h>

void timer_init();
uint32_t get_tick();

#endif  // TIMER_H
