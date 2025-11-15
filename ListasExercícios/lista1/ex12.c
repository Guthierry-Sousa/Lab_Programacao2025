#include <stdio.h>

int main(){

    char a, b, aux;

    puts("Informe o valor de a: ");
    scanf("%hhd", &a);

    puts("Informe o valor de b: ");
    scanf("%hhd", &b);

    aux = a;
    a = b;
    b = aux;

    printf("a = %hhd | b = %hhd", a, b);

    return 0;
}