#include "utils.h"

/*
 *	Mapeia inteiro especificado de uma escala para outra.
 *
 *  formerValue Valor inteiro especificado
 *  formerMin Valor minimo da escala anterior.
 *  formerMax Valor maximo da escala anterior.
 *  newMin Valor minimo da nova escala.
 *  newMax Valor maximo da nova escala.
 *
 *  retorna o valor mapeado.
 *
 */

int map(int formerValue, int formerMin, int formerMax, int newMin, int newMax) {
	long int newValue;

	newValue = (long int) (formerValue - formerMin) * (newMax - newMin);
	newValue /= (formerMax - formerMin);
	newValue += newMin;

	return (int) newValue;
}
