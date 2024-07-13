/* Calculadora de matrizes com operações de adição, subtração, multiplicação, transposição, determinante, inversa e operações escalares. */

// Bibliotecas usadas
#include <stdio.h>
#include <stdlib.h>

// Constante com o tamanho máximo das matrizes
#define TamanhoMaximo 100

// Função para entrada dos elementos na matriz
void InputMatriz(int linhas, int colunas, double (*matriz)[TamanhoMaximo]){
    int i, j;
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            printf("Elemento[%d][%d] = ", i + 1, j + 1); // Solicita ao usuário o elemento
            while (scanf("%lf", &matriz[i][j]) != 1){ // Verifica se o usuário inseriu um número
                printf("Entrada inválida. Por favor, insira um número!\n");
                printf("Elemento[%d][%d] = ", i + 1, j + 1); // Solicita ao usuário o elemento novamente
                while (getchar() != '\n'); // Limpa o buffer do teclado
            }
        }
    }
}

// Função para exibição de matriz
void ExibirMatriz(int linhas, int colunas, double (*matriz)[TamanhoMaximo]){
    int i, j;
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            printf("[%.2lf] ", matriz[i][j]); // Imprime a matriz com duas casas decimais
        }
        printf("\n");
    }
}

// Função para calcular a matriz inversa usando o método de eliminação de Gauss-Jordan
void InversaMatriz(int dimensao, double (*matriz)[TamanhoMaximo], double (*matrizInversa)[TamanhoMaximo]){
    // Matriz temporária que armazena a matriz aumentada, sendo a matriz + a matriz identidade
    double matrizTemp[TamanhoMaximo][2 * TamanhoMaximo];

    // Inicializar a matriz aumentada com a matriz original e a matriz identidade
    int i, j;
    for (i = 0; i < dimensao; i++){
        for (j = 0; j < dimensao; j++){
            matrizTemp[i][j] = matriz[i][j];
            // Matriz identidade
            matrizTemp[i][j + dimensao] = (i == j) ? 1.0 : 0.0; // "Se i for igual a j, o elemento assume 1.0, senão assume 0.0"
        }
    }

    // Método de eliminação de Gauss-Jordan
    for (i = 0; i < dimensao; i++){
        // Pivô (matriz[i][i]) assume 1 e zera todos os outros elementos na mesma coluna
        double piv = matrizTemp[i][i];
        for (j = 0; j < 2 * dimensao; j++){
            matrizTemp[i][j] /= piv;
        }

        // Zera todos os elementos nas outras linhas e colunas
        for (int k = 0; k < dimensao; k++){
            if (k != i){
                double fator = matrizTemp[k][i];
                for (j = 0; j < 2 * dimensao; j++){
                    matrizTemp[k][j] -= fator * matrizTemp[i][j];
                }
            }
        }
    }

    // Copia a matriz inversa para a saída
    for (i = 0; i < dimensao; i++){
        for (j = 0; j < dimensao; j++){
            matrizInversa[i][j] = matrizTemp[i][j + dimensao];
        }
    }
}

// Função para soma entre matrizes
void SomaMatriz(int linhas, int colunas, double (*matrizA)[TamanhoMaximo], double (*matrizB)[TamanhoMaximo], double (*matrizCalculo)[TamanhoMaximo]){
    int i, j;
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            matrizCalculo[i][j] = matrizA[i][j] + matrizB[i][j]; // Reliza a soma dos elementes entre as matrizes
        }
    }
}

// Função para subtração entre matrizes
void SubtracaoMatriz(int linhas, int colunas, double (*matrizA)[TamanhoMaximo], double (*matrizB)[TamanhoMaximo], double (*matrizCalculo)[TamanhoMaximo]){
    int i, j;
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            matrizCalculo[i][j] = matrizA[i][j] - matrizB[i][j]; // Reliza a subtração dos elementes entre as matrizes
        }
    }
}

// Função para multiplicação entre matrizes
void MultiplicacaoMatriz(int linhasA, int colunasA, int colunasB, double (*matrizA)[TamanhoMaximo], double (*matrizB)[TamanhoMaximo], double (*matrizCalculo)[TamanhoMaximo]){
    int i, j, k;
    for (i = 0; i < linhasA; i++){
        for (j = 0; j < colunasB; j++){
            matrizCalculo[i][j] = 0;
            for (k = 0; k < colunasA; k++){
                matrizCalculo[i][j] += matrizA[i][k] * matrizB[k][j]; // Reliza a multiplicação dos elementes entre as matrizes
            }
        }
    }
}

