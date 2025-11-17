// Vetor de Médias por linha

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 100

int **alocarMatriz(const int, const int);
void exibirMatriz(int **, const int, const int);
void preencherMatriz(int **, const int, const int);
void vetorMedia(double *, int **, const int, const int, double (*media)(int*, int));
double media(int*, int);
void exibirVetor(double *, const int);

int main(int argc, char **argv){

    srand(time(NULL));

    if(argc != 3){
        printf("Use: %s <qtd_linhas> <qtd_colunas>\n", *argv);
        exit(1);
    }

    int lin = atoi(*(argv+1));
    int col = atoi(*(argv+2));

    double *vetor_media = calloc(lin, sizeof(double));

    if(!(vetor_media)){
        puts("Memória Indisponível.");
        exit(2);
    }

    int **M = alocarMatriz(lin, col);
    printf("\nMatriz Gerada: \n");
    preencherMatriz(M, lin, col);
    exibirMatriz(M, lin, col);

    printf("\nVetor das média de cada linha da matriz: ");
    vetorMedia(vetor_media, M, lin, col, media);
    exibirVetor(vetor_media, lin);

    free(vetor_media);

    for(int i = 0; i<lin; i++){
        free(*(M+i));
    }

    free(M);

    return 0;
}

int **alocarMatriz(const int linhas, const int colunas){

    int **matriz = NULL;

    if(!(matriz = (int**) calloc(linhas, sizeof(int*)))){

        puts("Memória Indisponível.");
        exit(3);

    }

    for(int i = 0; i<linhas; i++){

        if(!(*(matriz+i) = (int*) calloc(colunas, sizeof(int)))){

            puts("Memória Indisponível.");
            exit(4);

        }

    }

    return matriz;
}

void exibirMatriz(int **matriz, const int linhas, const int colunas){

    printf("\n");

    for(int i = 0; i<linhas; i++){
        for(int j = 0; j<colunas; j++){

            printf("%4d ", *(*(matriz + i)+j));

        }

        printf("\n");
    }

    printf("\n");
}

void preencherMatriz(int **matriz, const int linhas, const int colunas){

    for(int i = 0; i<linhas; i++){
        for(int j = 0; j<colunas; j++){

            *(*(matriz+i)+j) = rand() % RANGE;
        }
    }
}

void vetorMedia(double *vetor, int **matriz, const int linhas, const int colunas, double (*calcMedia)(int*, int)){

    for(int i = 0; i<linhas; i++){
        *(vetor+i) = (*calcMedia)(*(matriz+i), colunas);
    }

}

double media(int* vetor_linha, int colunas){

    double somatorio = 0;

    double mean = 0;

    for(int i = 0; i<colunas; i++){

        somatorio = somatorio + *(vetor_linha + i);

    }

    mean = somatorio/colunas;

    return mean;

}

void exibirVetor(double *vetor, const int tam){

    printf("\n");

    for(int i = 0; i<tam; i++){

        printf("%7.1lf ", *(vetor + i));
    }
    printf("\n\n");
}