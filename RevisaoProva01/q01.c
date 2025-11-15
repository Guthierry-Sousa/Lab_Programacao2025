#include <stdio.h>

int main(){

    float x, entrada, saida;
    float y = 1.0;
    float limite = 0.00001;

    puts("Informe um valor: ");
    scanf("%f", &entrada);

    x = entrada;

    while((x-y)>limite || (y-x)>limite){

        x = (x+y)/2;
        y = entrada/x;

    }

    saida = x;
    printf("Valor final: %f\n", saida);

    return 0;
}