#include <stdio.h>

#include "sensors.h"

int main() {
    sensor_t sensors[8];
    int j = 0;
    uint8_t data;

    for (int i = 0; i < 8; i++) {
        sensors[i].threshold = 250;
    }

    for (;;) { 
        if(j == 8) // byte já está montado 
        {
            send_data(data);
            break;
        }
        sensors[j].leitura = get_value(); //Recebe valores aleatórios
        if (sensors[j].leitura > sensors[j].threshold)
            data |= (1<<j); //montando o byte com valor 1 onde a leitura do "sensor" foi maior que o treshold
        


        j++;
    }

    return 0;
}
