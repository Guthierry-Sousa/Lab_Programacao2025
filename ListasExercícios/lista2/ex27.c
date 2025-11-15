#include <stdio.h>

int main(){

    int num;

    int maior_num;

    int menor_num;

    int prod, cont = 0;

    puts("Informe um número: ");
    scanf("%d",&num);

    menor_num = maior_num = num;

    while((num%2) || (num>=0)){

        maior_num = (num>maior_num)?num:maior_num;

        menor_num = (num<menor_num)?num:menor_num;

        printf("Maior número = %d\n", maior_num);

        printf("Menor número = %d\n", menor_num);

        puts("Informe um número: ");
        scanf("%d",&num);

        cont++;
    }

    if(cont>0){

        prod = maior_num*menor_num;

        printf("Produto do maior número pelo menor: %d x %d = %d\n", maior_num, menor_num, prod);
    }

    puts("Programa Finalizado.");

    return 0;
}