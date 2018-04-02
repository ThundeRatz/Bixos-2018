#!/usr/bin/bash
gcc -c main.c -o main.o -Wall -Wextra
gcc -c sensors.c -o sensors.o -Wall -Wextra
gcc -o tarefa main.o sensors.o
