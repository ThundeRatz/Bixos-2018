#ifndef SENSORS_H_INCLUDED
#define SENSORS_H_INCLUDED



#endif // SENSORS_H_INCLUDED
#include <stdint.h>

int get_value();
void send_data(uint8_t data);

typedef struct {
    int leitura;
    int threshold;
} sensor_t;
