// Vetores e Aritmética de ponteiros

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20
#define RG 100

// Procedimento - Imprimir Vetor
void imprimirVetor(int *v, int tam);
void imprimirLetras(char *nome, int tam);

// Procedimento - Preencher um vetor
void preencherVetor(int *v,int tam);


int main(){

    char name[TAM];
    int vet[TAM];

    printf("Informe seu nome: ");
    fgets(name, TAM, stdin);

    preencherVetor(vet, TAM);

    // O nome do vetor é um ponteiro, pois ele armazena o endereço do primeiro elemento do vetor

    imprimirVetor(vet, TAM);

    printf("\n\n");
    imprimirLetras(name, TAM);

    return 0;

}

void imprimirVetor(int *v, int tam){

    // Aritmética de ponteiros
    for(int i = 0; i<tam; i++){
        printf("vet[%d] = %d\n", i, *(v + i));
    }

}

void imprimirLetras(char *nome, int tam){

    for(int i = 0; i<tam; i++){

        if(*(nome+i) == '\0') break;;

        printf("name[%d] = %c\n", i, *(nome + i));
    }

}

// Altera o vetor por referência
void preencherVetor(int *v ,int tam){

    srand(time(NULL));

    for(int i = 0; i<tam; i++){

        *(v + i) = rand()%RG;

    }

}
