// Matriz de Frequências Cruzadas

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarVetor(int *, const int, const int);
void exibirVetor(int *, const int);
int **alocarMatriz(const int);
void matrizFrequencia(int **, int*, int*, const int);
void exibirMatriz(int **, const int);

int main(int argc, char **argv){

    srand(time(NULL));

    if(argc != 3){
        printf("Use: %s <tamanhoVetor> <limite>\n", *argv);
        exit(1);
    }

    int tam_vetor = atoi(*(argv+1));
    int limite_max = atoi(*(argv+2));
    
    int *vetor_x = malloc(sizeof(int) * tam_vetor);
    int *vetor_y = malloc(sizeof(int) * tam_vetor);

    if((!vetor_x) || (!vetor_y)){
        puts("Memória Indisponível.");
        exit(2);
    }

    // Trabalhando com os vetores

    printf("Vetor X: \n");
    gerarVetor(vetor_x, tam_vetor, limite_max);
    exibirVetor(vetor_x, tam_vetor);

    printf("Vetor Y: \n");
    gerarVetor(vetor_y, tam_vetor, limite_max);
    exibirVetor(vetor_y, tam_vetor);

    // Trabalhando com a matriz

    int **M = alocarMatriz(limite_max);
    matrizFrequencia(M, vetor_x, vetor_y, tam_vetor);

    printf("\nMatriz de Frequência: \n");
    exibirMatriz(M, limite_max);

    // Desalocando Memória

    free(vetor_x);
    free(vetor_y);

    for(int i = 0; i<limite_max; i++){
        free(*(M+i));
    }

    free(M);
    
    return 0;
}

void gerarVetor(int *vet, const int tam, const int max){

    for(int i = 0; i<tam; i++){

        *(vet + i) = rand() % max;
    }
}

void exibirVetor(int *vet, const int tam){

    printf("\n");
    for(int i = 0; i<tam; i++){

        printf("%5d ", *(vet+i));

    }
    printf("\n\n");
}

int **alocarMatriz(const int max){

    int **matriz = NULL;

    if(!(matriz = (int**) calloc(max, sizeof(int*)))){

        puts("Memória Indisponível.");
        exit(3);

    }

    for(int i = 0; i<max; i++){

        if(!(*(matriz+i) = (int*) calloc(max, sizeof(int)))){

            puts("Memória Indisponível.");
            exit(4);

        }

    }

    return matriz;
}

void matrizFrequencia(int **matriz, int *vet1, int *vet2, const int tam){

    for(int i = 0; i<tam; i++){

        int x = *(vet1 + i);
        int y = *(vet2 + i);

        *(*(matriz + x) + y) += 1;
    }

}

void exibirMatriz(int **matriz, const int max){

    printf("\n");
    for(int i = 0; i<max; i++){
        for(int j = 0; j<max; j++){

            printf("%4d ", *(*(matriz + i)+j));

        }

        printf("\n");
    }

    printf("\n");
}