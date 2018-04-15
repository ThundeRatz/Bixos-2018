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
 *	pwmFrequency Especifica a frequência da PWM do motor
 *
 */

void motorsInit(unsigned char pwmFrequency)
{
	// Initialize motor control pins as outputs.
	DDR_MOTOR |= (1<<MOTOR_LF) | (1<<MOTOR_LEN) | (1<<MOTOR_REN) | (1<<MOTOR_LB) | (1<<MOTOR_RB) | (1<<MOTOR_RF);

	// Sets PWMs' duty cycle proportional to OCR1x values and as 8-bit Phase Correct PWM.
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1) | (1<<WGM10);

	// If the desired frequency is either 30, 125, 500, 4k or 32kHz, set PWMs as 8-bit Fast PWM.
    if (pwmFrequency % 2 != 0)
    	TCCR1B |= (1<<WGM12);

    // Sets prescaler according to desired PWM frequency.
    TCCR1B += 1 + pwmFrequency / 2;
}

/*  Ativa os dois motores com as velocidades escolhidas.
 *
 *  Ativa os motores da esquerda e da direita colocando na saida uma PWM com duty cycle
 *  proporcional aos valores de velocidade especificados. Valores positivos são considerados
 *  rotação para frente.
 *
 *	leftSpeed Especifica a velocidade do motor da esqierda.
 *	rightSpeed Especifica a  velocidade do motor da direita.
 *
 */

void setMotors(int leftSpeed, int rightSpeed)
{
	// Prevents abrupt variations on the motors' speeds.
	if (leftSpeed > formerLeftSpeed + PWM_STEP)
		leftSpeed = formerLeftSpeed + PWM_STEP;
	if (leftSpeed < formerLeftSpeed - PWM_STEP)
		leftSpeed = formerLeftSpeed - PWM_STEP;

	if (rightSpeed > formerRightSpeed + PWM_STEP)
		rightSpeed = formerRightSpeed + PWM_STEP;
	if (rightSpeed < formerRightSpeed - PWM_STEP)
		rightSpeed = formerRightSpeed - PWM_STEP;

	// Define direction and magnitude of both motors' rotations.
	if (leftSpeed >= 0) {
		PORT_MOTOR |= (1<<MOTOR_LF);
		PORT_MOTOR &= ~(1<<MOTOR_LB);

		MOTOR_LPWM = toUChar(leftSpeed);
	} else {
		PORT_MOTOR &= ~(1<<MOTOR_LF);
		PORT_MOTOR |= (1<<MOTOR_LB);

		MOTOR_LPWM = toUChar(abs(leftSpeed));
	}

	if (rightSpeed >= 0) {
		PORT_MOTOR |= (1<<MOTOR_RF);
		PORT_MOTOR &= ~(1<<MOTOR_RB);

		MOTOR_RPWM = toUChar(rightSpeed);
	} else {
		PORT_MOTOR &= ~(1<<MOTOR_RF);
		PORT_MOTOR |= (1<<MOTOR_RB);

		MOTOR_RPWM = toUChar(abs(rightSpeed));
	}

	// Updates previous speed values.
	formerLeftSpeed = leftSpeed;
	formerRightSpeed = rightSpeed;

	// Small delay between speed updates.
	_delay_ms(PWM_DELAY);
}
