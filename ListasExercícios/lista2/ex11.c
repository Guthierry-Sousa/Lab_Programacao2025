#include <stdio.h>

int main(){

    int a, b;

    int aux;

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

        if( i%4 == 0 )
            printf("%d^2 = %d\n", i, i*i);

    }

    return 0;
}