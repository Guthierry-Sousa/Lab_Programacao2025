// Introdução a ponteiros

#include <stdio.h>

int main(){

    // Valor 1 - Ponteiro (armazena um endereço de memória) para um inteiro
    int *valor1, valor2 = 50;

    // Letra 1 - Ponteiro (armazena um endereço de memória) para um char
    char *letra1, letra2 = 'g';

    // & - Obter o endereço de memória
    valor1 = &valor2;
    letra1 = &letra2;

    // Imprimindo o valor e o endereço das variáveis
    printf("Valor de valor2 = %d\n", valor2);
    printf("Valor de letra2 = %c\n", letra2);
    printf("Endereço de valor2 = %p\n", &valor2);
    printf("Endereço de letra2 = %p\n", &letra2);

    printf("\n\n");
    // Imprimindo o valor dos ponteiros e o conteudo apontado pelos ponteiros
    printf("Valor de valor1 = %p\n", valor1);
    printf("Valor de letra1 = %p\n", letra1);
    printf("Conteudo apontado por valor1 = %d\n", *valor1);
    printf("Conteudo apontado por letra1 = %c\n", *letra1);

    return 0;
}