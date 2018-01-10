# Sumo Autonomo

A categoria de Sumô Autonomo consiste em dois robôs posicionados num dojô e que tem como objetivo empurrar o adversário para fora desse dojô.

## Projeto
----
Considere um robô que contém 5 sensores de distância e 4 sensores de linha, dispostos da seguinte maneira:

![Posicao sensores][robo]

Assuma que os sensores de distância são [esses][sharp] e funcionam como no datasheet, operando em 5V.
Assuma também que o sensor de 6 eixos é [esse][mpu].

## Dojo

O dojo é uma arena redonda, preta, com linhas brancas na borda, cada robo começa em uma metade, desde que atrás das linhas demarcadas.

![Dojo][dojo]

## Programa

O programa que vocês vão fazer consiste em uma estratégia para esse robô, usando tudo que ele tem e acharem necessário (não precisa usar *tudo*). Para isso, devem usar os dados dos sensores com as seguintes funções:

```c
void sensors_init();
void update_distance();
void update_line();
void update_accel();

void motors_init();
void motors(int16_t vel_left, int16_t vel_right);

void timer_init();
uint32_t get_tick();
```

Assumam que as funções funcionem, não precisam implementá-las, foquem na estratégia e podem mexer em outras partes dos arquivos, i.e. para criar algum define no sensors.h.

Lembrando que vocês também podem criar mais de uma estratégia, se acharem necessário, afinal, diferentes tipos de estratégia podem ser mais eficientes contra diferentes tipos de adversários.

[robo]: http://thunderatz.org/media/ps2017/SumoAuto.png "Sensores Sumo"
[dojo]: http://robogames.net/images/sumo-ring.gif "Dojo"
[sharp]: http://www.sharp-world.com/products/device/lineup/data/pdf/datasheet/gp2y0a60szxf_e.pdf
[mpu]: https://www.invensense.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf
