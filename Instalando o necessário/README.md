# Instalando o necessário

Para realizar as tarefas do Processo Seletivo, é necessário instalar algumas coisas antes.
* GCC;
* Make;
* Git;
* Pacotes do AVR.

Explicaremos o que são essas coisas mais tarde.

## Instruções para instalar

### Windows

No Windows, instale o [MSYS2][msys2] e siga as instruções da página de download.
Após realizar todos os passos da página, podemos instalar pacotes pelo terminal do MSYS2, usando o comando:

`pacman -S <pacote1> <pacote2> ... <pacoteN>`

Assim, para instalar o que é necessário para o Processo Seletivo (que também é necessário para a equipe), basta utilizar o comando:

`pacman -S gcc make git`

Obs.: Os pacotes do AVR não estão disponíveis no MSYS2, é necessário instalar de outra forma que será explicada depois.

Após isso, é preciso colocar a pasta do msys2 nas variáveis de ambiente do Windows. Para isso, faça:
1. Pesquise variáveis de ambiente e clique em "Editar as variáveis de ambiente do sistema". Ou, vá para Painel de Controle > Sistema e Segurança > Sistema > Configurações avançadas do sistema.
2. Na janela que abriu, clique em "Variáveis de ambiente".
3. Na parte de "Variáveis do sistema", encontra a variável Path, selecione-a e clique em "Editar".
4. Clique em "Novo".
5. Digite o caminho para os executáveis MSYS2, normalmente C:\msys64\usr\bin.
6. Clique em "OK".

Agora abra o Prompt de Comando para testar se os pacotes foram instalados corretamente.
Para testar se gcc foi instalado corretamente, digite:

`gcc -v`

Algo parecido com isso deve aparecer no seu prompt de comando:

```
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-pc-msys/6.4.0/lto-wrapper.exe
Target: x86_64-pc-msys
Configured with: /msys_scripts/gcc/src/gcc-6.4.0/configure --build=x86_64-pc-msys --prefix=/usr --libexecdir=/usr/lib --enable-bootstrap --enable-shared --enable-shared-libgcc --enable-static --enable-version-specific-runtime-libs --with-arch=x86-64 --with-tune=generic --disable-multilib --enable-__cxa_atexit --with-dwarf2 --enable-languages=c,c++,fortran,lto --enable-graphite --enable-threads=posix --enable-libatomic --enable-libcilkrts --enable-libgomp --enable-libitm --enable-libquadmath --enable-libquadmath-support --enable-libssp --disable-win32-registry --disable-symvers --with-gnu-ld --with-gnu-as --disable-isl-version-check --enable-checking=release --without-libiconv-prefix --without-libintl-prefix --with-system-zlib --enable-linker-build-id --with-default-libstdcxx-abi=gcc4-compatible
Thread model: posix
gcc version 6.4.0 (GCC)
```

Para testar se make foi instalado corretamente, digite:

`make -v`

Algo parecido com isso deve aparecer no seu prompt de comando:

```
GNU Make 4.2.1
Built for x86_64-pc-msys
Copyright (C) 1988-2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
```

Para testar se git foi instalado corretamente, digite:

`git --version`

Algo parecido com isso deve aparecer no seu prompt de comando:

```
git version 2.15.0
```

Para instalar os pacotes do AVR, instale o [WinAVR][win-avr]. Durante a instação, certifique-se que a opção "Add directories to PATH" esteja selecionada.

Edite a variável de ambiente Path novamente, movendo o diretório do MSYS para cima dos diretórios do WinAVR.

Para verificar se os pacotes de AVR foram instalados corretamente, digite, no prompt de comando:

`avr-gcc --version`

Algo parecido com isso deve aparecer no seu prompt de comando:

```
avr-gcc (WinAVR 20100110) 4.3.3
Copyright (C) 2008 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

### Linux
No Linux, instale os pacotes utilizando os seguintes comandos no terminal:

#### Ubuntu
```bash
$ sudo apt update
$ sudo apt install gcc build-essential make git gcc-avr gdb-avr binutils-avr avr-libc avrdude
```

#### Fedora
```bash
$ sudo dnf upgrade
$ sudo dnf install gcc make git avr-gcc avr-gdb avr-binutils avr-libc avrdude
```

#### Arch Linux
```bash
$ sudo pacman -Syu
$ sudo pacman -S gcc make git avr-gcc avr-gdb avr-binutils avr-libc avrdude
```

Há outras distribuições do Linux com gerenciadores de pacotes diferentes. Com uma pesquisa rápida no Google
você consegue encontrar a forma equivalente para instalar os pacotes na sua distribuição.

Quaisquer dúvidas ou problemas, podem nos procurar.

[msys2]: http://www.msys2.org/
[win-avr]: http://winavr.sourceforge.net/index.html
