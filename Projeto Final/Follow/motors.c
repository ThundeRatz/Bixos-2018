#include <avr/io.h>
#include <util/delay.h>
#include "motors.h"
#include "hardware.h"
#include "utils.h"

int formerLeftSpeed = 0, formerRightSpeed = 0;

/*  Inicializa PWMs dos motores
 *
 *	Inicializa as PWMs dos dois motores com a frequência especificada.
 *  Timer/Counter 1 é habilitado como geradores de PWM nos pinos PB1 (OC1A) e PB2 (OC1B)
 *
 *	pwm_frequency Especifica a frequência da PWM do motor
 *
 */

void motors_init(uint8_t pwm_frequency)
{
	// Initialize motor control pins as outputs.
	DDR_MOTOR |= (1<<MOTOR_LF) | (1<<MOTOR_LEN) | (1<<MOTOR_REN) | (1<<MOTOR_LB) | (1<<MOTOR_RB) | (1<<MOTOR_RF);

	// Sets PWMs' duty cycle proportional to OCR1x values and as 8-bit Phase Correct PWM.
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1) | (1<<WGM10);

	// If the desired frequency is either 30, 125, 500, 4k or 32kHz, set PWMs as 8-bit Fast PWM.
    if (pwm_frequency % 2 != 0)
    	TCCR1B |= (1<<WGM12);

    // Sets prescaler according to desired PWM frequency.
    TCCR1B += 1 + pwm_frequency / 2;
}

/*  Ativa os dois motores com as velocidades escolhidas.
 *
 *  Ativa os motores da esquerda e da direita colocando na saida uma PWM com duty cycle
 *  proporcional aos valores de velocidade especificados. Valores positivos são considerados
 *  rotação para frente.
 *
 *	left_speed Especifica a velocidade do motor da esqierda.
 *	right_speed Especifica a  velocidade do motor da direita.
 *
 */

void set_motors(int left_speed, int right_speed)
{
	// Prevents abrupt variations on the motors' speeds.
	if (left_speed > formerLeftSpeed + PWM_STEP)
		left_speed = formerLeftSpeed + PWM_STEP;
	if (left_speed < formerLeftSpeed - PWM_STEP)
		left_speed = formerLeftSpeed - PWM_STEP;

	if (right_speed > formerRightSpeed + PWM_STEP)
		right_speed = formerRightSpeed + PWM_STEP;
	if (right_speed < formerRightSpeed - PWM_STEP)
		right_speed = formerRightSpeed - PWM_STEP;

	// Define direction and magnitude of both motors' rotations.
	if (left_speed >= 0) {
		PORT_MOTOR |= (1<<MOTOR_LF);
		PORT_MOTOR &= ~(1<<MOTOR_LB);

		MOTOR_LPWM = toUChar(left_speed);
	} else {
		PORT_MOTOR &= ~(1<<MOTOR_LF);
		PORT_MOTOR |= (1<<MOTOR_LB);

		MOTOR_LPWM = toUChar(abs(left_speed));
	}

	if (right_speed >= 0) {
		PORT_MOTOR |= (1<<MOTOR_RF);
		PORT_MOTOR &= ~(1<<MOTOR_RB);

		MOTOR_RPWM = toUChar(right_speed);
	} else {
		PORT_MOTOR &= ~(1<<MOTOR_RF);
		PORT_MOTOR |= (1<<MOTOR_RB);

		MOTOR_RPWM = toUChar(abs(right_speed));
	}

	// Updates previous speed values.
	formerLeftSpeed = left_speed;
	formerRightSpeed = right_speed;

	// Small delay between speed updates.
	_delay_ms(PWM_DELAY);
}
