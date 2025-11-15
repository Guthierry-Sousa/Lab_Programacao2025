#include <stdio.h>

int main(){

    int a, b;

    puts("Entre com um número: ");
    scanf("%d", &a);

    puts("Entre com outro número: ");
    scanf("%d", &b);

    a%b ? printf("%d não é múltiplo de %d\n", a, b) : printf("%d é múltiplo de %d\n", a, b);

    return 0;
}