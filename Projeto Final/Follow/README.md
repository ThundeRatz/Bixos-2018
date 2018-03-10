# Seguidor de Linha

A categoria Seguidor de Linha consiste em um robô que deve completar um percurso no menor tempo possível, sem em nenhum momento sair completamente de cima de uma linha que serve como base.

## O robô
----
O robô tem, como forma de sensoreamento, 5 sensores de linha, dispostos na frente do robô.

O robô pode ser visto na gaiola.

## Pista

A pista segue as seguintes regras:

* A linha que deve ser seguida é branca, em um fundo preto;
* Antes de cada curva, existe sempre uma pequena linha de marcação do lado esquerdo;
* Não existem curvas em 90º, todas as curvas têm um raio de curvatura de no mínimo 15 cm;
* Existe uma área de largada, que é demarcada por traços no lado direito da pista, em seu ínicio e final, e robô deve começar e parar entre essas duas marcações;
* Sempre que existir um cruzamento na pista, ele será entre duas retas, com exatamente 90º entre elas.

Qualquer dúvida, existe uma pista seguindo exatamente essas regras do lado de fora da gaiola, se quiserem ver é só avisar.

## Programa

O programa que vocês vão fazer consiste em fazer esse robô seguir a linha, usando as coisas que ele tem e as características da pistas(não precisa usar tudo). Para isso, devem usar as seguintes funções:

```c
void motors(int16_t velE, int16_t velD);

uint16_t getLineSensor(uint16_t sensor);
uint32_t get_tick();
```
Assumam que essas funções funcionam e estão implementadas, vocês podem fazer alterações em todos arquivos (e criar novos), da forma que preferirem. Podem usar o controle que preferirem, os dados de sensores que acharem necessário.