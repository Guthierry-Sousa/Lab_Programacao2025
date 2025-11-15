#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100


int main(){

    srand(time(NULL));

    int vetor[TAM];
    int min, max;

    puts("Informe o limite inferior do intervalo: ");
    scanf("%d", &min);

    puts("Informe o limite superior do intervalo: ");
    scanf("%d", &max);

    for(int i = 0; i<TAM; i++){
        vetor[i] = min + rand() % max; //[min, max-1]
    }

    puts("Vetor original: ");
    for(int i = 0; i<TAM; i++){
        printf("vetor[%d] = %d\n",i, vetor[i]);
    }

    // Algoritimo de ordenção - Selection
    int minimo, aux;

    for(int i = 0; i<TAM-1; i++){

        minimo = i;

        for(int j = i+1; j<TAM; j++){

            if(vetor[minimo] > vetor[j]){
                minimo = j;
            }

        }

        if(minimo!=i){
            aux = vetor[minimo];
            vetor[minimo] = vetor[i];
            vetor[i] = aux;
        }

    }
    puts("Vetor ordenado: ");
    for(int i = 0; i<TAM; i++){
        printf("vetor[%d] = %d\n",i, vetor[i]);
    }
    return 0;

}