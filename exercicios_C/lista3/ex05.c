// Utilizando strcat()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 15

int main(){

    char string_1[TAM];
    char string_2[TAM];

    puts("Informe uma string(1): ");
    fgets(string_1, TAM, stdin);

    string_1[strcspn(string_1, "\n")] = '\0';

    puts("Informe uma string(2): ");
    fgets(string_2, TAM, stdin);

    string_2[strcspn(string_2, "\n")] = '\0';

    printf("Strings concatenadas = %s\n", strcat(string_1, string_2));

    return 0;
}