#import <stdio.h>
#import <stdlib.h>
#import <string.h>
#import <math.h>

#define MAXLINHA   400
#define MAXCOLUNA  400
#define JANELA_MAX 50
#define JANELA_MIN 3
#define MAX_NAME   256

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif                 /*faltava essa linha,por comparação ao #ifdef min*/

int copia[MAXLINHA][MAXCOLUNA];

typedef struct {
    int linha, coluna;
} posicao;

posicao compara(int a[MAXLINHA][MAXCOLUNA], int b[MAXLINHA][MAXCOLUNA], int linhasA, int linhasB, int colunasA, int colunasB, int i,int j);

void imprimeMatriz(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas,int i,int j);
void menu();
void troca(int* a, int* b);

int media(int media[JANELA_MAX*JANELA_MAX], int tam,int k);
int min(int mininimizar[JANELA_MAX*JANELA_MAX], int tam, int k);
int max(int maximizar[JANELA_MAX*JANELA_MAX], int tam,int k);
int maiorvalor (int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas,int i,int j);

int le_pgm(char* prefixo_do_nome, int m[MAXLINHA][MAXCOLUNA], int *linhas, int* colunas, int* maiorValor,int i,int j);
int grava_pgm(char* prefixo_do_nome, int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int maiorValor,int i,int j);

void negativo(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas,int i,int j);
void rebatimentoVertical(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas,int i,int j);
void rebatimentoHorizontal(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas,int i,int j);
void rotacao(int m[MAXLINHA][MAXCOLUNA], int* linhas, int* colunas,int i,int j);
void corte(int m[MAXLINHA][MAXCOLUNA], int* linhas, int* colunas, int xsup, int ysup, int xinf, int yinf,int i,int j);
void filtroMediana(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela,int i,int j,int k,int l);
void filtroMedia(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela,int i,int j,int k,int l);
void filtroErosao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela,int k,int j,int i,int l);
void filtroDilatacao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela,int i,int j,int k,int l);
void limiarizacao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas,int i,int j, int k);
void filtroBorda1(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k,int i,int j,int l);
void filtroBorda2(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k,int i,int j,int l);
void filtroBorda3(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k,int i,int j,int l);

