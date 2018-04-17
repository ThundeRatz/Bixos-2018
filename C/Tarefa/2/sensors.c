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
    int i=0;
	
    for (i=0; i<8; i++){
	printf ("Sensor %d: %d\n", (i+1), (data%2)); /*data%2 imprime o bit 
						       menos significativo de 
						       data*/

	data = data/2; //divide data por 2 para shiftar o binário para a direita
    }
}
