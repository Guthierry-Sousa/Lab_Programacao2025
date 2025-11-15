#include <stdio.h>

int main(){

    unsigned char a, p;
    unsigned char mask = 0x01;

    puts("Informe um número: ");
    scanf("%hhu", &a);

    puts("Informe a posição do bit que você quer ligar: ");
    scanf("%hhu", &p);

    mask<<=(p-1);

    a|=mask;

    printf("Código Final: %hhu\n", a);

    return 0;
}