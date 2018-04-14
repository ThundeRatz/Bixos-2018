#!/usr/bin/bash
gcc -c main.c -Wall -Wextra
gcc -s sensors.c -o sensors.o -Wall -Wextra
gcc -o tarefa main.o sensors.o
