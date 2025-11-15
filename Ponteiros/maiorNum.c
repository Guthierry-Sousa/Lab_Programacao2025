// Gerar um vetor com valores(tipo float) aleatórios;
// Informar o maior número;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// Gerar Vetor
void gerarVetor(float *vet, int tam); // Protótipo do procedimento

// Encontrar o maior valor
float maiorValor(float *vet, int tam); // protótipo da função (retorna o maior número)

// Imprimir o vetor
void imprimirVetor(float *vet, int tam);// Procedimento para imprimir um vetor

int main(){

    float vetor[TAM];

    gerarVetor(vetor, TAM);
    imprimirVetor(vetor, TAM);

    float maior_valor = maiorValor(vetor, TAM);

    printf("Maior valor do vetor = %f\n",maior_valor);

    return 0;
}

void gerarVetor(float *vet, int tam){

    srand(time(NULL));

    for(int i = 0; i<tam; i++){

        *(vet+i) =  (float)rand() / RAND_MAX;

    }

}
float maiorValor(float *vet, int tam){

    float maiorNum = *vet;

    for(int i = 1; i<tam-1; i++){

        if(*(vet+i) > maiorNum){

            maiorNum = *(vet + i);

        }

    }

    return maiorNum;

}
void imprimirVetor(float *vet, int tam){

    for(int i = 0; i<tam; i++){

        printf("vetor[%d] = %f | Endereço: %p\n", i, *(vet + i), vet+i);

    }
}