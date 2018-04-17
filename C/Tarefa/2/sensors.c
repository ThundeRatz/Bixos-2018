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
    int valor = 0;

    for (int i = 0; i < 8; i++)
    {
        if((1<<i) & data) //Verifica se o valor da posicao i eh 1
            valor = 1;
        else              //Caso contrario, valor eh 0
            valor = 0;
        printf("Sensor %d: %d\n", i, valor);
    }
}
