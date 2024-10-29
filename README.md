# PCP Projeto2 OpenMP

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
