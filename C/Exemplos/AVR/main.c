#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

#include "setup.h"

#define LED1_ON()     LED_PORTx |=  (1 << LED1_PIN)
#define LED1_OFF()    LED_PORTx &= ~(1 << LED1_PIN)
#define LED1_TOGGLE() LED_PORTx ^=  (1 << LED1_PIN)

#define LED2_ON()     LED_PORTx |=  (1 << LED2_PIN)
#define LED2_OFF()    LED_PORTx &= ~(1 << LED2_PIN)
#define LED2_TOGGLE() LED_PORTx ^=  (1 << LED2_PIN)

int main() {
	setup();

	LED2_ON();
	for (;;) {
		LED1_TOGGLE();
		_delay_ms(500);
	}
}
