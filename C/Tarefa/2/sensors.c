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
    // Desfaçam o empacotamento e imprimam


    for (int i = 0; i < 8; i++){
        printf("Sensor %d: %d \n", i, 1 & (data >> i));
    }
}