// Função para transposição de matriz
void TranspostaMatriz(int linhas, int colunas, double matriz[TamanhoMaximo][TamanhoMaximo], double matrizTransposta[TamanhoMaximo][TamanhoMaximo]){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matrizTransposta[j][i] = matriz[i][j];
        }
    }
}

// Função para calcular o determinante de uma matriz quadrada
double DeterminanteMatriz(int ordem, double (*matriz)[TamanhoMaximo]){
    // Se a ordem da matriz for 1, retorna o único elemento da matriz como o determinante
    if (ordem == 1){
        return matriz[0][0];
    }
    else{
        double det = 0;
        double sinal = 1;
        int i, j, k;
        double submatriz[TamanhoMaximo][TamanhoMaximo];

        // Loop sobre a primeira linha para calcular o determinante
        for (i = 0; i < ordem; i++){
            int sub_linha = 0, sub_coluna = 0;
            // Criando a submatriz excluindo a linha e coluna do elemento atual
            for (j = 1; j < ordem; j++){
                for (k = 0; k < ordem; k++){
                    if (k == i)
                        continue; // Ignora a coluna do elemento atual
                    submatriz[sub_linha][sub_coluna] = matriz[j][k];
                    sub_coluna++;
                }
                sub_linha++;
                sub_coluna = 0;
            }
            // Calcula recursivamente o determinante da submatriz e soma ao determinante
            det += sinal * matriz[0][i] * DeterminanteMatriz(ordem - 1, submatriz);
            // Alterna o sinal para o próximo termo da expansão
            sinal = -sinal;
        }
        return det;
    }
}


// Função para executar uma operação escalar em uma matriz
void OperacaoEscalar(int linhas, int colunas, double (*matrizA)[TamanhoMaximo], double escalar, char operacao, double (*matrizResultado)[TamanhoMaximo]){
    int i, j;
    // Loop para iterar sobre todas as células da matriz
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            // Verifica a operação a ser realizada
            switch (operacao){
            // Multiplicação por um escalar
            case 1:
                matrizResultado[i][j] = matrizA[i][j] * escalar; // Multiplica o elemente pelo escalar
                break;
            // Divisão por um escalar e verificação para divisões por zero
            case 2:
                if (escalar != 0)
                    matrizResultado[i][j] = matrizA[i][j] / escalar; // Divide o elemente pelo escalar
                else
                    printf("Não é possível realizar a divisão por zero.\n");
                break;
            // Operação inválida
            default:
                printf("Operação inválida.\n");
                break;
            }
        }
    }
}

