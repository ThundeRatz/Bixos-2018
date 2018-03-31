#include <stdio.h>

#include "sensors.h"


/* char aggregator(int* vetor){
	int i;
	char ret=0;
	for(i=0;i<8;i++){
		ret = ret | 1<<(7-i);
	}
	return ret;
} */

unsigned char validar(sensor_t* sensores){
	int i;
	unsigned char ret=0;
	
	for(i=0;i<8;i++){
		if(sensores[i].leitura > sensores[i].threshold){
			ret = ret | (1<<(7-i));
		}
		
	}
	return ret;
}

int main() {
    sensor_t sensors[8];
	int i;

    for (i = 0; i < 8; i++) {
        sensors[i].threshold = 250;
    }

    for (;;) { /*Loop infinito
        Leia os valores, trate-os e envie-os aqui */
		for(i=0;i<8;i++){
			sensors[i].leitura = get_value();
			/* printf("[%d , %d] ", i, sensors[i].leitura); */
		}
		/* printf("\n"); */
		send_data((uint8_t)validar(sensors));
    }

    return 0;
}

