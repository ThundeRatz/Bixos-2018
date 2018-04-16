#ifndef _SENSORS_H
#define _SENSORS_H

#define NUM_SENSORS 7

extern uint16_t sensors[NUM_SENSORS];

typedef enum {
    SENSOR2 = 0,
    SENSOR3,
    SENSOR4,
    SENSOR5,
    SENSOR1,
    SENSOR6 = 6,
    SENSOR7
} sensor_t;

void sensors_init();
void sensors_update();
uint16_t sensor_read(sensor_t sensor);

#endif /* _SENSORS_H */
