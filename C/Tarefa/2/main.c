#include <stdio.h>
#include "sensors.h"

int main(){
    uint8_t data = 0b00000000; //cria um int de tamanho 1 byte através da biblioteca stdint.h, incluída dentro de sensors.h
    sensor_t sensors[8]; //cria um vetor de 8 structs do tipo  sensor_t

    for (int i = 0; i < 8; i++) {
        sensors[i].threshold = 250; //atribui a metade do valor ao threshold
	sensors[i].leitura = get_value(); //atribui aleatoriamente um valor a cada sensor de leitura
    }

    for (int i = 0; i<8; i++) {
	if (sensors[i].leitura > sensors[i].threshold)
	    data = data + 1; //se o valor lido pelo sensor for maior do que a metade (threshold), soma 1 ao int data
	data = data << 1; //shifta os bits de data uma vez para a esquerda, de forma que na próxima vez o número 1 (ou manter o 0) possa ser adicionado ao bit menos significativo
    }

    send_data(data);

    return 0;
}
