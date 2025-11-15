// Não utilizando strcat()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 15
#define TAM_CAT 30

int main(){

    char string_1[TAM];
    char string_2[TAM];

    char string_concatenada[TAM_CAT];

    puts("Informe uma string(1): ");
    fgets(string_1, TAM, stdin);

    string_1[strcspn(string_1, "\n")] = '\0';

    puts("Informe uma string(2): ");
    fgets(string_2, TAM, stdin);

    string_2[strcspn(string_2, "\n")] = '\0';

    int i = 0;

    while (string_1[i] != '\0')
    {
        string_concatenada[i] = string_1[i];
        i++;
    }

    int j = 0;

    while (string_2[j] != '\0')
    {
        string_concatenada[i] = string_2[j];
        i++;
        j++;
    }

    string_concatenada[i] = '\0';
    
    printf("Strings concatenadas = %s\n", string_concatenada);

    return 0;
}