#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "hardware.h"
#include "motors.h"
#include "sensors.h"
#include "utils.h"
#include "timer.h"


int main(void) {
	hardware_init();
	for (;;) {

	}
	return 0;
}
