#include <stdio.h>

int main(){

    int a, b, aux;

    int qtd = 0;

    puts("Informe dois valores: ");
    scanf("%d%d", &a ,&b);

    if(a>b){
        aux = a;

        a = b;

        b = aux;
    }

    for(int i = a; i<=b; i++){
        if(i%3==0){
            qtd++;
        }
    }
    printf("Quantidades de números múltiplos de 3 de %d até %d: %d\n", a, b, qtd);

    return 0;
}