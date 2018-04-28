#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "utils.h"
#include "sensors.h"
#include "motors.h"
#include "timer.h"

#define SPEED 255
#define TURN_SPEED 128

int main () {
    motors_init();
    timer_init();
    sensors_init();
	
	int flag = 0;
	
    for (;;) {
		update_distance_sensors();
		if(distance_sensors[LEFT] || distance_sensors[RIGHT]){
			flag = 1;
		}
		else{
			flag = 0;
		}
		
		if(flag){
			motors(SPEED, SPEED);
		}
		else{
			motors(TURN_SPEED,-TURN_SPEED);
		}
    }
    return 0;
}