// entrada + 2 prestações (entrada >= prestações)
// restações (iguais, inteiras e maiores possíveis)

#include <stdio.h>

int main(){

    float valor_prod;

    float entrada;

    int prestacoes;

    puts("Informe o valor do produto: ");
    scanf("%f", &valor_prod);

    prestacoes = (valor_prod/3);

    entrada = valor_prod - (2*prestacoes);

    printf("Valor do produto = R$%.2f\n", valor_prod);

    printf("Entrada = R$%.2f | Prestações = R$%.2f \n", entrada,(float) prestacoes);
    
    return 0;
}