#include <stdio.h>

int main(){

    int n;

    int maior_num, menor_num;

    puts("Informe um número: ");
    scanf("%d", &n);

    maior_num = menor_num = n;
    
    while(n!=0){

        maior_num = (n>maior_num)? n: maior_num;
        printf("Maior número: %d\n", maior_num);
        
        menor_num = (n<menor_num)? n: menor_num;
        printf("Menor número: %d\n", menor_num);


        puts("Informe um número: ");
        scanf("%d", &n);

    }

    puts("Programa finalizado.");

    return 0;
}