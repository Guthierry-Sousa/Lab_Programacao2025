// Não Utilizando strcomp()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 15

int main(){

    char string_1[TAM];
    char string_2[TAM];

    int i = 0;

    int iguais = 1;

    puts("Informe uma string(1): ");
    fgets(string_1, TAM, stdin);

    puts("Informe uma string(2): ");
    fgets(string_2, TAM, stdin);

    // Faz o loop até o final da string, caso encontre diferença o valor da variável iguais muda, sinalizando uma diferença.

    while(string_1[i] != '\n' && string_2[i]!='\n'){

        if(string_1[i] != string_2[i]){
            iguais = 0;
            break;
        }
        i++;
    }

    if(iguais) puts("Strings Iguais");

    else puts("Strings Diferentes.");

    return 0;
}