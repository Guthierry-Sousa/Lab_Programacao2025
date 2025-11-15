#include <stdio.h>

int main(){

    int a, b;

    int somatorio = 0;

    float media;

    // Entrada da faixa específicada pelo usuário:
    puts("Infome o valor inicial: ");
    scanf("%d", &a);

    puts("Infome o valor final: ");
    scanf("%d", &b);

    for(int i = a; i<=b; i++){
        somatorio+=i;
    }

    media = (float) somatorio/(b-a+1);

    printf("Média dos números no intervalo [%d, %d] = %.2f\n", a, b, media);

    return 0;
}