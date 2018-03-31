#!/usr/bin/bash

gcc -ansi -c main.c sensors.c -Wall -Wextra
gcc -o tarefa2 main.o sensors.o