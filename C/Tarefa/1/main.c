#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
#endif

int copia[MAXLINHA][MAXCOLUNA];

typedef struct {
    int linha, coluna;
} posicao;

posicao compara(int a[MAXLINHA][MAXCOLUNA], int b[MAXLINHA][MAXCOLUNA], int linhasA, int linhasB, int colunasA, int colunasB);

void imprimeMatriz(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas);
void menu();
void troca(int* a, int* b);

int media(int media[JANELA_MAX*JANELA_MAX], int tam);
int min(int mininimizar[JANELA_MAX*JANELA_MAX], int tam);
int max(int maximizar[JANELA_MAX*JANELA_MAX], int tam);
int maiorvalor (int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas);

int le_pgm(char* prefixo_do_nome, int m[MAXLINHA][MAXCOLUNA], int *linhas, int* colunas, int* maiorValor);
int grava_pgm(char* prefixo_do_nome, int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int maiorValor);

void negativo(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas);
void rebatimentoVertical(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas);
void rebatimentoHorizontal(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas);
void rotacao(int m[MAXLINHA][MAXCOLUNA], int* linhas, int* colunas);
void corte(int m[MAXLINHA][MAXCOLUNA], int* linhas, int* colunas, int xsup, int ysup, int xinf, int yinf);
void filtroMediana(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela);
void filtroMedia(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela);
void filtroErosao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela);
void filtroDilatacao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela);
void limiarizacao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int k);
void filtroBorda1(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k);
void filtroBorda2(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k);
void filtroBorda3(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k);

void main(int argc, char *argv[]) {
    char prefixo_arquivo_out[MAX_NAME - 4];
    int imagem[MAXLINHA][MAXCOLUNA];
    int linhas, colunas, maiorValor, check, larguraJanela, k, limiteValido = 0;
    const char comandos[] = "nrvhedmz123xctgCas";
    char comando = 0;
    int flag = 0;

    if (argc < 2) {
        printf("Usage: %s <arquivo entrada>\n", argv[0]);
        exit(0);
    }

    if (le_pgm(argv[1], imagem, &linhas, &colunas, &maiorValor)) {
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

        for (int i = 4; i < 11; i++) {
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
            scanf("%d", &k);
        }

        if (comando = 'n') negativo(imagem, linhas, colunas);
        if (comando = 'r') rotacao(imagem, &linhas, &colunas);
        if (comando = 'v') rebatimentoVertical(imagem, linhas, colunas);
        if (comando = 'h') rebatimentoHorizontal(imagem, linhas, colunas);
        if (comando = 'e') filtroErosao(imagem, linhas, colunas, larguraJanela);
        if (comando = 'd') filtroDilatacao(imagem, linhas, colunas, larguraJanela);
        if (comando = 'm') filtroMediana(imagem, linhas, colunas, larguraJanela);
        if (comando = 'z') filtroMedia(imagem, linhas, colunas, larguraJanela);
        if (comando = '1') filtroBorda1(imagem, linhas, colunas, larguraJanela, k);
        if (comando = '2') filtroBorda2(imagem, linhas, colunas, larguraJanela, k);
        if (comando = '3') filtroBorda3(imagem, linhas, colunas, larguraJanela, k);
        if (comando = 'a') menu();

        if (comando == 'c') {
            check = 0;
            while (!check) {
                printf("Digite o nome do arquivo de entrada: ");
                scanf("%s", argv[1]);
                if ((check = le_pgm(argv[1], imagem, &linhas, &colunas, &maiorValor)))
                    printf("Arquivo %s.pgm carregado com sucesso.\n\n", argv[1]);
            }
            strcpy(prefixo_arquivo_out, argv[1]);
            flag = 0;
        }

        if (comando == 't') {
            imprimeMatriz(imagem, linhas, colunas);
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
                corte(imagem, &linhas, &colunas, xsup, ysup, xinf, yinf);
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
            grava_pgm(prefixo_arquivo_out, imagem, linhas, colunas, maiorValor);
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
                check = le_pgm(prefixo_arquivo_c, c, &linhasC, &colunasC, &maiorValorC);
            }

            erro = compara(imagem, c, linhas, linhasC, colunas, colunasC);

            if (erro.linha == -2 && erro.coluna == -2) {
                printf("As matrizes sao iguais\n");
            } else if (erro.linha == -1 && erro.coluna == -1) {
                printf("As matrizes tem dimensoes diferentes\n");
            } else {
                printf("As matrizes tem valores diferentes na posicao %d, %d\n", erro.linha, erro.coluna);
            }
        }

        for (int i = 0; i < 11; i++) {
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
}

void imprimeMatriz(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
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

void troca(int* a, int* b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordena(int ordenar[JANELA_MAX*JANELA_MAX], int tam) {
    for (int k = 0; k < tam; k++) {
        for (int l = 1; l < tam - k; l++) {
            if (ordenar[k] > ordenar[k + l]) {
                troca(&ordenar[k], &ordenar[k + l]);
            }
        }
    }
}

int media(int mediar[JANELA_MAX*JANELA_MAX], int tam) {
    int soma = 0;
    for (int k = 0; k < tam; k++) {
        soma += mediar[k];
    }
    return soma/tam;
}

int min(int minimizar[JANELA_MAX*JANELA_MAX], int tam) {
    int minimo = minimizar[0];
    for (int k = 1; k < tam; k++) {
        if (minimo > minimizar[k]) {
            minimo = minimizar[k];
        }
    }
    return minimo;
}

int max(int maximizar[JANELA_MAX*JANELA_MAX], int tam) {
    int maximo = maximizar[0];
    for (int k = 1; k < tam; k++) {
        if (maximo < maximizar[k]) {
            maximo = maximizar[k];
        }
    }
    return maximo;
}

int maiorvalor (int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas) {
    int maior = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (maior < m[i][j]) {
                maior = m[i][j];
            }
        }
    }
    return maior;
}

posicao compara(int a[MAXLINHA][MAXCOLUNA], int b[MAXLINHA][MAXCOLUNA], int linhasA, int linhasB, int colunasA, int colunasB) {
    posicao erro;
    if (linhasA != linhasB || colunasA != colunasB) {
        erro.linha = erro.coluna = -1;
        return erro;
    }

    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasA; j++) {
            if (a[i][j] != b[i][j]) {
                erro.linha = i;
                erro.coluna = j;
                return erro;
            }
        }
    }

    erro.linha = erro.coluna = -2;
}

