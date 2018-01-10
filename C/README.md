# C

Primeiramente, é importante que já saibam o básico de C, recomendo o seguinte:
* [Learn-C][learnc] - Um tutorial interativo de C, em inglês (Até a parte de Structures);
* [Material de MAC2166][mac2166] - Apostila de MAC2166 (Introdução à Computação de vocês) sobre C.

Além disso, existe o maravilhoso Google e o Stack Overflow =P

Qualquer dúvida podem me perguntar!

---
## Edição
Provavelmente já te mandaram baixar o [Code::Blocks][codeblocks] na aula de MAC2166
para editar e compilar seus códigos em C. É melhor que usem um editor de texto
separado e compilem pelo terminal, assim já treinam linha de comando.
Recomendo o [Atom][atom], que é um editor de texto open-source do GitHub
bem customizável, ou o [VS Code][vscode] ~~mais legal~~, que já tem um
terminal e também é bastante customizável, mas podem usar o Code::Blocks se preferirem.

---
## Organização de Código
Como já deve~~ria~~m saber, essa é a estrutura básica de um programa em C:
```c
#include <stdio.h>       // Isso é um header
// Outros includes
#define CONSTANTE 1
// Outras diretivas de compilador

// Declaração de funções (protótipos)
int func(int a);

int main() {
	// código
}

// Definição de funções
int func(int a) {
	// código
}
```
Mas e se o código for muito grande e/ou tiver muitas funções?
Como organizá-lo e facilitar a manutenção e compreensão? Simples: dividimos o código em vários arquivos!
* Headers - Cabeçalhos, onde ficam as declarações de funções e definições de constantes;
* Sources - Fontes, onde ficam as definições das funções declaradas nos headers.

### Headers
Um header é um arquivo terminado em .h que contém a declaração de funções e,
se necessário, definições de constantes, por exemplo:
```c
//func.h
#pragma once // Essa é uma diretiva que impede esse arquivo de ser processado pelo
			 // compilador mais de uma vez, caso mais de um arquivo o inclua.
// Também se pode incluir outros headers aqui, se forem necesários
#define CONST 10

int func(int a);

```
### Source Files
Um arquivo fonte é um arquivo terminado em .c que contém as definições de funções e a função main, normalmente em seu próprio arquivo, por exemplo:
```c
//func.c
#include "func.h" // Temos que incluir

int func(int a) {
	int b = CONST * a; // Podemos usar CONST, que foi definido no header incluso
	return b;
}
```
---
## Compilação
Programas em C são compilados usando o gcc (GNU Compiler Collection), para instalá-lo:
* Linux (provavelmente já tem, mas para garantir):
```bash
$ apt-get update
$ sudo apt-get install gcc
```
* Windows
 * Primeiro você deve instalar o [mingw-get][mingw-down] (Minimalist GNU for Windows);
 * Vá à [wiki][mingw-wiki] dele na parte de Environment Settings e faça o que está lá;
 * Depois:
 ```
 > mingw-get update
 > mingw-get install gcc
 ```

Para usar o gcc (igual para linux e windows):
* Primeiro deve-se criar os objetos dos arquivos fonte que se deseja compilar:
```bash
$ gcc -c main.c helloworld.c # Gera main.o e helloworld.o
```
* Depois criamos o executável, o nome depois do `-o` é o nome do executável que queremos
(no Windows é bom colocar um .exe no final do nome), podemos omitir o `-o executavel`,
assim o nome será a.out (a.exe no Windows).
```bash
$ gcc -o executavel main.o helloworld.o
```
* É possível resumir esses dois passou em uma única linha fazendo:
```bash
$ gcc -o executavel main.c helloworld.c
```
Isso cria os objetos, usa-os e os apaga, mas isso só em bom quando temos um ou dois arquivos,
se tivermos vários, é melhor o primeiro método, já que se mudarmos algo só precisamos recriar os .o
dos arquivos modificados. Já se tivermos realmente *muitos* arquivos, o melhor é utilizar um Makefile,
como verão na aula de make!
* Também existem [várias flags][gcc-flags] que podem ser colocadas no final dessa linha, como `-Wall`,
que habilita vários warnings úteis. Para uso na guerra, sempre usem `-Wall -Wextra`, que ativam muitos
warnings. Eles geralmente te avisam de qualquer erro facilmente identificável por passagem de tipos errados
e expressões que podem ter efeitos indesejados.

#### Exemplo
Para compilar o programa na pasta Exemplo:
* Linux
```bash
# Na pasta que clonaram o seu fork do repositório dos bixos
~/Bixos-2017$ cd C/PC/Exemplos
# Para compilar
~/Bixos-2017/C/Exemplos$ gcc -o exemplo *.c # Aqui diz "todos os arquivos terminados em .c na pasta atual"
# Para executar
~/Bixos-2017/C/Exemplos$ ./exemplo
```
* Windows
```
C:\Bixos-2017> cd C\PC\Exemplos
C:\Bixos-2017\C\Exemplos> gcc -o exemplo.exe *.c
C:\Bixos-2017\C\Exemplos> exemplo.exe
```
---
## AVR
Bom, o que vocês viram acima vale para programas feitos para rodarem em um terminal no computador, mas e nos robôs, como funciona?

