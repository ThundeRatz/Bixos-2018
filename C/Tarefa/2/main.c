#include <stdio.h>

#include "sensors.h"



int main() {
    sensor_t sensors[8];
    

    for (int i = 0; i < 8; i++) {
        sensors[8].threshold = 250;
    }

    for (;;) { // Loop infinito
        // Leia os valores, trate-os e envie-os aqui
        uint8_t data = 0b0
        for(int i = 0; i < 8; i++){
            sensors[i].leitura = get_value();
            data << 1 //shift
            data =  data + (sensors[i].leitura>sensors[i].threshold)//retorna um binário
        }                                                               //se são válidos ou não
        send_data(data)
    }

    return 0
}
