# Make
---
make é umas das ferramentas que usamos no desenvolvimento de software. O programa é bastante usado grandes projetos que envolvam processamento de muitos arquivos, não apenas em software. Trataremos aqui de um exemplo simples que será expandido até poder ser usado em um projeto simples em C.

## Propósito

Muitas vezes em um projeto, um programa depende de muitos arquivos. Imagine que a compilação para gerar um programa demora muito tempo, uma hora por exemplo. Se você perceber um erro em um arquivo e quiser gerar um novo executável, o que fazer? Gerar o projeto inteiro de novo e esperar outra hora? Outra opção seria procurar manualmente quais arquivos dependem do que foi modificado e gerá-los novamente. Nenhuma das duas opções é muito atraente, já que a primeira é desnecessariamente demorada e a segunda é susceptível a erros.

O programa make automatiza a **busca por dependências**. Quando um arquivo é modificado, apenas ele e os arquivos que dependem dele serão recompilados. Para isso, a pasta do projeto onde se deve usar make possui um arquivo especial, chamado Makefile, que indica as configurações do projeto.

## Estrutura

Cada entrada de um Makefile possui a seguinte estrutura:

```make
alvo: requisitos
	receita
```

O alvo indica o nome do alvo que você quer especificar. Os requisitos indicam o que precisa ser feito antes do alvo, ou seja, do que ele depende. A "receita" (recipe) indica comandos para gerar o alvo. Trechos após caracteres "#" são comentários (são ignorados).

Tudo pode parecer um pouco obscuro por enquanto, mas vamos a um exemplo prático simples: imagine que você está escrevendo um texto que está dividido em vários arquivos. Os arquivos podem possuir anotações suas sobre o texto e não devem sair na versão final.

O Makefile a seguir deverá:

* Pegar 2 arquivos, 1.txt e 2.txt e gerar versões deles sem as anotações, 1_processado.txt e 2_processado.txt (linhas que começam com "NOTE" são consideradas anotações).
* Juntar as versões em um arquivo final, texto.txt.

As regras de 1.txt e 2.txt terão a seguinte aparência:

```
1_processado.txt: 1.txt
	sed '/^NOTE/d' 1.txt > 1_processado.txt
```

Significando:

* A primeira linha mostra que 1_processado.txt depende de 1.txt. Se você editar o seu arquivo fonte (com comentários), o processado vai ser gerado novamente.
* A segunda linha usa o comando **sed**. Ele vai remover linhas que comecem com "NOTE" e salvar em 1_processado.txt. sed é um comando um pouco mais avançado e não é tão importante agora, tente focar no significado do Makefile (se 1.txt for modificado, será chamado um comando para gerar 1_processado.txt novamente).

A regra do texto final será a seguinte:
```
texto.txt: 1_processado.txt 2_processado.txt
	cat 1_processado.txt 2_processado.txt > texto.txt
```

Significando:

* Se 1_processado.txt ou 2_processado.txt forem modificados, texto.txt será gerado novamente.
* A segunda linha une os conteúdos de 1_processado.txt e 2_processado.txt em texto.txt.

O Makefile completo está no arquivo Makefile_1. Tente compreendê-lo antes de continuar. Executar *make -f Makefile_1* irá gerar o texto.txt. Você pode editar 1.txt e 2.txt e ver que apenas os arquivos necessários são gerados novamente (ao editar 1.txt, 1_processado.txt e texto.txt serão atualizados, mas 2_processado.txt não).

## Alvos especiais

Makefiles geralmente possuem alguns alvos especiais, como **all** e **clean**. Apenas esses dois serão tratados aqui. all instrui a compilar todos os programas que o Makefile possui, e clean a limpar todos os arquivos intermediários criados. Por exemplo:

```make
all: texto.txt

clean:
	rm 1_processado.txt 2_processado.txt texto.txt
```

Os alvos acima significam:

* Ao chamar o alvo all, texto.txt tem que estar gerado. Se ele não estiver atualizado, ele vai ser gerado.
* Ao chamar clean, os arquivos intermediários serão removidos.

Teste com o arquivo Makefile_2: *make -f Makefile_2 all* e *make -f Makefile_2 clean*.

## PHONY

Um problema do Makefile_2 é que não tem como o make diferenciar alvos como all e clean de alvos de arquivos (texto.txt, por exemplo). Se houver um arquivo chamado clean na pasta do projeto, chamar *make -f Makefile_2 clean* irá resultar em:

```
make: 'clean' is up to date.
```

make irá detectar se não houve mudança no arquivo clean e irá deixá-lo de lado. Para all e clean, desejamos que eles sempre sejam executados, sem verificação se existe um arquivo com esse nome.

O comando .PHONY faz exatamente isso, instruíndo arquivos que não devem ter sua modificação verificada. Adicionar no Makefile **.PHONY: all clean** terá o efeito desejado. Ao criar um arquivo chamado clean, o Makefile_3 continuará funcionando.

Um Makefile um pouco mais avançado está no arquivo Makefile dessa pasta. Ele usa algumas variáveis automáticas e uma variável para o comando de remoção de anotações. Recomenda-se a leitura do [manual de make](http://www.gnu.org/software/make/manual/make.html), pelo menos os capítulos 1 e 2 (Overview of make e An Introduction to Makefiles), que mostram o básico da criação de Makefiles.

O arquivo c/Makefile mostra um exemplo simples para um projeto em C. As regras de objetos estão sem as receitas porque make possui regras prontas para eles.
