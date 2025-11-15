#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TAM 15

int main(){

    char string[TAM];
    char caractere;

    puts("Digite uma string: ");
    fgets(string, TAM, stdin);
    string[strcspn(string, "\n")] = '\0'; //Troca o /n por /0, finalizando a string.

    puts("Digite um cacactere: ");
    caractere = getchar();

    int flag = 0;

    for(int i = 0; string[i] != '\0'; i++){

        if(toupper(caractere) == toupper(string[i])){
            flag = 1;
            break;
        }
    }

    if(flag){
        printf("\nO caracter '%c' esta na string (%s).\n",caractere, string);
    }
    else{
        printf("\nO caracter '%c' não esta na string (%s).\n",caractere, string);
    }
    return 0;
}