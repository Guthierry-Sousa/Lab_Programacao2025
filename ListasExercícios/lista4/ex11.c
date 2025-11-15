#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** alocarMatriz(int max);
void gerarVetor(int *vet, int tam, int max);
void exibirVetor(int *vet, int tam);
void contarFrequencia(int *vet1, int *vet2,int **matriz, int tam);
void exibirMatriz(int **matriz, int max);

int main(int argc, char **argv){

    srand(time(NULL));

    if(argc != 3){

        printf("Use: %s <tamanhoVetor> <max_value>\n");
        exit(1);

    }

    int tam_vetor = atoi(*(argv+1));
    int max_value = atoi(*(argv+2));

    int *vetor_x = calloc( tam_vetor, sizeof(int)*tam_vetor );

    int *vetor_y = calloc( tam_vetor, sizeof(int)*tam_vetor );

    if((!vetor_x) || (!vetor_y)){
        puts("Memória Indisponível.");
        exit(2);
    }

    printf("\nVetor X: \n");
    gerarVetor(vetor_x, tam_vetor, max_value);
    exibirVetor(vetor_x, tam_vetor);

    printf("\nVetor Y: \n");
    gerarVetor(vetor_y, tam_vetor, max_value);
    exibirVetor(vetor_y, tam_vetor);

    printf("\nMatriz das frequências: \n");
    int **M = alocarMatriz(max_value);
    contarFrequencia(vetor_x, vetor_y, M, tam_vetor);
    exibirMatriz(M, max_value);

    // Desalocação de memória:

    free(vetor_x);
    free(vetor_y);

    for(int i = 0; i<max_value; i++){

        free(*(M+i));

    }

    free(M);

    return 0;
}

int** alocarMatriz(int max){

    int **matriz = NULL;

    if(!(matriz = (int**) calloc(max, sizeof(int*) * max))){
        puts("Memória Indisponível.");
        exit(3);
    }

    for(int i = 0; i<max; i++){

        if(!(*(matriz+i) = (int*) calloc(max, sizeof(int) * max))){
            puts("Memória Indisponível");
            exit(4);
        }
    }

    return matriz;

}

void gerarVetor(int *vet, int tam, int max){

    for(int i = 0; i<tam; i++){
        *(vet+i) = rand() % max;
    }
}

void exibirVetor(int *vet, int tam){

    printf("\n");

    for(int i = 0; i<tam; i++){

        printf("%3d ", *(vet +i));
    }
    printf("\n\n");
}

void contarFrequencia(int *vet1, int *vet2,int **matriz, int tam){

    for(int i = 0; i<tam; i++){

        int a = *(vet1+i);
        int b = *(vet2+i);

        *(*(matriz + a)+b) += 1;

    }
}

void exibirMatriz(int **matriz, int max){

    printf("\n");

    for(int i = 0; i<max; i++){
        for(int j = 0; j<max; j++){

            printf("%d ", *(*(matriz+i)+j));

        }

        printf("\n");
    }

}