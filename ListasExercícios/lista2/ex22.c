#include <stdio.h>

int main(){

    int num, aux;

    int qtd_7 = 0;

    puts("Informe um número: ");
    scanf("%d", &num);

    int num_original = num;

    while(num>0){

        aux = num%10;

        if(aux==7){
            qtd_7++;
        }

        num = num/10;

    }

    printf("Número ' %d ' possui %d sete(s).\n", num_original, qtd_7);

    return 0;
}