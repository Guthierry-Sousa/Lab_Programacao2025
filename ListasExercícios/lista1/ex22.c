#include <stdio.h>

int main(){
    
    char num[4], aux;

    puts("Informe um número de 3 dígitos:");
    scanf("%s", &num);

    aux = num[0];
    num[0] = num[2];
    num[2] = aux;
    

    printf("Numero Invertido: %s",num);

    return 0;
}