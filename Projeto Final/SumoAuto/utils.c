#include "utils.h"

/* mapeia um valor de um intervalo para outro intervalo */
int map(int formerValue, int formerMin, int formerMax, int newMin, int newMax) {
    long int newValue;

    newValue = (long int) (formerValue - formerMin) * (newMax - newMin);
    newValue /= (formerMax - formerMin);
    newValue += newMin;

    return (int)newValue;
}
