#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "sensors.h"

static int initialized = 0;

int get_value() {
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }

    return rand() % 500;
}

void send_data(uint8_t data) {
    int v_bit = 0;
    for (int i = 0 ; i < 8 ; i++)
    {
        if((1<<i) & data)
            v_bit = 1;
        else
            v_bit = 0;
        printf("Sensor %d: %d", i,v_bit);
    }
}
