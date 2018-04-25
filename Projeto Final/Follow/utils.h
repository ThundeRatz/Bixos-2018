#ifndef _UTILS_H
#define _UTILS_H

#define abs(x)		(((x) > 0) ? (x) : -(x))
#define toUChar(x)	((uint8_t) ((x) > 255) ? 255 : (x))

int map(int value, int formerMin, int formerMax, int newMin, int newMax);

#endif /* _UTILS_H */
