#include <stdio.h>

int main(){

    float num;

    puts("Informe um número: ");
    scanf("%f", &num);

    // Escreve o número com apenas uma casa decimal;
    printf("Número = %.1f", num);

    return 0;
}