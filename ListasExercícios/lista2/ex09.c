// Algoritmo de fibonacci; 

// A questão fixa o número de algarismos (20);

#include <stdio.h>

int main(){

    int atual = 1, next, anterior = 0;

    int i = 0;

    for(i; i<=20; i++){

        printf(" %d ", atual);

        next = atual + anterior;

        anterior = atual;

        atual = next;
        
    }

    return 0;
}