#include <stdio.h>

// Foŕmula = 2^n - 1

int main(){

    long unsigned int qtd_graos = 0;

    long unsigned int qtd_graos_casa = 1;


    for(int i = 1; i<=64; i++){

        qtd_graos+=qtd_graos_casa;

        qtd_graos_casa*=2;

    }

    printf("Somatório dos grãos = %lu\n", qtd_graos);

    return 0;
}