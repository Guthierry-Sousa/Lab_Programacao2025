// Detector de palíndromo;

#include <stdio.h>

int main(){

    int a;

    unsigned char digitos[6];

    puts("Informe um número de 5 dígitos: ");
    scanf("%d", &a);

    int num_original = a;

    for(int i = 0; i<5; i++){

        digitos[i] = a%10;

        a = a/10;

    }

    if((digitos[0]==digitos[4]) && (digitos[1]==digitos[3])){
        printf("%d é um palíndromo\n", num_original);
    }
    else{
        printf("%d não é um palíndromo\n", num_original);
    }

    return 0;
}