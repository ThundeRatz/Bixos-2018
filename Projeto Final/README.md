# Projeto Final
## Processo Seletivo da Computação - ThundeRatz 2017

Olá de novo! Aqui serão dadas instruções para a última parte do Processo Seletivo da Computação da equipe.

Primeiramente, lembrem-se que essa parte é **em grupo**, então não façam as coisas sozinhos e consultem o resto do grupo antes de tomarem decisões importantes.

A primeira coisa a se fazer é esoclher um *fork* desse repositório de algum membro do grupo, o que já deveria ter sido na tarefa anterior, para ser o repositório do grupo, avisem ao seu responsável sobre essa decisão.

Em seguida, escolham entre Sumô Autônomo e Seguidor de Linha, cada um deles tem mais detalhes sobre seu funcionamento e o que o seu programa deve/pode fazer nos READMEs de suas respectivas pastas.

Escolhido o robô, leiam as informações na pasta dele e façam o programa da melhor forma que conseguirem, lembrando que:
* Vocês devem usar o github para o compartilhamento e versionamento do código
* Seria legal se fizessem seu próprio Makefile para a compilação do programa
	* Para compilar um programa para AVR:
	```bash
	$ avr-gcc -c arquivo.c -o arquivo.o -mmcu=m8 -std=c99 -Wall -Wextra -Os # gerar objetos
	$ avr-gcc -o main.elf <arquivos objeto> -mmcu=m8 -std=c99 -Wall -Wextra -Os # gerar o binário
	$ avr-objcopy -j .text -j .data -O ihex main.elf main.hex # gera o hexadecimal para o uC
	```
	* Para gravar na placa:
	```bash
	$ avrdude -c usbasp -p m168 -U flash:w:main.hex:i
	```