void main(int argc, char *argv[]) {
    char prefixo_arquivo_out[MAX_NAME - 4];
    int imagem[MAXLINHA][MAXCOLUNA];
    int linhas, colunas, maiorValor, check, larguraJanela, k, limiteValido = 0;
    const char comandos[] = "nrvhedmz123xctgCas";
    char comando = 0;
    int flag = 0;     /*faltava ;*/
    int i;
    int j;
    if (argc < 2) {
        printf("Usage: %s <arquivo entrada>\n", argv[0]);
        exit(0);
    }

    if (le_pgm(argv[1], imagem, &linhas, &colunas, &maiorValor, i, j)) {
        printf("Arquivo %s.pgm carregado com sucesso.\n", argv[1]);
    } else {
        exit(0);
    }

    strcpy(prefixo_arquivo_out, argv[1]);
    void menu();

    while (comando != 's') {
        printf("Digite um comando: ");
        scanf(" %c", &comando);

        if (!strchr (comandos, comando)) {
            printf("Comando invalido\n");
            continue;
        }

        for (i = 4; i < 11; i++) {                /*declaração da variável estava dentro do loop*/
            if (comando == comandos[i]) {
                larguraJanela = 0;
                while (larguraJanela < JANELA_MIN || larguraJanela > JANELA_MAX) {
                    printf("Digite o tamanho da janela: ");
                    scanf("%d", &larguraJanela);
                    if (larguraJanela < JANELA_MIN || larguraJanela > JANELA_MAX) {
                        printf("Tamanho invalido. A janela deve ser entre %d e %d.\n", JANELA_MIN);
                    }
                }
            }
        }

        if (comando == '1' || comando == '2' || comando == '3') {
            printf("Informe o valor de k: ");
            scanf("%d", &k);   /*faltava ;*/
        }

        if (comando = 'n') negativo(imagem, linhas, colunas, i, j);
        if (comando = 'r') rotacao(imagem, &linhas, &colunas, i, j);
        if (comando = 'v') rebatimentoVertical(imagem, linhas, colunas, i, j);
        if (comando = 'h') rebatimentoHorizontal(imagem, linhas, colunas, i, j);
        if (comando = 'e') filtroErosao(imagem, linhas, colunas, larguraJanela, k, j, i, l);
        if (comando = 'd') filtroDilatacao(imagem, linhas, colunas, larguraJanela, i, j, k, l);
        if (comando = 'm') filtroMediana(imagem, linhas, colunas, larguraJanela, i, j, k, l);
        if (comando = 'z') filtroMedia(imagem, linhas, colunas, larguraJanela, i, j, k, l);
        if (comando = '1') filtroBorda1(imagem, linhas, colunas, larguraJanela, k, i, j, l);
        if (comando = '2') filtroBorda2(imagem, linhas, colunas, larguraJanela, k, i, j, l);
        if (comando = '3') filtroBorda3(imagem, linhas, colunas, larguraJanela, k, i, j, l);
        if (comando = 'a') menu();

        if (comando == 'c') {
            check = 0;
            while (!check) {
                printf("Digite o nome do arquivo de entrada: ");
                scanf("%s", argv[1]);
                if ((check = le_pgm(argv[1], imagem, &linhas, &colunas, &maiorValor, i, j)))
                    printf("Arquivo %s.pgm carregado com sucesso.\n\n", argv[1]);
            }
            strcpy(prefixo_arquivo_out, argv[1]);
            flag = 0;
        }

        if (comando == 't') {
            imprimeMatriz(imagem, linhas, colunas, i, j);
            printf("\n");
        }

        if (comando == 'x') {
            int xsup, ysup, xinf, yinf;
            printf("Informe x superior: ");
            scanf("%d", &xsup);
            printf("Informe y superior: ");
            scanf("%d", &ysup);
            printf("Informe x inferior: ");
            scanf("%d", &xinf);
            printf("Informe y inferior: ");
            scanf("%d", &yinf);
            if (xsup < 0 || ysup < 0 || xinf >= linhas || yinf >= colunas || xsup > xinf || ysup > yinf) limiteValido = 0;
            else limiteValido = 1;
            if (limiteValido) {
                corte(imagem, &linhas, &colunas, xsup, ysup, xinf, yinf, i, j);
                if (!flag) {
                    strcat(prefixo_arquivo_out, "-");
                    flag = 1;
                }
                strncat(prefixo_arquivo_out, &comando, 1);
                printf("Operacao realizada com sucesso.\n");
            } else {
                printf("Limites invalidos\n\n");
            }
        }

        if (comando == 'g') {
            grava_pgm(prefixo_arquivo_out, imagem, linhas, colunas, maiorValor, i, j);
            printf("%s.pgm\n", prefixo_arquivo_out);
            printf("Arquivo %s.pgm gravado com sucesso.\n", prefixo_arquivo_out);
        }

        if (comando == 'C') {
            int c[MAXLINHA][MAXCOLUNA];
            int linhasC, colunasC, maiorValorC;
            char prefixo_arquivo_c[MAX_NAME - 4];
            posicao erro;
            check = 0;
            while (!check) {
                printf("Digite o nome do arquivo com a imagem a ser comparada: ");
                scanf("%s", prefixo_arquivo_c);
                check = le_pgm(prefixo_arquivo_c, c, &linhasC, &colunasC, &maiorValorC, i, j);
            }

            erro = compara(imagem, c, linhas, linhasC, colunas, colunasC, i, j);

            if (erro.linha == -2 && erro.coluna == -2) {
                printf("As matrizes sao iguais\n");
            } else if (erro.linha == -1 && erro.coluna == -1) {
                printf("As matrizes tem dimensoes diferentes\n");
            } else {
                printf("As matrizes tem valores diferentes na posicao %d, %d\n", erro.linha, erro.coluna);
            }
        }

        for (i = 0; i < 11; i++) {       /*problema similar ao da linha 85*/
            if (comando == comandos[i]) {
                if (flag == 0) {
                    strcat(prefixo_arquivo_out, "-");
                    flag = 1;
                }
                strncat(prefixo_arquivo_out, &comando, 1);
                printf("Operacao realizada com sucesso.\n");
            }
        }
    }
    return 0;
}

