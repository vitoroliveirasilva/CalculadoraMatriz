<!-- Título e descrição -->
# Calculadora de Matrizes em C

Este projeto apresenta uma calculadora de matrizes desenvolvida em C, capaz de realizar diversas operações matriciais, tais como adição, subtração, multiplicação, transposição, cálculo de determinantes, inversão de matrizes e operações escalares.

<!-- Operações utilizadas -->
## Operações

#### Adição
- Insira as dimensões e os elementos de duas matrizes.
- O programa exibirá a matriz resultante após a adição.

#### Subtração
- Insira as dimensões e os elementos de duas matrizes.
- O programa exibirá a matriz resultante após a subtração.

#### Multiplicação
- Insira as dimensões e os elementos de duas matrizes.
- O programa exibirá a matriz resultante após a multiplicação.

#### Transposição
- Insira as dimensões e os elementos de uma matriz.
- O programa exibirá a matriz transposta.

#### Determinante
- Insira as dimensões e os elementos de uma matriz.
- O programa exibirá o determinante da matriz.

#### Inversão
- Insira as dimensões e os elementos de uma matriz.
- O programa exibirá a matriz inversa, se existir.

#### Operações Escalares
- Insira as dimensões e os elementos de uma matriz, além do valor escalar.
- O programa exibirá a matriz resultante após a operação escalar.

<!-- Funções do código -->
## Visão geral do código

#### Validação de Entrada
- Este programa realiza a validação dos valores inseridos pelo usuário.
#### Dimensão de Matrizes
- O programa garante as dimensões corretas para cada operação.

#### O arquivo Main.c contém todas as funções necessárias para realizar as operações matriciais. Aqui está uma visão geral de algumas funções principais:

```javascript
void InputMatriz(int linhas, int colunas, double matriz[TamanhoMaximo][TamanhoMaximo]);
```

```javascript
void ExibirMatriz(int linhas, int colunas, double matriz[TamanhoMaximo][TamanhoMaximo]);
```

```javascript
void InversaMatriz(int dimensao, double matriz[TamanhoMaximo][TamanhoMaximo], double matrizInversa[TamanhoMaximo][TamanhoMaximo]);
```

```javascript
void SomaMatriz(int linhas, int colunas, double matrizA[TamanhoMaximo][TamanhoMaximo], double matrizB[TamanhoMaximo][TamanhoMaximo], double matrizC[TamanhoMaximo][TamanhoMaximo]);
```

```javascript
void SubtraiMatriz(int linhas, int colunas, double matrizA[TamanhoMaximo][TamanhoMaximo], double matrizB[TamanhoMaximo][TamanhoMaximo], double matrizC[TamanhoMaximo][TamanhoMaximo]);
```

```javascript
void MultiplicaMatriz(int linhasA, int colunasA, int colunasB, double matrizA[TamanhoMaximo][TamanhoMaximo], double matrizB[TamanhoMaximo][TamanhoMaximo], double matrizC[TamanhoMaximo][TamanhoMaximo]);
```

```javascript
void TransporMatriz(int linhas, int colunas, double matriz[TamanhoMaximo][TamanhoMaximo], double matrizTransposta[TamanhoMaximo][TamanhoMaximo]);
double DeterminanteMatriz(int dimensao, double matriz[TamanhoMaximo][TamanhoMaximo]);
```

```javascript
void OperacaoEscalar(int linhas, int colunas, double matriz[TamanhoMaximo][TamanhoMaximo], double escalar, int operacao, double matrizResultado[TamanhoMaximo][TamanhoMaximo]);
```

<!-- Como usar -->
## Uso

Para utilizar o programa, compile e execute o arquivo `main.c` no compilador C de sua preferência. Siga as instruções exibidas na tela para selecionar a operação desejada e insira os elementos da matriz conforme solicitado. Assim, você poderá realizar as operações matriciais e obter os resultados desejados.

<!-- Gif -->
![UsoCalculadoraMatriz](https://github.com/user-attachments/assets/d779625c-9fe5-4c47-88d3-fdacd211badd)

<!-- Observações -->
## Nota

Projeto realizado para a faculdade, com o objetivo exclusivo de aprendizagem.

Este projeto está licenciado sob a licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.
