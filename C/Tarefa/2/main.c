#include <stdio.h>

#include "sensors.h"

int main() {
    sensor_t sensors[8];
    uint8_t data = 0b0;
    int j =0;

    for (int i = 0; i < 8; i++) {
        sensors[i].threshold = 250;
    }

    for (;;) 
    { 
        if(j == 8)
        {
            send_data(data); //Com o byte já montado, enviar
            j = 0; //Resetar as leituras
        }
        sensors[j].leitura = get_value(); //Lê um valor aleatorio
        if(sensors[j].leitura > sensors[j].threshold) 
            data |= (1<<j); //Coloca 1 na posicao do byte correspondente ao sensor
        else
            data &= ~(1<<j);
            
        j++;
    }
    
    

    return 0;
}