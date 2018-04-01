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
    //printf("%d\n",data);
    uint8_t res;
    for (int i = 0; i < 8; i++) {
        res = data >> (7-i); //Mover a o número correspondendo ao sensor[i] para a direita (o máximo possível)
        res = res & 1 << 0; //verificar se esse número é 0 ou 1
        printf("Sensor %d: %d\n", i, res);
    }    
}
