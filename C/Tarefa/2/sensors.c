#include <stdlib.h>
#include <stdint.h>
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
    // Desfaçam o empacotamento e imprimam
    int pacote = data;
    int aux;                                 
    for (int i = 0; i < 8; i++){          
        aux = data % 10;                       // pega o valor do sensor
        data = data / 10;                      //elimina o valor desse sensor
        printf("Sensor %d: %d", i, aux);
    }
}
