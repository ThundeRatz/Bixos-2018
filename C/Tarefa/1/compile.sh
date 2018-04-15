#!/usr/bin/bash
gcc -std=c99 -c main.c -o main.o -Wall -Wextra
gcc -o tarefa1 main.o

rm main.o
