#ifndef SENSORS_H
#define SENSORS_H

#include <avr/io.h>

extern uint16_t line_sensors[2];
extern uint16_t distance_sensors[2];

typedef enum {
    LEFT,
    RIGHT
} sensor_t;

void sensors_init();
void update_line_sensors();
void update_distance_sensors();

#endif