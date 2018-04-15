#include <stdio.h>

#include "sensors.h"

int main() {
    sensor_t sensors[8];

    for (int i = 0; i < 8; i++) {
        sensors[i].threshold = 250;
    }

    for (int j = 0; j < 8; j++) { // Criei um for que vai do valor j=0 até j=7 (equivalente ao for superior)
        // Leia os valores, trate-os e envie-os aqui

        sensors[j].leitura = get_value(); //Pega o dado de cada sensor do 0 ao 7
        if (sensors[j].leitura > sensors[j].threshold) {//Questiona se esta no threshold
            send_data(1); //Se sim, envia 1
        } else {
            send_data(0);//Se não, envia 0
        } 

    }


    return 0;
}