void imprimeMatriz(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int i,int j) {
    for (i = 0; i < linhas; i++) {       /*problema similar ao da linha 85*/
        for (j = 0; j < colunas; j++) {  /*problema similar ao da linha acima*/
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

void menu() {
    printf("c - carga\n");
    printf("t - exibicao na tela\n");
    printf("n - negativo\n");
    printf("r - rotacao\n");
    printf("v - rebatimento vertical\n");
    printf("h - rebatimento horizontal\n");
    printf("x - corte\n");
    printf("e - filtro da erosao\n");
    printf("d - filtro da dilatacao\n");
    printf("m - filtro da mediana\n");
    printf("z - filtro da media\n");
    printf("1 - filtro de bordas 1\n");
    printf("2 - filtro de bordas 2\n");
    printf("3 - filtro de bordas 3\n");
    printf("g - gravacao\n");
    printf("C - comparacao\n");
    printf("a - ajuda\n");
    printf("s - sair\n\n");
}

void troca(int* a,int* b) {       /*troca estava definida para ponteiros,nessa linha isso não era respeitado*/
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordena(int ordenar[JANELA_MAX*JANELA_MAX], int tam,int k,int l) {
    for (k = 0; k < tam; k++) {                        /*problema similar ao da linha 85*/
        for (l = 1; l < tam - k; l++) {                /*problema similar ao da linha acimna*/
            if (ordenar[k] > ordenar[k + l]) {
                troca(&ordenar[k], &ordenar[k + l]);
            }
        }
    }
}

int media(int mediar[JANELA_MAX*JANELA_MAX], int tam,int k) {
    int soma = 0;
    for (k = 0; k < tam; k++) {       /*Problema similar ao da linha 85*/
        soma += mediar[k];
    }
    return soma/tam;
}

int min(int minimizar[JANELA_MAX*JANELA_MAX], int tam,int k) {
    int minimo = minimizar[0];
    for (k = 1; k < tam; k++) {       /*variável declarada no loop for*/
        if (minimo > minimizar[k]) {
            minimo = minimizar[k];
        }
    }
    return minimo;
}

int max(int maximizar[JANELA_MAX*JANELA_MAX], int tam,int k) {
    int maximo = maximizar[0];
    for (k = 1; k < tam; k++) {           /*Variável declarada no loop for*/
        if (maximo < maximizar[k]) {
            maximo = maximizar[k];
        }
    }
    return maximo;
}

int maiorvalor (int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas,int i,int j) {
    int maior = 0;
    for (i = 0; i < linhas; i++) {           /*variável declarada no loop for*/
        for (j = 0; j < colunas; j++) {      /*Problema similar ao apresentado acima*/
            if (maior < m[i][j]) {
                maior = m[i][j];
            }
        }
    }
    return maior;
}

posicao compara(int a[MAXLINHA][MAXCOLUNA], int b[MAXLINHA][MAXCOLUNA], int linhasA, int linhasB, int colunasA, int colunasB,int i,int j) {
    posicao erro;
    if (linhasA != linhasB || colunasA != colunasB) {
        erro.linha = erro.coluna = -1;
        return erro;
    }

    for (i = 0; i < linhasA; i++) {               /*Variável declarada no loop for*/
        for (j = 0; j < colunasA; j++) {      /*Variável declarada no loop for*/
            if (a[i][j] != b[i][j]) {
                erro.linha = i;
                erro.coluna = j;
                return erro;
            }
        }
    }

    erro.linha = erro.coluna = -2;
}

int le_pgm(char* prefixo_do_nome, int m[MAXLINHA][MAXCOLUNA], int *linhas, int* colunas, int* maiorValor,int i,int j) {
    FILE *arq;
    char key[128];
    int aux;
    char fname[MAX_NAME];

    strcpy(fname, prefixo_do_nome);
    strcat(fname,".pgm");

    arq = fopen(fname, "r");
    if (arq == NULL) {
        printf("Erro na abertura do arquivo %s\n",fname);
        return 0;
    }

    aux = fscanf(arq, "%s", key);
    if (aux != 1) {
        printf("Erro na leitura do arquivo %s \n",fname);
        return 0;
    }
    if (strcmp(key, "P2") != 0) {
        printf("Formato desconhecido\n");
        fclose(arq);
        return 0;
    }
    aux = fscanf(arq, "%d %d %d", colunas, linhas, maiorValor);
    if (aux != 3) {
        printf("Formato incorreto\n");
        fclose(arq);
        return 0;
    }

    for (i = 0; i < *linhas; i++) {           /*Variável declarada no loop for*/
        for (j = 0; j < *colunas; j++) {      /*Problema similar ao da linha acima*/
            fscanf(arq, "%d", &m[i][j]);
        }
    }
    fclose(arq);

    return 1;
}

int grava_pgm(char* prefixo_do_nome, int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int maiorValor,int i,int j) {
    FILE *arq;
    char fname[MAX_NAME];

    strcpy(fname, prefixo_do_nome);
    strcat(fname,".pgm");

    arq = fopen(fname, "w");
    if (arq == NULL) {
        printf("Erro na abertura do arquivo %s\n",fname);
        return 0;
    }

    fprintf(arq, "P2\n");
    fprintf(arq, "%d %d\n%d\n", colunas, linhas, maiorValor);

    for (i = 0; i < linhas; i++) {               /*Variável declarda no loop for*/
        for (j = 0; j < colunas; j++) {          /*Problema similar ao da linha acima*/
            fprintf(arq, "%d ", m[i][j]);
        }
        fprintf(arq, "\n");
    }
    fclose(arq);
    return 1;
}

void negativo(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas,int i,int j) {
    for (i = 0; i < linhas; i++) {           /*Variável declarada no loop for*/
        for (j = 0; j < colunas; j++) {      /*Problema similar ao da linha acima*/
            m[i][j] = 255 - m[i][j];
        }
    }
}

void rebatimentoVertical(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas,int i,int j) {
    for (i = 0; i < linhas; i++) {           /*Variável declarada no loop for*/
        for (j = 0; j < colunas/2; j++) {    /*Problema similar ao da linha acima*/
            troca(&m[i][j], &m[i][colunas - j - 1]);
        }
    }
}

void rebatimentoHorizontal(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas,int i,int j) {
    for (i = 0; i < linhas/2; i++) {          /*Variável declarada no loop for*/
        for (j = 0; j < colunas; j++) {       /*Problema similar ao da linha acima*/
            troca(&m[i][j], &m[linhas - i - 1][j]);
        }
    }
}

void rotacao(int m[MAXLINHA][MAXCOLUNA], int* linhas, int* colunas,int i,int j) {
    int maior = *linhas > *colunas ? *linhas : *colunas;
    for (i = 0; i < maior; i++) {            /*Variável declarada no loop for*/
        for (j = i; j < maior; j++) {        /*Problema similar ao da linha acima*/
            troca(&m[i][j], &m[j][i]);
        }
    }
    troca(linhas, colunas);
    rebatimentoVertical(m, *linhas, *colunas, i, j);
}

void corte(int m[MAXLINHA][MAXCOLUNA], int* linhas, int* colunas, int xsup, int ysup, int xinf, int yinf,int i,int j) {
    *linhas = xinf - xsup + 1;
    *colunas = yinf - ysup + 1;
    for (i = 0; i < *linhas; i++) {
        for (j = 0; j < *colunas; j++) {
            m[i][j] = m[xsup + i][ysup + j];
        }
    }
}

void filtroMediana(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela,int i,int j,int k,int l) {
    int  n;
    int vizinhanca[JANELA_MAX*JANELA_MAX];
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            copia[i][j] = m[i][j];
        }
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            n = 0;
            for (k = i - larguraJanela/2; k <= i + larguraJanela/2; k++) {    /*Faltava ; entre os comandos e a condição*/
                for (l = j - larguraJanela/2; l <= j + larguraJanela/2; l++) {
                    if (k >= 0 && l >= 0 && k < linhas && l < colunas) {
                        vizinhanca[n] = copia[k][l];
                        n++;
                    }
                }
            }
             void ordena(vizinhanca, n);                   /*Faltava Void*/
            m[i][j] = n % 2 == 0 ? vizinhanca[(n - 1)/2 + 1] : vizinhanca[(n - 1)/2];
        }
    }
}

void filtroMedia(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela,int i,int j,int k,int l) {
    int n;
    int vizinhanca[JANELA_MAX*JANELA_MAX];
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            copia[i][j] = m[i][j];
        }
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            n = 0;
            for (k = i - larguraJanela/2; k <= i + larguraJanela/2; k++) {
                for (l = j - larguraJanela/2; l <= j +  larguraJanela/2; l++) {
                    if (k >= 0 && l >= 0 && k < linhas && l < colunas) {
                        vizinhanca[n] = copia[k][l];
                        n++;
                    }
                }
            }
            m[i][j] = media(vizinhanca, n, k);
        }
    }
}

