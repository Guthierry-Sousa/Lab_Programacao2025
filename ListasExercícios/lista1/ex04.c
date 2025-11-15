#include <stdio.h>

int main(){

    float valor_conta, valor_total;

    puts("Entre com o valor da conta: ");
    scanf("%f", &valor_conta);

    valor_total = valor_conta * 1.1; // 10% de taxa para o garçom;

    printf("Valor total incluindo taxa para o garçom: R$%.2f", valor_total);

    return 0;
}