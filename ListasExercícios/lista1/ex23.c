#include <stdio.h>

int main(){

    int x, n;

    puts("Informe o número que vc quer multiplicar por 2^n: ");
    scanf("%d", &x);

    puts("Informe a potência do 2: ");
    scanf("%d", &n);

    x = x << n;

    printf("Resultado = %d", x);

    return 0;
}