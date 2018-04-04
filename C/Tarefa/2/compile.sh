#!/usr/bin/bash

gcc -c main.c sensors.c -Wall -Wextra
gcc -o tarefa2 main.o sensors.o

rm main.o
rm sensors.o
