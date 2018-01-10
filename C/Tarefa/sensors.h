/**
 * Processo Seletivo 2017 - sensors.c
 *
 * Equipe ThundeRatz de Robótica
 * 03/2017
 */

#pragma once

typedef enum {
	SENSOR_LE = 0,
	SENSOR_FE,
	SENSOR_FD = 6,
	SENSOR_LD
} sensor_t;

void sensors_init();
uint16_t get_sensor(sensor_t sensor);
