#include <stdio.h>

#include "sensors.h"

int main() {
    sensor_t sensors[8];

    for (int i = 0; i < 8; i++) {
        sensors[i].threshold = 250;
    }

    for (;;) { // Loop infinito
        // Leia os valores, trate-os e envie-os aqui
        uint8_t dados = 0b0;

        for(int i= 0; i < 8; i++){
            sensors[i].leitura = get_value(); //pegando os valores para cada sensor
            dados << 1 ; //shift
            dados = dados | (sensors[i].leitura > sensors[0].threshold); //atribuindo os binários
        }
        send_data(dados);
    }

    return 0;
}
