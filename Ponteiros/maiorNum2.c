#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// Preenche um vetor com números aleatórios
void preencherVetor(float *vet, int tam); // Protótipo
//imprimir vetor
void imprimirVetor(float *vet, int tam); // Protótipo
//Encontrar o maior valor
void maiorValor(float *vet, float *max, int tam); // Protótipo

int main(){

    float vetor[TAM];

    float maior_num;
    float *pMaiorNum = &maior_num;

    preencherVetor(vetor, TAM);

    imprimirVetor(vetor, TAM);

    maiorValor(vetor, pMaiorNum, TAM);

    printf("\nO maior valor do vetor é: %f\n", *pMaiorNum);

    return 0;
}

void preencherVetor(float *vet, int tam){

    srand(time(NULL));

    for(int i = 0; i<tam; i++){

        *(vet+i) = (float) rand()/RAND_MAX;
    }
}

void imprimirVetor(float *vet, int tam){

    for(int i = 0; i<tam; i++){
        printf("vetor[%d] = %f\n", i, *(vet+i));
    }
}

void maiorValor(float *vet, float *max, int tam){
    
    *max = *vet;

    for(int i = 1; i<tam; i++){

        if(*(vet+i) > *max){
            *max = *(vet+i);
        }
    }
}