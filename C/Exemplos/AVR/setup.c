#include <avr/io.h>
#include "setup.h"

void setup() {
	LED_DDRx |= (1 << LED1_PIN);
	LED_DDRx |= (1 << LED2_PIN);

	LED_PORTx &= ~(1 << LED1_PIN);
	LED_PORTx &= ~(1 << LED2_PIN);
}


