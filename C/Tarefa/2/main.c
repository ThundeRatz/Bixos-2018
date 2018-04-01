#include <stdio.h>

#include "sensors.h"

int main() {
    sensor_t sensors[8];

    for (int i = 0; i < 8; i++) {
        sensors[i].threshold = 250;
    }

    for (;;) { // Loop infinito
        // Leia os valores, trate-os e envie-os aqui
        uint8_t byte = 0 << 7;
        for (int i = 0; i < 8; i++) {
            sensors[i].leitura = get_value();
            if (sensors[i].leitura > sensors[i].threshold)
                byte = byte | 1 << (9-i); //colocar o 1 na posição correspondente ao i
                //considerei o sensor 0 o que está mais na esquerda e o 8 o mais na direita
        }
        send_data(byte);   
    }

    return 0;
}
