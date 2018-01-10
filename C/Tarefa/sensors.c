/**
 * Processo Seletivo 2017 - sensors.c
 *
 * Equipe ThundeRatz de Robótica
 * 03/2017
 */

#include <avr/io.h>
#include "sensors.h"

void sensors_init() {
    DDRC &= ~((1 << PC0) | (1 << PC1));

    ADMUX  |= (1 << REFS0);
    ADCSRA |= (1 << ADEN) | (1 << ADPS0) | (1 << ADPS2);
}

uint16_t get_sensor(sensor_t sensor) {
	ADMUX = (ADMUX & 0xF8) | sensor;

	ADCSRA |= (1 << ADSC);

	while (ADCSRA & (1 << ADSC));

	return ADC;
}
