#include <stdio.h>

int main(){

    int num;

    int fat = 1;

    puts("Informe um número: ");
    scanf("%d", &num);

    if(num<0){
        printf("\n%d : Número Negativo (Não possui fatorial).\n", num);
    }
    
    else{
        for(int x = 1; x<=num; x++){
            fat*=x;

        }   
        printf("%d! = %d", num, fat);   
    }

    

    return 0;
}