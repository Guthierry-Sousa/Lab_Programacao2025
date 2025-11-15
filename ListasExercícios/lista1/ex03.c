#include <stdio.h>

int main(){

    int num;

    puts("Entre com um número: ");
    scanf("%d", &num);

    printf("%d ao quadrado = %d\n", num, num*num);

    printf("Triplo de %d = %d\n", num, num*3);
    
    printf("Meio de %d = %.2f\n", num, num*0.5);

    return 0;
}