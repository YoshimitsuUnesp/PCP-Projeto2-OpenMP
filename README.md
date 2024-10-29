# Projeto 2 - OpenMP

## 1. Especificação

Para a efetuação do segundo projeto, será realizado uma série de *benchmarks* do método dos trapézios na seguinte integral dupla:

$$
\int_{0}^{1.5} \int_{0}^{1.5} \sin(x^2 + y^2)
$$

Para isso, deverá ser utilizado a biblioteca **OpenMP**, variando o número de *threads* e diferente intervalos de discretização:

- **Quantidade de *threads* :** 1, 2, 4 e 8 *threads.*
- **Quantidade de intervalos no eixo $x$:** $10^3$, $10^4$ e $10^5$.
- **Quantidade de intervalos no eixo $y$:** $10^3$, $10^4$ e $10^5$.

## 2. Entrega

Para resolução do projeto deverá ser entregue o código fonte da aplicação, além de um relatório descrevendo o tempo de execução para cada situação, utilizando tabelas e gráficos.

---

## Instruções

Para rodar, é necessário ter o GCC instalado. Há duas alternativas para compilar o programa:

### Makefile

A forma mais simples de compilar e rodar o programa é estando dentro da pasta do projeto e em seguida usando os seguintes comandos pelo terminal:

```bash
make
./main
```

### Escrevendo os comandos

A segunda forma é escrevendo o que o Makefile faria:

```bash
gcc -g -o main *.c -fopenmp
./main

```

## Debugging

Para debuggar o projeto, pode ser necessário alterar o caminho em launch.json:

```json
"cwd": "/home/lanzo/PCP-Projeto2-OpenMP",
"program": "/home/lanzo/PCP-Projeto2-OpenMP/main",
```

Altere estes campos para o caminho do projeto e do executável em sua máquina.
