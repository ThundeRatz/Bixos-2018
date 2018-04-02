#include <stdio.h>
#include "sensors.h"

int main() {
    sensor_t sensors[8];
    int enviar = 0; 
    for (int i = 0; i < 8; i++) {
        sensors[8].threshold = 250;
    }

    for (;;) { // Loop infinito
        // Leia os valores, trate-os e envie-os aqui
        for (int i = 0; i < 8; i++){
            sensors[i].leitura = get_value(); //Pega os valores
            if (sensors[i].leitura > sensors[i].threshold){   // valor válido
                enviar = enviar + 1 << i;
            }
            else {                                          // não válido
                enviar = enviar + 0 << i;
            }
            
        }
        send_data(enviar);
    }

    return 0;
}
