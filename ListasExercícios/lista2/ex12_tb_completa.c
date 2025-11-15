// Tabuada;

#include <stdio.h>

int main(){

    int n;

    puts("Informe um número: ");
    scanf("%d", &n);

    for(int i = 1; i<=10; i++){

        printf("%d + %d = %d\t", i , n, i+n);
        printf("%d - %d = %d\t", i+n , n, (i+n)-n);
        printf("%d * %d = %d\t", i , n, i*n);

        if (n!=0){
            printf("%d / %d = %f\n", i, n, (float)i/n);
        }
        
        else{
            printf("%d / %d = Não existe divisão por 0 \n", i, n);
        }

    }

    return 0;
}