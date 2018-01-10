#pragma once

typedef enum {
	ENCODER_L = 0,
	ENCODER_R
} encoder_t;

typedef enum {
	EIXO_X = 0,
	EIXO_Y
    EIXO_Z
} eixo_t;

uint16_t getLineSensor(uint16_t sensor);
int16_t getEncoder(encoder_t enc);
int16_t getAccel(eixo_t eixo);
