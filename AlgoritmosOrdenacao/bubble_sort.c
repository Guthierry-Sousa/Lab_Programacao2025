// Algoritmo - Bubble Sort | Complexidade: O(n²)

// Melhor caso: O(n)
// Espaço: O(1)
// Estabilidade: SIM (Não muda a ordem relativa dos elementos)

#include <stdio.h>

#define TAM 10

int main(){

    int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int aux, flag;

    for(int i = 0; i<TAM-1; i++){

        flag = 1;

        // (j<TAM-1-i) -> Encurta a área de busca a cada nova interação.
        for(int j = 0; j<TAM-1-i; j++){

            if(vetor[j]>vetor[j+1]){

                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;

                flag = 0;
            }
        }
        if(flag) break; // Interrompe quando o vetor ja estiver ordenado;
    }


    for(int k = 0; k<TAM; k++){

        printf("Vetor [%d] = %d\n", k, vetor[k]);

    }
    

    return 0;
}