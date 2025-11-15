#include <stdio.h>

int main(){

    int x,y;

    puts("Informe o valor inicial: ");
    scanf("%d", &x);

    puts("Informe o valor final: ");
    scanf("%d", &y);

    int somatorio = 0;

    for(x; x<=y; x++){

        if(x%2==0){

            somatorio += x;

        }
    }

    printf("Somatorio = %d\n", somatorio);

    return 0;
    
}