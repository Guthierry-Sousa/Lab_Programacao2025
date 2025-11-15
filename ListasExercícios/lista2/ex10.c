#include <stdio.h>

// Faixa de valores definida: 15 até 90

int main(){

    int i = 15;

    for(i; i<=90; i++){

        if(i%4==0){

            printf("%d^2 = %d\n", i, i*i);

        }

    }

    return 0;
}