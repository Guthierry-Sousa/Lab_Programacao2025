#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 15
#define RX 100

void gerarVetor(float *vet, int tam);
float* getMaior(float *vet, int tam);
float* getMenor(float *vet, int tam);
void exibirVetor(float *vet, int tam);

int main(){

    float vetor[TAM];

    gerarVetor(vetor, TAM);
    exibirVetor(vetor, TAM);
    
    float *maior = getMaior(vetor, TAM);
    float *menor = getMenor(vetor, TAM);

    printf("Maior: %f | Menor: %f | Soma = %f\n", *maior, *menor, *maior+(*menor));

    return 0;
}

void gerarVetor(float *vet, int tam){

    srand(time(NULL));

    for(int i = 0; i<tam; i++){

        *(vet+i) = ((float) rand()/RAND_MAX)*100;

    }
}

float* getMaior(float *vet, int tam){

    float *maior = vet;

    for(int i = 1; i<tam; i++){

        if(*(vet+i) > *maior){

            maior = vet+i; 

        }

    }

    return maior;
}
float* getMenor(float *vet, int tam){

    float *menor = vet;

    for(int i = 1; i<tam; i++){

        if(*(vet+i) < *menor){

            menor = vet+i; 

        }

    }
        return menor;
    

}

void exibirVetor(float *vet, int tam){

    for(int i = 0; i<tam; i++){

        printf("vetor[%d] = %f\n", i, *(vet+i));

    }

}