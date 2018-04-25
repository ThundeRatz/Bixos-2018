#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "hardware.h"
#include "motors.h"
#include "sensors.h"
#include "utils.h"
#include "timer.h"


int main(void) {
	int velL = 0,velR = 0;
	hardware_init();
	sensors_init();
	sensors_update();
	motors_init(frequencia);//passar frequencia
	set_motors(velL,velR);
	for (;;) {
		if(sensors[3] > 500){//virar esquerda
			while(sensors[3]<500){
				velL-=2;
				set_motors(velL,velR);//mudar a velocidade dos motores para fazer a rotação à esquerda
			}
		}else if(sensors[5] > 500){//virar direita
			while(sensors[5]<500){
				velR-=2;
				set_motors(velL,velR);//mudar a velocidade dos motores para fazer a rotação à direita
			}
		}else{//Iguala as velocidades depois de rotacionar
			if(velL > velR){
				velR = velL;
			}else if(velR > velL){
				velL = velR
			}
		}
		sensors_update();
	}
	return 0;
}
