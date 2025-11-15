#include <stdio.h>

int main(){

    int a;

    puts("Entre com um número: ");
    scanf("%d", &a);

    a%2? puts("É impar"):puts("É par");

    return 0;
}