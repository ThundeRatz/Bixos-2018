#!/usr/bin/bash

gcc -c main.c -o main.o -Wall -Wextra
gcc -o tarefa1 main.o

rm main.o
