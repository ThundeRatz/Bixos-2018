#include <stdio.h>

#include "sensors.h"

int main() {
    sensor_t sensors[8];
    uint8_t bin = 0;

    for (int i = 0; i < 8; i++) {
        sensors[i].threshold = 250;
        sensors[i].leitura = get_value(); //é gerada a leitura do sensor
    }
    for(;;){ //Loop infinito
    // Leia os valores, trate-os e envie-os aqui
    for (int i = 0;i < 8;i++) {
       printf("Sensor %d %d ",i+1,sensors[i].leitura); //mostra o sensor e o valor da leitura
        if(sensors[i].leitura <=250){ //verifica se a leitura está entre 0 e 250, caso verdadeiro adiciona o bit 1
            printf("valor a enviar 1\n");
            bin = (bin << 1); //desloca uma casa para esquerda
            bin = bin | 0b000000001; //faz o ou com o bit 1 já que o valor está dentro do esperado
        }else{//caso o valor não esteja dentro do thresold adiciona 0 ao byte
            printf("valor a enviar 0\n");
            bin = bin << 1;
        }
    }
    send_data(bin); //envia a variável com a condição dos sensores
    }
    return 0;
}