int le_pgm(char* prefixo_do_nome, int m[MAXLINHA][MAXCOLUNA], int *linhas, int* colunas, int* maiorValor) {
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

    for (int i = 0; i < *linhas; i++) {
        for (int j = 0; j < *colunas; j++) {
            fscanf(arq, "%d", &m[i][j]);
        }
    }
    fclose(arq);

    return 1;
}

int grava_pgm(char* prefixo_do_nome, int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int maiorValor) {
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

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fprintf(arq, "%d ", m[i][j]);
        }
        fprintf(arq, "\n");
    }
    fclose(arq);
    return 1;
}

void negativo(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            m[i][j] = 255 - m[i][j];
        }
    }
}

void rebatimentoVertical(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas/2; j++) {
            troca(&m[i][j], &m[i][colunas - j - 1]);
        }
    }
}

void rebatimentoHorizontal(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas) {
    for (int i = 0; i < linhas/2; i++) {
        for (int j = 0; j < colunas; j++) {
            troca(&m[i][j], &m[linhas - i - 1][j]);
        }
    }
}

void rotacao(int m[MAXLINHA][MAXCOLUNA], int* linhas, int* colunas) {
    int maior = *linhas > *colunas ? *linhas : *colunas;
    for (int i = 0; i < maior; i++) {
        for (int j = i; j < maior; j++) {
            troca(&m[i][j], &m[j][i]);
        }
    }
    troca(linhas, colunas);
    rebatimentoVertical(m, *linhas, *colunas);
}