Os códigos também são escritos em C, mas tem alguns pontos específicos, já que vão rodar num microcontrolador. Primeiramente, o compilador é uma versão do gcc feita especificamente para os microcontroladores da Atmel, o avr-gcc, para tê-lo em seu computador basta instalar o [WinAvr][win-avr] ou, no Linux, fazer:

```bash
$ sudo apt-get update
$ sudo apt-get install gcc build-essential
$ sudo apt-get install gcc-avr gdb-avr binutils-avr avr-libc avrdude # talvez o nome dos pacotes seja diferente na sua distribuição, mas é bem fácil de achar na internet
```

Além disso, existem algumas flags especiais que precisam ser setadas para o compilador saber qual o microcontrolador alvo: `-mmcu=<microcontrolador>` (usamos `-mmcu=atmega168` em boa parte das placas).

Outra coisa bastante presente na programação em C para microcontroladores é o uso de números binários e alguns operadores úteis para trabalhar com eles (essa sintaxe é válida para programas em C comuns, não está limitada a AVR) e a manipulação de *registradores*.

Para representar um número binário, basta colocar `0b` antes do número, por exemplo, o número 107 em binário seria `0b01101011` ~~olhei no google a conversão~~. Também é possível usar números hexadecimais, que tem `0x` antes (107 seria `0x6B`), cada número hexadecimal representa um número binário de 4 bits (0b0000 = 0x0 = 0 a 0x1111 = 0xF = 15).

Ok, mas por que é necessário usar números binários? Num microcontrolador, vamos mexer em bits individuais de seus registradores, não entrarei muito a fundo nisso, mas darei um exemplo rápido: Uma porta do uC tem 8 pinos e é representada por três registradores e cada um "tem" um byte (8 bits), um bit pra cada pino, se eu ligar um LED no pino PB3 (Pino 3 da Porta B) precisarei mexer assim:

```c
#include <avr/io.h> // Header principal, tem as definições de portas e pinos

int main() {
	DDRB = 0b00001000; // Data Direction Register B, ativar o bit diz que o pino é de saída
	PORTB = 0b00001000; // Ativar o bit "liga" a saída, acendendo o LED

	for (;;) {} // Loop infinito
}
```
Mas ficar escrevendo esses número binários é muito chato, então existem uns operadores úteis, o primeiro é o bit-shift (`<<` ou `>>`) que faz o shift de um número, ou seja, desloca os bits dele na direção desejada um certo número de vezes, por exemplo:
```c
1 << 6 = 0b1000000 // Desloquei o umero 1 6 vezes para a esquerda
0b101 << 3 = 0b101000
0b1001 >> 2 = 0b0010 // Aqui desloquei para a direita, assim perco bits menos significativos
```
Com isso podemos setar bits em registradores muito mais fácil, por exemplo, se eu quiser fazer como no exemplo, poderia fazer `DDRB = (1 << 3)` ou, usando as definições de pino `DDRB = (1 << PB3)`.

Outros operadores importantes são os operadores lógicos bit a bit *ou* e *e* (`|`e `&`, não confundam com `||`e `&&`), com eles podemos fazer operações lógicas em números binários, por exemplo `0b0110 | 0b1100 = 0b1110` e `0b0110 & 0b1100 = 0b0100`, o operador *ou* deixa cada bit resultante em 1 se em qualquer um dos numeros houver um 1 na posição e o operador *e* deixa em 1 somente se nos dois números houver um 1 na posição. Então, se eu quiser ligar dois pinos do uC posso fazer: `DDRB = (1 << PB3) | (1 << PB4)`, por exemplo.

Bom, não entrarei em mais detalhes sobre isso nessa aula, existem muitas possibilidades, e vocês não vão mexer muito com essa parte mais baixo nível no PS, mas se quiserem aprender mais sobre essa parte, podem nos procurar e aparecer na gaiola que mostramos!

---

Se tiverem *qualquer* dúvida, não hesitem em nos perguntar, seja pessoalmente ou pelo [fórum][forum], estamos aqui para ensinar!


[learnc]: http://www.learn-c.org/
[mac2166]: http://www.ime.usp.br/~hitoshi/introducao/
[codeblocks]: http://www.codeblocks.org/
[atom]: https://atom.io/
[vscode]: https://code.visualstudio.com/
[forum]: http://forum.thunderatz.org/
[mingw-down]: http://sourceforge.net/projects/mingw/files/
[mingw-wiki]: http://www.mingw.org/wiki/getting_started
[gcc-flags]: https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html
[win-avr]: http://winavr.sourceforge.net/index.html
