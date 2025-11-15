#include <stdio.h>

int main(){

    float cot_dollar, real, dollar;

    puts("Informe a cotação atual: ");
    scanf("%f", &cot_dollar);

    puts("Informe o valor a ser convertido: ");
    scanf("%f", &real);

    dollar = real/cot_dollar;

    printf("Valor convertido: US$%.3f", dollar);

    return 0;
}