int main(void) {
    int linhasA, colunasA, colunasB, operacao, formula, continuar = 1;
    double matrizA[TamanhoMaximo][TamanhoMaximo], matrizB[TamanhoMaximo][TamanhoMaximo], matrizCalculo[TamanhoMaximo][TamanhoMaximo], matrizTransposta[TamanhoMaximo][TamanhoMaximo], matrizInversa[TamanhoMaximo][TamanhoMaximo];
    double escalar, determinante;

    // Loop para manter o programa em execução até que o usuário escolha parar
    while (continuar) {
        system("clear");
        printf("~ CALCULADORA DE MATRIZES ~\n===========================\n\n");
        printf("1 - Soma de Matrizes\n");
        printf("2 - Subtração de Matrizes\n");
        printf("3 - Multiplicação de Matrizes\n");
        printf("4 - Determinante de Matriz\n");
        printf("5 - Transposta de Matriz\n");
        printf("6 - Inversa de Matriz\n");
        printf("7 - Operações Escalares\n");
        printf("0 - Sair\n");
        printf("Insira o número equivalente à operação desejada: ");
        scanf("%d", &formula);

        // Switch case para escolher a operação a ser realizada
        switch (formula) {
            case 0:
                continuar = 0; // Variável continuar como 0 encerra o loop
                system("clear");
                break;

            case 1:
                // Código para adição de matrizes
                system("clear");
                printf("~ ADIÇÃO DE MATRIZES ~\n===========================\n\n");

                // Solicita as dimensões das matrizes
                printf("\nInforme a quantidade de linhas da matriz: ");
                scanf("%d", &linhasA);
                printf("Informe a quantidade de colunas da matriz: ");
                scanf("%d", &colunasA);

                // Verifica se o número de linhas e colunas ultrapassam o tamanho máximo da matriz ou se são menores do que 1
                if (linhasA < 1 || colunasA < 1 || linhasA > TamanhoMaximo || colunasA > TamanhoMaximo) {
                    printf("\n*** Tamanho da matriz inválido! ***\n");
                    // Sai da opção escolhida
                    printf("\n\nClique em 'Enter' para continuar. ");
                    getchar();
                    getchar();
                    break;
                }

                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz A:\n");
                InputMatriz(linhasA, colunasA, matrizA);
                printf("\nInsira os elementos da matriz B:\n");
                InputMatriz(linhasA, colunasA, matrizB);

                // Exibe as matrizes
                printf("\n\nMatriz A:\n");
                ExibirMatriz(linhasA, colunasA, matrizA);
                printf("\nMatriz B:\n");
                ExibirMatriz(linhasA, colunasA, matrizB);

                // Realiza a adição entre as matrizes
                SomaMatriz(linhasA, colunasA, matrizA, matrizB, matrizCalculo);

                // Exibe o resultado
                printf("\n\nResultado da soma:\n");
                ExibirMatriz(linhasA, colunasA, matrizCalculo);

                // Sai da opção escolhida
                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            case 2:
                // Código para subtração de matrizes
                system("clear");
                printf("~ SUBTRAÇÃO DE MATRIZES ~\n===========================\n\n");

                // Solicita as dimensões das matrizes
                printf("\nInforme a quantidade de linhas da matriz: ");
                scanf("%d", &linhasA);
                printf("Informe a quantidade de colunas da matriz: ");
                scanf("%d", &colunasA);

                // Verifica se o número de linhas e colunas ultrapassam o tamanho máximo da matriz ou se são menores do que 1
                if (linhasA < 1 || colunasA < 1 || linhasA > TamanhoMaximo || colunasA > TamanhoMaximo) {
                    printf("\n*** Tamanho da matriz inválido! ***\n");
                    // Sai da opção escolhida
                    printf("\n\nClique em 'Enter' para continuar. ");
                    getchar();
                    getchar();
                    break;
                }

                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz A:\n");
                InputMatriz(linhasA, colunasA, matrizA);
                printf("\nInsira os elementos da matriz B:\n");
                InputMatriz(linhasA, colunasA, matrizB);

                // Exibe as matrizes
                printf("\n\nMatriz A:\n");
                ExibirMatriz(linhasA, colunasA, matrizA);
                printf("\nMatriz B:\n");
                ExibirMatriz(linhasA, colunasA, matrizB);

                // Realiza a subtração entre as matrizes
                SubtracaoMatriz(linhasA, colunasA, matrizA, matrizB, matrizCalculo);

                // Exibe o resultado
                printf("\n\nResultado da subtração:\n");
                ExibirMatriz(linhasA, colunasA, matrizCalculo);

                // Sai da opção escolhida
                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            case 3:
                // Código para multiplicação de matrizes
                system("clear");
                printf("~ MULTIPLICAÇÃO DE MATRIZES ~\n===========================\n\n");

                // Solicita as dimensões das matrizes
                printf("\nInforme a quantidade de linhas da matriz A: ");
                scanf("%d", &linhasA);
                printf("Informe a quantidade de colunas da matriz A: ");
                scanf("%d", &colunasA);
                printf("Informe a quantidade de colunas da matriz B: ");
                scanf("%d", &colunasB);

                // Verifica se o número de linhas e colunas ultrapassam o tamanho máximo da matriz ou se são menores do que 1
                if (linhasA < 1 || colunasA < 1 || colunasB < 1 || linhasA > TamanhoMaximo || colunasA > TamanhoMaximo || colunasB > TamanhoMaximo) {
                    printf("\n*** Tamanho da matriz inválido! ***\n");
                    // Sai da opção escolhida
                    printf("\n\nClique em 'Enter' para continuar. ");
                    getchar();
                    getchar();
                    break;
                }

                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz A:\n");
                InputMatriz(linhasA, colunasA, matrizA);
                printf("\nInsira os elementos da matriz B:\n");
                InputMatriz(colunasA, colunasB, matrizB);

                // Exibe as matrizes
                printf("\n\nMatriz A:\n");
                ExibirMatriz(linhasA, colunasA, matrizA);
                printf("\nMatriz B:\n");
                ExibirMatriz(colunasA, colunasB, matrizB);

                // Realiza a multiplicação entre as matrizes
                MultiplicacaoMatriz(linhasA, colunasA, colunasB, matrizA, matrizB, matrizCalculo);

                // Exibe o resultado
                printf("\n\nResultado da multiplicação:\n");
                ExibirMatriz(linhasA, colunasB, matrizCalculo);

                // Sai da opção escolhida
                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            case 4:
                // Código para cálculo do determinante
                system("clear");
                printf("~ DETERMINANTE DE MATRIZ ~\n===========================\n\n");

                // Solicita as dimensões da matriz
                printf("Informe a quantidade de linhas e colunas da matriz quadrada: ");
                scanf("%d", &linhasA);

                // Verifica se a matriz é quadrada
                colunasA = linhasA;

                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz:\n");
                InputMatriz(linhasA, colunasA, matrizA);

                printf("\n\nMatriz:\n");
                ExibirMatriz(linhasA, colunasA, matrizA);

                // Cálculo do determinante
                double determinante = DeterminanteMatriz(linhasA, matrizA);
                printf("\n\nDeterminante da matriz: %0.2lf\n", determinante);
                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            case 5:
                // Código para cálculo da transposta
                system("clear");
                printf("~ TRANSPOSTA DE MATRIZ ~\n===========================\n\n");
    
                // Solicita as dimensões da matriz
                printf("Informe a quantidade de linhas da matriz: ");
                scanf("%d", &linhasA);
                printf("Informe a quantidade de colunas da matriz: ");
                scanf("%d", &colunasA);
    
                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz:\n");
                InputMatriz(linhasA, colunasA, matrizA);
    
                printf("\n\nMatriz:\n");
                ExibirMatriz(linhasA, colunasA, matrizA);
    
                // Calcula a transposta
                TranspostaMatriz(linhasA, colunasA, matrizA, matrizCalculo);
                printf("\n\nResultado da transposta:\n");
                ExibirMatriz(colunasA, linhasA, matrizCalculo); // Linhas e colunas invertidas na transposta
                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            case 6:
                // Código para matriz inversa
                system("clear");
                printf("~ MATRIZ INVERSA ~\n===========================\n\n");

                // Solicita a ordem da matriz quadrada
                printf("\nInforme a ordem da matriz quadrada: ");
                scanf("%d", &linhasA);

                // Verifica se a ordem ultrapassa o tamanho máximo da matriz ou se é menor do que 1
                if (linhasA <= 0 || linhasA > TamanhoMaximo) {
                    printf("\n*** Tamanho da matriz inválido! ***\n");
                    // Sai da opção escolhida
                    printf("\n\nClique em 'Enter' para continuar. ");
                    getchar();
                    getchar();
                    break;
                }

                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz:\n");
                InputMatriz(linhasA, linhasA, matrizA);

                // Exibe a matriz
                printf("\n\nMatriz:\n");
                ExibirMatriz(linhasA, linhasA, matrizA);

                // Calcula a matriz inversa
                InversaMatriz(linhasA, matrizA, matrizInversa);

                // Calcula o determinante da matriz
                determinante = DeterminanteMatriz(linhasA, matrizA);

                // Verifica se a matriz é invertível
                if (determinante == 0) {
                    printf("\n\nO determinante da matriz é zero, portanto não é invertível!");
                } else {
                    printf("\n\nMatriz Inversa:\n");
                    ExibirMatriz(linhasA, linhasA, matrizInversa);
                }

                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            case 7:
                // Código para operações escalares
                system("clear");
                printf("~ OPERAÇÕES ESCALARES ~\n===========================\n\n");

                // Solicita a operação a ser realizada nas operações escalares
                printf("1 - Multiplicação\n2 - Divisão\n\n");
                printf("Insira o número equivalente à operação desejada: ");
                scanf("%d", &operacao);

                // Solicita as dimensões da matriz
                printf("\nInforme a quantidade de linhas da matriz: ");
                scanf("%d", &linhasA);
                printf("Informe a quantidade de colunas da matriz: ");
                scanf("%d", &colunasA);

                // Solicita o escalar a ser usado no cálculo
                printf("\nInforme o escalar: ");
                scanf("%lf", &escalar);

                // Solicita os elementos da matriz
                printf("\n\nInsira os elementos da matriz:\n");
                InputMatriz(linhasA, colunasA, matrizA);

                printf("\n\nMatriz:\n");
                ExibirMatriz(linhasA, colunasA, matrizA);

                printf("\n\nResultado da operação escalar:\n");
                OperacaoEscalar(linhasA, colunasA, matrizA, escalar, operacao, matrizCalculo);
                ExibirMatriz(linhasA, colunasA, matrizCalculo);
                printf("\n\nClique em 'Enter' para continuar. ");
                getchar();
                getchar();
                break;

            default:
                printf("\n\n*** Opção inválida, por favor escolha uma opção válida ou digite 0 para encerrar o programa. ***\n");
                break;
        }
    }

    printf("\nPrograma encerrado.\n");

    return 0;
}