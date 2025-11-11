#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RG 10

int ** alocarMatriz(const int, const int);
void liberarMatriz(int** ,const int);
void exibirMatriz(int** ,const int,const int);
void preencherMatriz(int**,const int,const int);

int main(){

    srand(time(NULL));
    int rowns = 0, columns = 0;
    int **M = NULL;

    //Número de linhas
    puts("Informe a quantidade de linhas: ");
    scanf("%d", &rowns);

    //Número de colunas
    puts("Informe a quantidade de colunas: ");
    scanf("%d", &columns);

    if(rowns <= 0 || columns <=0){
        puts("Dimensões Inválidas!");
        return 1;
    }

    // Alocando o espaço de memória necessário para a matriz
    M = alocarMatriz(rowns, columns);

    preencherMatriz(M, rowns, columns);
    exibirMatriz(M, rowns, columns);

    int lin_element, col_element;
    puts("Informe a linha e a coluna de uma elemento da matriz: ");
    scanf("%d%d", &lin_element, &col_element);

    if(lin_element > rowns || col_element > columns){
        puts("Posição Inválida.");
    }
    else{

        printf("matriz[%d][%d] = %d\n", lin_element, col_element, M[lin_element][col_element]);

    }

    liberarMatriz(M, rowns);

    return 0;
}

int ** alocarMatriz(const int linhas, const int colunas){

    int **M = NULL;

    if(!(M = (int**) malloc(sizeof(int*) * linhas))){

        puts("Memória Indisponível.");
        exit(1);

    }

    for(int i = 0; i<linhas; i++){

        *(M + i) = (int*) malloc(colunas * sizeof(int));


        if(!(*(M+i))){

            puts("Memória Indisponível.");
            exit(1);
        }

    }

    return M;
}

void exibirMatriz(int** matriz ,const int linhas, const int colunas){

    for(int i = 0; i<linhas; i++){

        for(int j = 0; j<colunas; j++){

            printf("matriz[%d][%d] = %1d ",i, j, *(*(matriz+i)+j));
        }

        printf("\n");
        
    }

}

void preencherMatriz(int** matriz,const int linhas,const int colunas){

    for(int i = 0; i<linhas; i++){

        for(int j = 0; j<colunas; j++){

            *(*(matriz+i)+j) = rand() % RG;
        }
    }
}

void liberarMatriz(int** matriz ,const int linhas){

    for(int i = 0; i<linhas; i++){
        free(*(matriz + i));
    }

    free(matriz);
}