# Projeto Final
## Processo Seletivo da Computação - ThundeRatz 2018

Olá de novo! Aqui serão dadas instruções para a última parte do Processo Seletivo da Computação da equipe.

Primeiramente, lembrem-se que essa parte é **em grupo**, então não façam as coisas sozinhos e consultem o resto do grupo antes de tomarem decisões importantes.

A primeira coisa a se fazer é escolher um *fork* desse repositório de algum membro do grupo, o que já deveria ter sido na tarefa anterior, para ser o repositório do grupo, avisem ao seu responsável sobre essa decisão.

Em seguida, leiam as instruções das pastas do Follow e do SumoAuto nos seus respectivos README's e façam um programa para cada um desses robôs.

* Vocês devem usar o GitHub para o compartilhamento e versionamento do código
* Seria legal se fizessem seu próprio Makefile para a compilação do programa
	* Para compilar um programa para AVR:
	```bash
	$ avr-gcc -c arquivo.c -o arquivo.o -mmcu=id_microcontrolador -std=c99 -Wall -Wextra -Os # gerar objetos
	$ avr-gcc -o main.elf <arquivos objeto> -mmcu=id_microcontrolador -std=c99 -Wall -Wextra -Os # gerar o binário
	$ avr-objcopy -j .text -j .data -O ihex main.elf main.hex # gera o hexadecimal para o uC
	```
	* Para gravar na placa:
	```bash
	$ avrdude -c usbasp -p id_microcontrolador -U flash:w:main.hex:i
	```
	O ID do microcontrolador depende do microcontrolador usado no projeto. Por exemplo, se for o ATMega8, esse ID é m8. Se for ATMega32U4, o ID é m32u4.
