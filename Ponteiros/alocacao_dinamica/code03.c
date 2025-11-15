// Parâmetros da função main - int argc , char argv[] 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* alocarVetor(int tam);
void gerarVetor(int *vet, int tam);
void exibirVetor(int *vet, int tam);
void reordenarVetor(int *vet, int tam);

#define RG 100

int main(int argc, char **argv){

    srand(time(NULL));

    if(argc != 2){
        printf("Use: \t %s <tamanho_vetor>\n", *argv);
        exit(1);
    }

    int tam = atoi(*(argv + 1));

    int *vetor = alocarVetor(tam);

    gerarVetor(vetor, tam);

    printf("\nVetor Original: \n");
    exibirVetor(vetor, tam);

    reordenarVetor(vetor, tam);
    printf("\nVetor Reordenado: \n");
    exibirVetor(vetor, tam);

    return 0;
}

int* alocarVetor(int tam){

    int *vet = NULL;

    if(!(vet = (int*) malloc(sizeof(int) * tam))){
        puts("Memória Indisponível.");
        exit(2);
    }

    return vet;

}

void gerarVetor(int *vet, int tam){

    for (int i = 0; i < tam; i++)
    {
        *(vet+i) = rand() % RG;
    }

}

void exibirVetor(int *vet, int tam){

    for(int i = 0; i < tam; i++){

        printf("%3d ", *(vet + i));
    }

}

void reordenarVetor(int *vet, int tam){

    int aux;

    for(int i = 1, j = tam-2; i < j; i++, j--){

        aux = *(vet + i);

        *(vet + i) = *(vet + j);

        *(vet + j) = aux;
    }

}