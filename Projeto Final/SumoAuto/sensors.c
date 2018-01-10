#include "sensors.h"

uint16_t distance[5] = { 0 };

uint16_t line[5] = { 0 };

uint16_t gyro[3] = { 0 };
uint16_t accel[3] = { 0 };

void sensors_init() {
	/**
	 Faz as inicializações necessarias para
	 os sensores funcionarem
	*/
}

void update_distance() {
	/**
	 Atualiza o valor de leitura dos sensores
	 de distancia no vetor distance.

	 distance[0] -> sensor lateral esquerdo
	 distance[1] -> sensor frontal esquerdo
	 distance[2] -> sensor frontal central
	 distance[3] -> sensor frontal direito
	 distance[4] -> sensor lateral direito

	 O valor de cada sensor varia de 0 a 1023,
	 sendo 0 o valor ideal para nada sendo visto e
	 1023 muito próximo.
	*/
}

void update_line() {
	/**
	 Atualiza o valor de leitura dos sensores
	 de linha no vetor line.

	 line[0] -> sensor do canto superior esquerdo
	 line[1] -> sensor do canto superior direito
	 line[2] -> sensor do canto inferior direito
	 line[3] -> sensor do canto inferior esquerdo

	 O valor de cada sensor varia de 0 a 1023,
	 sendo 0 o valor ideal para preto e 1023
	 para branco.
	*/

}

void update_accel() {
	/**
	 Atualiza o valor de leitura do sensor
	 de seis eixos nos vetores gyro e accel

	 gyro[0] -> rotação no eixo X
	 gyro[0] -> rotação no eixo Y
	 gyro[0] -> rotação no eixo Z

	 accel[0] -> aceleração no eixo X
	 accel[0] -> aceleração no eixo Y
	 accel[0] -> aceleração no eixo Z

	 Sendo X o eixo que aponta apara a frente do robô,
	 Y o eixo que aponta para a esquerda e Z para cima.

	 O valor de cada sensor varia de 0 a 1023,
	 sendo 0 o valor ideal para preto e 1023
	 para branco.
	*/
}
