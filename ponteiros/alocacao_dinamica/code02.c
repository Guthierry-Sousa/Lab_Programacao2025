#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RG 100

int** alocarMatriz(int linhas, int colunas);
void exibirMatriz(int **matriz, int linhas, int colunas);
void preencherMatriz(int **matriz, int linhas, int colunas);
void liberarMatriz(int **matriz, int linhas);
void sumElements(int **matriz, int linhas, int colunas, int *sum);

int main(){

    srand(time(NULL));

    int **M = NULL;

    int rowns = 0, columns = 0;

    int sum = 0;

    puts("Informe a quantidade de linhas: ");
    scanf("%d", &rowns);

    puts("Informe a quantidade de colunas: ");
    scanf("%d", &columns);

    if(rowns <= 0 || columns <= 0){
        puts("Dimensão Inválida!");
        return 1;
    }

    M = alocarMatriz(rowns, columns);

    preencherMatriz(M, rowns, columns);

    exibirMatriz(M, rowns, columns);

    sumElements(M, rowns, columns, &sum);

    printf("\nSoma = %d\n", sum);

    liberarMatriz(M, rowns);

    return 0;
}

int** alocarMatriz(int linhas, int colunas){

    int **matriz = NULL;

    if(!(matriz = (int**) malloc(linhas * sizeof(int*)))){

        puts("Memória Indisponível.");

        exit(1);
    }

    for(int i = 0; i<linhas; i++){

        *(matriz+i) = (int*) malloc(colunas * sizeof(int));

        if(!(*(matriz+i))){

            puts("Memória Indisponível.");

            exit(1);
        }

    }

    return matriz;
}
void exibirMatriz(int **matriz, int linhas, int colunas){

    for (int i = 0; i < linhas; i++)
    {

        for (int j = 0; j < colunas; j++)
        {

            printf("%3d ", matriz[i][j]);

        }

        printf("\n");
        
    }
    
}
void preencherMatriz(int **matriz, int linhas, int colunas){

    for(int i = 0 ; i<linhas ; i++){

        for(int j = 0; j<colunas ; j++){

            matriz[i][j] = rand() % RG;

        }
    }

}

void liberarMatriz(int **matriz, int linhas){

    for(int i = 0; i<linhas ; i++){

        free(matriz[i]);

    }

    free(matriz);

    puts("Memória desalocada. Finalizando o programa.");

}
void sumElements(int **matriz, int linhas, int colunas, int* sum){

    int lin_element = 0, col_element = 0;

    int qtd_element = 0;

    printf("\nInforme a quantidade de elementos que vc quer somar:  ");
    scanf("%d", &qtd_element);

    for(int i = 0; i<qtd_element; i++){

        printf("\nInforme a linha e a coluna de uma elemento da matriz: ");
        scanf("%d%d", &lin_element, &col_element);

        if(lin_element > linhas || col_element > colunas){

            puts("Posição Inválida.");
            printf("\nTente novamente.\n\n");
            i--;
            
        }
        else{

            printf("\nmatriz[%d][%d] = %d\n", lin_element, col_element, matriz[lin_element][col_element]);

            *sum += matriz[lin_element][col_element];

        }

    }

}