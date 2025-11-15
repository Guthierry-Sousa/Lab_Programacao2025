#include <stdio.h>

int main(){
    
    int n, v;

    puts("Informe um valor: ");
    scanf("%d", &n);
    
    v=n;

    while(n!=0){

        v = (n>v)?n:v;

        printf("Maior Valor: %d\n", v);

        puts("Informe um valor: ");
        scanf("%d", &n);
        
    }

    return 0;
    
}