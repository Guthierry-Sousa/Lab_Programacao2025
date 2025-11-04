// Utilizando strcomp()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 15

int main(){

    char string_1[TAM];
    char string_2[TAM];

    puts("Informe uma string(1): ");
    fgets(string_1, TAM, stdin);

    puts("Informe uma string(2): ");
    fgets(string_2, TAM, stdin);

    if(!(strcmp(string_1,string_2))){
        puts("Strings iguais");
    }
    else{
        puts("Strings diferentes");
    }

    return 0;
}