void filtroErosao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela,int k,int j,int l,int i) {
    int n;
    int vizinhanca[JANELA_MAX*JANELA_MAX];
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            copia[i][j] = m[i][j];
        }
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            n = 0;
            for (k = i - larguraJanela/2; k <= i + larguraJanela/2; k++) {
                for (l = j - larguraJanela/2; l <= j +  larguraJanela/2; l++) {
                    if (k >= 0 && l >= 0 && k < linhas && l < colunas) {
                        vizinhanca[n] = copia[k][l];
                        n++;
                    }
                }
            }
            m[i][j] = min(vizinhanca, n, k);
        }
    }
}

void filtroDilatacao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela,int i,int j,int k,int l) {
    int n;
    int vizinhanca[JANELA_MAX*JANELA_MAX];
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            copia[i][j] = m[i][j];
        }
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            n = 0;
            for (k = i - larguraJanela/2; k <= i + larguraJanela/2; k++) {
                for (l = j - larguraJanela/2; l <= j +  larguraJanela/2; l++) {
                    if (k >= 0 && l >= 0 && k < linhas && l < colunas) {
                        vizinhanca[n] = copia[k][l];
                        n++;
                    }
                }
            }
            m[i][j] = max(vizinhanca, n, k);
        }
    }
}

