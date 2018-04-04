#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>

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
    /*Desfacam o empacotamento e imprimam*/
    int i;
    
    for (i = 0; i < 8; i++){
        printf("Sensor %d: %d\n", i, (data>>(7-i))&1);
    }
}

