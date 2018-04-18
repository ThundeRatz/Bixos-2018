#include <stdio.h>

#include "sensors.h"

int main() {
    sensor_t sensors[8];

    for (int i = 0; i < 8; i++) {
        sensors[i].threshold = 250;
    }

    for ( ; ; ) { // Loop infinito
        uint8_t data = 0;
        // Leia os valores, trate-os e envie-os aqui
        for(int i = 0; i < 8; i++){
            sensors[i].leitura = get_value();
            if(sensors[i].leitura >= sensors[i].threshold){
                data |= (1 << i);
            }
        }
        send_data(data);
    }

    return 0;
}
