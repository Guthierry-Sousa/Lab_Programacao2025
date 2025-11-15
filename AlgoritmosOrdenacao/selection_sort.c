// Algoritmo - Selection Sort | Complexidade - O(n²)

// Espaço: O(1)
// Estabilidade: NÃO - Pode trocar elementos iguais

#include <stdio.h>

#define TAM 10

int main(){

    int vetor[TAM] = {2, 7, 1, 3, 10, 5, 9, 8, 8, 10};

    // Algoritmo:
    int min, aux;

    for(int i = 0; i<TAM-1; i++){

        min = i;

        for(int j = i+1; j<TAM; j++){

            // Encontrando o Indice do menor valor;
            if(vetor[j]<vetor[min]){

                min = j; // Atribui o indice do menor valor ao min;

            }
        }

        // Troca de posição;
        if(min != i){

            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;

        }

    }

    for(int k = 0; k<TAM; k++){

        printf("Vetor [%d] = %d\n", k, vetor[k]);

    }
    

    return 0;
}