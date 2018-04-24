#ifndef _MOTORS_H
#define _MOTORS_H

#define PWM_15  	0
#define PWM_30  	1
#define PWM_60  	2
#define PWM_125 	3
#define PWM_250 	4
#define PWM_500 	5
#define PWM_2K  	6
#define PWM_4K  	7
#define PWM_16K		8
#define PWM_32K 	9

#define PWM_STEP	25
#define PWM_DELAY	10

void motors_init(uint8_t pwm_frequency);
void set_motors(int left_speed, int right_speed);

#endif /* _MOTORS_H */
