#include "sensors.h"

uint16_t getLineSensor(uint16_t sensor){
    /*
    Recebe o número de um sensor(0 a 6) e retorna o valor da leitura analógica 
    dele, sendo 0 a leitura mais escura possível e 1023 a leitura mais clara

    A disposição dos sensores na frente do robô é a seguinte:
                                  FRENTE

                                2   3   4
                            1               5
          ESQUERDA      0                       6      DIREITA
    */
}

int16_t getEncoder(encoder_t enc){
    /*
    Recebe qual o encoder que deve ser lido, ENCODER_L ou ENCODER_R.
    Retorna o número de contagens já feita pelo encoder até o momento.
    O valor retornado é persistente entre as chamadas, e é a contagem desde o início.
    Ou seja, caso você chame a função e ela retorne 100 2 vezes seguidas, 
    a posição da roda não mudou entre as chamadas.

    As contagens funcionam da seguinte forma:
    Cada volta para a frente da roda aumenta em 100 o valor retornado pela função.
    Da mesma forma, uma volta para trás diminui esse número em 100.
    Esse valor é contínuo, ou seja, meia volta vai mudar em 50 o valor retornado.
    */
}

int16_t getAccel(eixo_t eixo){
    /*
    Retorna um valor entre -1024 e 1023, equivalente à aceleração do robô naquele
    momento, no eixo pedido. Retorna 0 se não houver aceleração naquele eixo,
    e -1024/1023 se estiver muito acelerado(engenharia de precisão rs), com o sentido
    indicado pelo sinal.

                O sensor está montado de forma que os eixos ficam:

                                        FRENTE

                                       X/\
                                        |
                                        |
                                        |
                                        |
                                        |
                ESQUERDA   <------------.             DIREITA
                           Y

    E o eixo Z é positivo para cima.
    */                              
}