void corte(int m[MAXLINHA][MAXCOLUNA], int* linhas, int* colunas, int xsup, int ysup, int xinf, int yinf) {
    *linhas = xinf - xsup + 1;
    *colunas = yinf - ysup + 1;
    for (int i = 0; i < *linhas; i++) {
        for (int j = 0; j < *colunas; j++) {
            m[i][j] = m[xsup + i][ysup + j];
        }
    }
}

void filtroMediana(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela) {
    int  n;
    int vizinhanca[JANELA_MAX*JANELA_MAX];
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            copia[i][j] = m[i][j];
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            n = 0;
            for (int k = i - larguraJanela/2; k <= i + larguraJanela/2; k++) {
                for (int l = j - larguraJanela/2; l <= j + larguraJanela/2; l++) {
                    if (k >= 0 && l >= 0 && k < linhas && l < colunas) {
                        vizinhanca[n] = copia[k][l];
                        n++;
                    }
                }
            }
            ordena(vizinhanca, n);
            m[i][j] = n % 2 == 0 ? vizinhanca[(n - 1)/2 + 1] : vizinhanca[(n - 1)/2];
        }
    }
}

void filtroMedia(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela) {
    int n;
    int vizinhanca[JANELA_MAX*JANELA_MAX];
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            copia[i][j] = m[i][j];
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            n = 0;
            for (int k = i - larguraJanela/2; k <= i + larguraJanela/2; k++) {
                for (int l = j - larguraJanela/2; l <= j +  larguraJanela/2; l++) {
                    if (k >= 0 && l >= 0 && k < linhas && l < colunas) {
                        vizinhanca[n] = copia[k][l];
                        n++;
                    }
                }
            }
            m[i][j] = media(vizinhanca, n);
        }
    }
}

void filtroErosao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela) {
    int n;
    int vizinhanca[JANELA_MAX*JANELA_MAX];
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            copia[i][j] = m[i][j];
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            n = 0;
            for (int k = i - larguraJanela/2; k <= i + larguraJanela/2; k++) {
                for (int l = j - larguraJanela/2; l <= j +  larguraJanela/2; l++) {
                    if (k >= 0 && l >= 0 && k < linhas && l < colunas) {
                        vizinhanca[n] = copia[k][l];
                        n++;
                    }
                }
            }
            m[i][j] = min(vizinhanca, n);
        }
    }
}

void filtroDilatacao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela) {
    int n;
    int vizinhanca[JANELA_MAX*JANELA_MAX];
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            copia[i][j] = m[i][j];
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            n = 0;
            for (int k = i - larguraJanela/2; k <= i + larguraJanela/2; k++) {
                for (int l = j - larguraJanela/2; l <= j +  larguraJanela/2; l++) {
                    if (k >= 0 && l >= 0 && k < linhas && l < colunas) {
                        vizinhanca[n] = copia[k][l];
                        n++;
                    }
                }
            }
            m[i][j] = max(vizinhanca, n);
        }
    }
}

void limiarizacao(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int k) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            m[i][j] = m[i][j] >= k ? 255 : 0;
        }
    }
}

void filtroBorda1(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k) {
    int E[MAXLINHA][MAXCOLUNA];
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            E[i][j] = m[i][j];
        }
    }
    filtroDilatacao(m, linhas, colunas, larguraJanela);
    filtroErosao(E, linhas, colunas, larguraJanela);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            m[i][j] -= E[i][j];
        }
    }

    limiarizacao(m, linhas, colunas, k);
}

void filtroBorda2(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k) {
    int E[MAXLINHA][MAXCOLUNA];
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            E[i][j] = m[i][j];
        }
    }
    filtroErosao(E, linhas, colunas, larguraJanela);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            m[i][j] -= E[i][j];
        }
    }

    limiarizacao(m, linhas, colunas, k);
}

void filtroBorda3(int m[MAXLINHA][MAXCOLUNA], int linhas, int colunas, int larguraJanela, int k) {
    int D[MAXLINHA][MAXCOLUNA];
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            D[i][j] = m[i][j];
        }
    }

    filtroDilatacao(D, linhas, colunas, larguraJanela);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            m[i][j] = D[i][j] - m[i][j];
        }
    }

    limiarizacao(m, linhas, colunas, k);
}
