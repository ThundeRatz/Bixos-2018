#pragma once

#include <stdint.h>

int get_value();
void send_data(uint8_t data);

typedef struct {
    int leitura;
    int threshold;
} sensor_t;