void limiarizacao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int i, int j,int k) {
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            m[i][j] = m[i][j] >= k ? 255 : 0;
        }
    }
}

void filtroBorda1(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k,int i,int j,int l) {
    int E[MAXLINHA][MAXCOLUNA];
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            E[i][j] = m[i][j];
        }
    }
    filtroDilatacao(m, linhas, colunas, larguraJanela, i, j, k, l);
    filtroErosao(E, linhas, colunas, larguraJanela, k, j, l, i);

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            m[i][j] -= E[i][j];
        }
    }

    limiarizacao(m, linhas, colunas, i, j, k);
}

void filtroBorda2(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k,int i,int j, int l) {
    int E[MAXLINHA][MAXCOLUNA];
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            E[i][j] = m[i][j];
        }
    }
    filtroErosao(E, linhas, colunas, larguraJanela, k, j, l, i);

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            m[i][j] -= E[i][j];
        }
    }

    limiarizacao(m, linhas, colunas, i, j, k);
}

void filtroBorda3(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k,int i,int j, int l) {
    int D[MAXLINHA][MAXCOLUNA];
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            D[i][j] = m[i][j];
        }
    }

    filtroDilatacao(D, linhas, colunas, larguraJanela, i, j, k, l);

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            m[i][j] = D[i][j] - m[i][j];
        }
    }

    limiarizacao(m, linhas, colunas, i, j, k);
}
