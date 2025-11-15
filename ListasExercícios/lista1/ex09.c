#include <stdio.h>

int main(){

    float vol, comp, larg, alt;

    puts("Informe o comprimento da caixa:");
    scanf("%f", &comp);

    puts("Informe a largura da caixa:");
    scanf("%f", &larg);

    puts("Informe a altura da caixa:");
    scanf("%f", &alt);

    vol = comp * alt * larg;

    printf("Volume da caixa = %.2f m³", vol);

    return 0;
}