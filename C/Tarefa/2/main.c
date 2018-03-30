#include <stdio.h>

#include "sensors.h"

int main() {
    sensor_t sensors[8];

    for (int i = 0; i < 8; i++) {
        sensors[i].threshold = 250;
    }

    for (;;) { // Loop infinito
        // Leia os valores, trate-os e envie-os aqui
        sensor[i].leitura = get_value()
        if (sensor[i].leitura > sensor[i].threshold) {
            
        }
    }

    return 0;
}
