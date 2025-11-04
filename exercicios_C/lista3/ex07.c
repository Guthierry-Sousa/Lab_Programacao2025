#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM 3
#define RG 20

int main(){

    srand(time(NULL));

    int vetor[TAM];

    for(int i = 0; i<TAM; i++){
        vetor[i] = rand() % 20; //[0,19]
    }
    for(int i = 0; i<TAM; i++){
        printf("vetor[%d] = %d\n",i, vetor[i]);
    }

    // Média Aritmética
    float media_aritmetica = 0;
    float somatorio = 0;

    for(int i = 0; i<TAM; i++){

        somatorio += vetor[i];
    }

    media_aritmetica = somatorio/TAM;
    printf("Média Aritmética: %f\n", media_aritmetica);

    // Média Geométrica
    float media_geometrica = 0;
    float produtorio = 1;

    for(int i = 0; i<TAM; i++){

        produtorio *= vetor[i];
    }

    media_geometrica = cbrt(produtorio);
    printf("Média Geomética: %f\n", media_geometrica);

    return 0;
}