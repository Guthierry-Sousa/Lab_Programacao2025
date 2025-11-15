#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 15

int varificarTamanhoString(char *string);

int main(){

    char string[TAM];

    puts("Informe uma string: ");
    fgets(string, TAM, stdin);

    int tam_string = varificarTamanhoString(string);

    printf("Tamanho da string digitada: %d\n", tam_string);

    printf("Tamanho da string digitada com função strlen(): %d\n", strlen(string));

    return 0;
}

int varificarTamanhoString(char *string){

    int i = 0;
    
    while( *(string+i) != '\0'){

        i++;
    }

    return i;

}