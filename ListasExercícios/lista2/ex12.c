#include <stdio.h>

int main(){

    int n;

    int op;

    puts("Informe um número: ");
    scanf("%d", &n);

    puts("Selecionar Operação:");
    puts("1 - Soma");
    puts("2 -  Subtração");
    puts("3 -  Multiplicação");
    puts("4 -  Divisão");
    scanf(" %d", &op);

    if(n==0 && op==4){
        puts("Não existe divisão por 0.");
        return 1;
    }

    for(int i = 1; i<=10; i++){
        switch(op){

            case 1:
                
                    printf("%d + %d = %d\n", i , n, i+n);
                
                break;
            case 2:
                
                    printf("%d - %d = %d\n", i+n , n, (i+n)-n);
                
                break;
            case 3:
                
                    printf("%d * %d = %d\n", i , n, i*n);
                
                break;
            case 4:
                    printf("%d / %d = %.2f\n", i, n, (float)i/n);

                break;
        }
    }
    return 0;
}