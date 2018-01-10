# Seguidor de Linha

A categoria Seguidor de Linha consiste em um robô que deve completar um percurso no menor tempo possível, sem em nenhum momento sair completamente de cima de uma linha que serve como base.

## O robô
----
O robô tem, como forma de sensoreamento, 7 sensores de linha, dispostos em arco na frente do robô.
Além disso, cada motor tem um encoder, que mede a sua rotação.
O robô também têm em seu centro um acelerômetro, que mede a aceleração em cada um dos 3 eixos.
Caso necessário, considere o tamanho da roda como 20mm.

![Posição sensores][follow]

## Pista

A pista segue as seguintes regras:

* A linha que deve ser seguida é branca, em um fundo preto;
* Antes de cada curva, existe sempre uma pequena linha de marcação do lado esquerdo;
* Não existem curvas em 90º, todas as curvas têm um certo raio de curvatura;
* Existe uma área de largada, que é demarcada por traços de ambos os lados da písta, em seu ínicio e final, e robô deve começar e parar entre essas duas marcações;
* Sempre que existir um cruzamento na pista, ele será entre duas retas, com exatamente 90º entre elas.

Qualquer dúvida, existe uma pista seguindo exatamente essas regras do lado de fora da gaiola, se quiserem ver é só avisar.

## Programa

O programa que vocês vão fazer consiste em fazer esse robô seguir a linha, usando as coisas que ele tem e as características da pistas(não precisa usar tudo). Para isso, devem usar as seguintes funções:

```c
void motors(int16_t velE, int16_t velD);

uint16_t getLineSensor(uint16_t sensor);
int16_t getEncoder(encoder_t enc);
int16_t getAccel(eixo_t eixo);

uint32_t get_tick();
```
Assumam que essas funções funcionam e estão implementadas, vocês podem fazer alterações em todos arquivos(e criar novos), da forma que preferirem. Podem usar o controle que preferirem, os dados de sensores que acharem necessário.

[follow]: http://thunderatz.org/media/ps2017/Follow.jpeg "Sensores Follow"
