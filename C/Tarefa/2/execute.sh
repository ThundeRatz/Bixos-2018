#!/usr/bin/bash
gcc -c main.c sensors.c sensors.h
gcc -o tarefa2.exe main.c sensors.c sensors.h

rm main.o sensors.o sensors.h.gch
