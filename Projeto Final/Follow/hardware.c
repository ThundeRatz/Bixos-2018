#include <avr/io.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include "hardware.h"
#include "motors.h"
#include "sensors.h"
#include "timer.h"

/*  Inicialização do hardware.
 *
 *  Inicializa pinos usados para controlar o botão, os LEDs e os motores
 * 
 *  Desabilita operação do watchdog timer
 * 
 *  Inicializa geradores de PWM com frequência de 32kHz
 *
 */

void hardware_init() {
	// Disable watchdog timer.
	MCUSR &= ~(1<<WDRF);
	wdt_reset();
	wdt_disable();

	// Initialize LED control pins as outputs.
	DDR_LED |= (1<<LED_BLUE) | (1<<LED_RED) | (1<<LED_YELLOW);

	// Initialize sensors.
	sensors_init();

	// Initialize timer.
	timer_init();

	// Initialize PWM generator at 32kHz.
	motors_init(PWM_32K);

	// Small delay for changes to be applied.
	_delay_ms(100);
}

/*  Controla estado do LED.
 *
 * 	Desliga, liga ou inverte os estado do LED (especificado pela cor)
 *
 *  color Especifica cor do LED a ser controlado.
 *	action Especifica novo estado do LED (ON, OFF ou TOGGLE).
 *
 */

 void led_control(uint8_t color, uint8_t action) {
 	// Apply action to an LED according to specifications.
 	switch (action) {
 		case OFF:
 			PORT_LED &= ~(((color == BLUE)<<LED_BLUE) | ((color == RED)<<LED_RED) | ((color == YELLOW)<<LED_YELLOW));
 			break;
 		case ON:
 			PORT_LED |= ((color == BLUE)<<LED_BLUE) | ((color == RED)<<LED_RED) | ((color == YELLOW)<<LED_YELLOW);
 			break;
 		case TOGGLE:
 			PORT_LED ^= ((color == BLUE)<<LED_BLUE) | ((color == RED)<<LED_RED) | ((color == YELLOW)<<LED_YELLOW);
 			break;
 		default:
 			break;
 	}
 }
