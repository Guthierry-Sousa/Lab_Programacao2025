#include <stdio.h>

int main(){

    char num;

    // Entrada de dados;
    puts("Informe um número inteiro: ");
    scanf("%hhd",&num);
    
    // Saída de dados;
    printf("Hexadecimal = %X\n", num);
    printf("Octal = %o\n", num);


    return 0;
}