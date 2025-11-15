#include <stdio.h>


int main(){

    int a, b;

    int aux;

    int soma = 0;

    puts("Informe um valor: ");
    scanf("%d", &a);

    puts("Informe um outro valor: ");
    scanf("%d", &b);


    // Caso A>B: Inverte os valores;
    if(a>b){

        aux = a;

        a = b;
        
        b = aux;

    }

    for(int i = a; i<=b; i++){
        if(i%2==0){
            soma+=i;
        }
    }

    printf("Somatório dos números pares de %d até %d = %d\n", a, b, soma);

    return 0;
}