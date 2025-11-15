#include <stdio.h>
#include <stdlib.h>

int main(){

    int *x = malloc(sizeof(int)), *y = malloc(sizeof(int)); // Alocando memória dinamicamente

    puts("Informe um valor: ");
    scanf("%d", x);

    puts("Informe outro valor: ");
    scanf("%d", y);

    int sum = *x + *y;

    printf("\n%d + %d = %d | Endereço: %p\n",*x, *y, sum, &sum);

    return 0;
}