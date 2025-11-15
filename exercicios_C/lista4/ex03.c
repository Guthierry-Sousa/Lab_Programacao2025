#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menorNum(int *menor, int *cont);

int main(){

    int menor_num, cont = 1;

    menorNum(&menor_num, &cont);

    if((cont) != 1){
        printf("\nPrograma Finalizado - foi digitado 0.\n");
        printf("\nMenor número de todos: %d\n", menor_num);
    }
    else{

        printf("\nPrograma Finalizado - foi digitado 0 e nenhum outro valor foi digitado.\n");

    }    

    return 0;
}

void menorNum(int *menor, int *cont){

    int num;

    printf("Informe um valor(%d): ", *cont);
    scanf("%d", &num);

    *menor = num;
    
    while (num != 0)
    {

        if(*menor > num){

            *menor = num;

        }

        printf("\nMenor valor Digitado: %d\n", *menor);

        (*cont)++;

        printf("Informe um valor(%d): ", *cont);
        scanf("%d", &num);
    } 
    
}