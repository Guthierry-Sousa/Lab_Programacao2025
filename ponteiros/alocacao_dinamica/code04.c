// Gerar uma matriz (quadrada) dinamicamente com parâmetros passados no terminal para função main e somar sua diagonal principal e secundaria.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** alocarMatriz(int dim);
void preencherMatriz(int **M, int dim);
void exibirMatriz(int **M, int dim);
int somaDiagonalPrincipal(int **M, int dim);
int somaDiagonalSecundaria(int **M, int dim);
void desalocarMatriz(int **M, int dim);

#define RG 10;

int main(int argc, char **argv){

    srand(time(NULL));

    if(argc != 2){
        printf("Use: \t %s <dimensão>\n", *argv);
        exit(1);
    }

    int dimensao = atoi(*(argv + 1));

    int **matriz = alocarMatriz(dimensao);
    preencherMatriz(matriz, dimensao);

    exibirMatriz(matriz, dimensao);

    int somatorio_Dprincipal = somaDiagonalPrincipal(matriz, dimensao);

    int somatorio_Dsecundaria = somaDiagonalSecundaria(matriz, dimensao);

    desalocarMatriz(matriz, dimensao);

    printf("\n\nSomatório dos elementos da diagonal principal = %d\n\n", somatorio_Dprincipal);

    printf("\n\nSomatório dos elementos da diagonal secundária = %d\n\n", somatorio_Dsecundaria);

    return 0;
}

int ** alocarMatriz(int dim){

    int **M = NULL;

    if(!(M = (int **) malloc(sizeof(int *) * dim))){ //Alocando a quantidade de linhas da matriz

        puts("Memória Indisponível.");
        exit(2);
    }
    
    for(int i = 0; i<dim; i++){

        *( M + i ) = (int*) malloc(sizeof(int) * dim);

        if(!(*(M+i))){  // Alocando as colunas da matriz

            puts("Memória Indisponível.");
            exit(3);
        }
         
    }

    return M;

}

void preencherMatriz(int **M, int dim){

    for(int i = 0; i<dim; i++){

        for(int j = 0; j<dim; j++){

            *(*(M+i)+j) = rand() % RG;
        }
    }
}

void exibirMatriz(int **M, int dim){

    printf("\nMatriz Gerada: \n\n");

    for(int i = 0; i<dim; i++){

        for(int j = 0; j<dim; j++){

            printf("%2d ",*(*(M + i) + j) );
        }
        printf("\n");
    }
}

int somaDiagonalPrincipal(int **M, int dim){

    int sum_principal = 0;

    printf("\nElementos Diagonal Principal: \n");
    for(int i = 0;i<dim; i++){

        printf("\nM[%d][%d] = %d\n", i,i, *(*(M+i)+i));

        sum_principal += *(*(M+i)+i);

    }

    return sum_principal;
}

int somaDiagonalSecundaria(int **M, int dim){

    int sum_secundaria = 0;

    printf("\nElementos Diagonal Secundária: \n");
    for(int i = 0;i<dim; i++){

        for(int j =0; j<dim; j++){

            if(i+j == dim-1){

                printf("\nM[%d][%d] = %d\n", i,j, *(*(M+i)+j));

                sum_secundaria += *(*(M+i)+j);
                
            }
        }
        
    }

    return sum_secundaria;

}

void desalocarMatriz(int **M, int dim){

    for(int i = 0;i<dim; i++){

        free(*(M+i));

    }

    free(M);
}