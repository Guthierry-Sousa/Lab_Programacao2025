#include <stdio.h>

int main(){

    float altura, peso;
    char sexo;

    puts("Entre com seu sexo:");
    puts("1 - Feminino");
    puts("0 - Masculino");
    scanf("%hhd", &sexo);

    puts("Entre com sua altura (m):");
    scanf("%f", &altura);

    if(sexo)
        peso = (62.1 * altura) - 44.7; // Fórmula p/ mulheres;
    else
        peso = (72.7 * altura) - 58; // Fórmula p/ homens;

    printf("Peso Ideal = %.1fkg\n", peso);


    return 0;
}