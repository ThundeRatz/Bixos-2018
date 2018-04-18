#include <stdio.h>

#include "sensors.h"

int main() {
    sensor_t sensors[8];

    for (int i = 0; i < 8; i++) {
        sensors[i].threshold = 250;
    }
    uint8_t byte;
    for (;;) { // Loop infinito
        // Leia os valores, trate-os e envie-os aqui
        byte = 0;
        for (int i = 0; i < 8; i++) {
            sensors[i].leitura = get_value();
            if (sensors[i].leitura > sensors[i].threshold)
                byte = byte | 1 << (7-i); //colocar o 1 na posição correspondente ao i
                //considerei o sensor 0 o que está mais na esquerda e o 7 o mais na direita
        }
        send_data(byte);   
    }
    return 0;
}
