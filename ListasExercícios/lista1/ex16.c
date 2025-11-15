#include <stdio.h>

int main(){

    int a;

    puts("Entre com um número: ");
    scanf("%d", &a);

    a = a < 0? -a: a;

    printf("Valor Absoluto de a : %d\n", a);

    return 0;
}