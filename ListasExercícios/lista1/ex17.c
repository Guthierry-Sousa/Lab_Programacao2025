#include <stdio.h>

int main(){

    float raio, pi = 3.14159;

    puts("Informe o raio do círculo: ");
    scanf("%f", &raio);

    printf("Diâmetro: %.2f m\n", 2 * raio);

    printf("Circunferência: %.2f m\n", 2 * pi * raio);
    
    printf("Área: %.2f m quadrados\n", pi * (raio*raio));

    return 0;
}