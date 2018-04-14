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
    int k=1, i=0; //cria dois contadores
	
    for (i=7; i>=0; i--){
	printf ("Sensor %d: %d\n", k, (data&1)); //k imprime o número do sensor, enquanto data&1 utiliza o operador lógico and para verificar se o bit mais significativo de data é 1, caso contrário, retornará 0. A ideia é de que, na utilização em um robô, bastaria enviar o valor de data&1 ao invés de utilizar o printf.
	data = data>>1; //shifta data para a direita de forma a descartar o bit mais significativo, sendo assim, o próximo bit a direita (correpondente ao próximo sensor) será analisado e, no final, data estará reinicializado como 0
	k+=1;
    }
}
