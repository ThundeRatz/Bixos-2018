#include <stdio.h>

#include "sensors.h"

int main() {
    sensor_t sensors[8];
    uint8_t data = 0b0;

    for (int i = 0; i < 8; i++) {
        sensors[i].threshold = 250;
    }

    for (int j = 0 ; j<=7 ; j++ ) 
    { 
        sensors[j].leitura = get_value(); //Lê um valor aleatorio
        if(sensors[j].leitura > sensors[j].threshold) 
            data |= (1<<j); //Coloca 1 na posicao do byte correspondente ao sensor
        else
            data &= ~(1<<j);
    }
    //Com o byte já montado, enviar
    send_data(data);

    return 0;
}