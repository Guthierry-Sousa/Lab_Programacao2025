// Diferença de pré-incrementar e pós-incrementar;

#include <stdio.h>

int main(){

    int num1 = 6;

    int num2 = 20;

    //Pré-incrementar;
    printf("%d\n",num1);
    printf("%d\n",++num1); //Incrementa primeiro e Printa na tela "7";

    //Pós-incrementar;
    printf("%d\n",num2++); // Printa "20" e depois Incrementra;
    printf("%d\n",num2);

    return 0;
}