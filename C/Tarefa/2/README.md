# Tarefa 2 - Bits!

Considere um programa que recebe dados de 8 sensores e, a partir de um _threshold_ determinado, sabe se o valor é válido (1) ou não (0). essa informação precisa ser enviada para um programa externo, porém, por limitações, a resposta de todos os sensores devem ser enviadas em apenas um byte. Algumas funções já estão implementadas para simular a leitura e o envio/recebimento de dados.

```c
// Pegar uma leitura aleatória para o sensor
sensor[0].leitura = get_value()

// Comparar a leitura com o threshold do sensor
// Vejam o que fazer com esses dados para juntarem todos os resultados num unico byte
sensor[0].leitura > sensor[0].threshold

// Usar essa função para "enviar" seu byte
// Implemente a função para apenas imprimir os dados desempacotados
send_data(dados)
```

Não se esqueçam de comentar o código minimamente para sabermos o que pensaram.
