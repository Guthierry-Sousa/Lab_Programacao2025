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

    // Algoritimo de ordenção - Bubble
    int flag, aux;

    for(int i = 0; i<TAM-1; i++){

        flag = 1;

        for (int j = 0; j<TAM-1-i; j++){

            if(vetor[j]>vetor[j+1]){
                
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;

                flag = 0;
            }
        }
        if(flag) break;

    }
    puts("Vetor ordenado: ");
    for(int i = 0; i<TAM; i++){
        printf("vetor[%d] = %d\n",i, vetor[i]);
    }
    return 0;

}