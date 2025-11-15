// Algoritmo - Insertion Sort | Complexidade: O(n²)

// Estabilidade: SIM - Não troca elementos iguais

#include <stdio.h>

#define TAM 10

int main(){

    int vetor[TAM] = {14, 22, 88, 87, 46, 25, 14, 93, 2, 101};
    
    int aux;

    for(int i = 1; i<TAM; i++){

        aux = vetor[i];
        int j;

        for(j = i-1; j>=0 && vetor[j]>aux; j--){

            vetor[j+1] = vetor[j];
            
        }
        vetor[j+1] = aux;
    }

    for(int k = 0; k<TAM; k++){

        printf("Vetor [%d] = %d\n", k, vetor[k]);

    }
    

    return 0;
}