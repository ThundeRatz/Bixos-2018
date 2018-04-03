#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include "sensors.h"

static int initialized = 0;

int get_value() {
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }

    return rand() % 500;
}

void send_data(uint8_t data) {
    // Desfaçam o empacotamento e imprimam
    int valores[8];
    
    for (int i = 0; i < 8 ; i++){
        uint8_t mascara = 0b1;
        uint8_t valor;
        
        mascara = mascara << (7-i); //usando máscara
        valor = data & mascara; //determinando qual o resultado da operação logica
        if (valor != 0){
            valores[i] = 1;
        }
        else 
        {
            valores[i] = 0;
        }
        
    }
    
    for (int i = 0; i < 8; i++){
        printf("Sensor %d: %d \n", i, valores[i] );

    }
}
