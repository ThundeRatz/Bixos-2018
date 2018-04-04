#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "sensors.h"

static int initialized = 0;
uint8_t valor = 0,q = 0, r = 0;

int get_value() {
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }
    return rand() % 500;
}

void send_data(uint8_t data) {
    // Desfaçam o empacotamento e imprimam
    printf("Dados recebidos com sucesso!\n");
    valor = data;
    
    for (int i = 8; i > 0; i--){//extrai os bits do byte e coloca o valor correspondente de cada sensor
        printf("Sensor %d ",i);
        if((valor / 2) > 0){
            q = valor / 2;
            r = valor % 2;
            valor /=2;
            printf("valor %d \n",r);
           
        }else{
            printf("valor %d \n",q);
        }
    }
}
