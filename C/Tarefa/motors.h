/**
 * Processo Seletivo 2017 - motors.h
 *
 * Equipe ThundeRatz de Robótica
 * 03/2017
 */

#pragma once

#define MOTDF OCR0B //Motores direita para frente
#define MOTEF OCR2B //Motores esquerda para frente
#define MOTDT OCR0A //Motores direita para Tras
#define MOTET OCR2A //Motores esquerda para tras

void motors_init();
void motors(int16_t velE, int16_t velD);
