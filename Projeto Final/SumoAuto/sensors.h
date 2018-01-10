#pragma once

/**
 * Includes
 */

extern uint16_t distance[5];

extern uint16_t line[4];

extern uint16_t gyro[3];
extern uint16_t accel[3];

void sensors_init();

void update_distance();
void update_line();
void update_accel();
