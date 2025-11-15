#include <stdio.h>

int main(){

    float valor_liquido;
    unsigned char dias;

    puts("Informe a quantidade de dias trabalhados: ");
    scanf("%hhu", &dias);

    if (dias <= 10){
        // Sem gratificação
        valor_liquido = 50.25 * dias;

    }

    else if (dias<=20){
        // Gratificação - 20%
        valor_liquido = 50.25 * dias * 1.20;

    }

    else{
        // Gratificação - 30%
        valor_liquido = 50.25 * dias * 1.30;
    }

    // Imposto de renda - 10%
    valor_liquido *= 0.9;

    printf("Valor Líquido = R$%.2f\n", valor_liquido);

    return 0;
}