#ifndef UTILS_H
#define UTILS_H

#define constrain(x, a, b) ((x) < (a) ? (a) : ((x) > (b) ? (b) : (x)))
#define abs(x) ((x) < 0 ? -(x) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

int map(int formerValue, int formerMin, int formerMax, int newMin, int newMax);

#endif