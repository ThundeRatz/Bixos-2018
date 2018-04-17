# Seguidor de Linha

A categoria Seguidor de Linha consiste em um robô que deve completar um percurso no menor tempo possível, sem em nenhum momento sair completamente de cima de uma linha que serve como base.

## O robô
----
O robô tem, como forma de sensoreamento, 7 sensores de linha, dispostos na frente do robô.

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

O programa que vocês vão fazer consiste em fazer esse robô seguir a linha, usando as coisas que ele tem e as características da pista (não precisa usar tudo). Para isso, podem usar as seguintes funções:

```c
void hardware_init();
void set_motors(int left_speed, int right_speed);
void sensor_update();  // atualiza todos os sensores de uma vez no vetor de sensores
uint16_t sensor_read(sensor_t sensor);  // retorna a leitura de um sensor especifico
void led_control(uint8_t color, uint8_t action);
uint32_t get_tick();
```

Vocês podem fazer alterações em todos arquivos (e criar novos), da forma que preferirem. Podem usar o controle que preferirem, os dados de sensores que acharem necessário.

Observação: Não precisa fazer o robô parar ao completar a pista.
