/**
 * Processo Seletivo 2017 - main.c
 *
 * Equipe ThundeRatz de Robótica
 * 03/2017
 */

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "sensors.h"
#include "motors.h"

int main() {
	sensors_init();
	motors_init();
	sei();
	wdt_reset();
	wdt_disable();

	for (;;) {
		if (get_sensor(SENSOR_FD) < 500)
			motors(255, 255);
		else
			motors(-100, -100);

		_delay_ms(10);
	}

	return 0;
}
