#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "hardware.h"
#include "motors.h"
#include "sensors.h"
#include "utils.h"


int main(void) {
	hardwareInit();
	for (;;) {
		
	}
	return 0;
}
