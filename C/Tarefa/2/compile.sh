#!/usr/bin/bash
gcc -c main.c -Wall -Wextra
gcc -c sensors.c -Wall -Wextra
gcc -o tarefa main.o sensors.o

rm main.o
rm sensors.o