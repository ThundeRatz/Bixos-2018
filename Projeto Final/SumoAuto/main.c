#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "utils.h"
#include "sensors.h"
#include "motors.h"
#include "timer.h"

int main () {
    motors_init();
    timer_init();
    sensors_init();
    for (;;) {

    }
    return 0;
}