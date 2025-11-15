#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 15

int main(){

    char string_1[TAM];

    char inversa[TAM];

    int i,j;

    puts("Informe uma string(1): ");
    fgets(string_1, TAM, stdin);

    string_1[strcspn(string_1, "\n")] = '\0';

    for(i = strlen(string_1)-1, j = 0; i >= 0; i--, j++){

        inversa[j] = string_1[i];
    }

    inversa[j] = '\0';
    
    printf("String (%s) invertida = %s\n", string_1, inversa);

    return 0;
}