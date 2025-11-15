#include <stdio.h>

int main(){

    int a, b;

    puts("Informe o valor de a: ");
    scanf("%d", &a);

    puts("Informe o valor de b: ");
    scanf("%d", &b);

    printf("%d + %d = %d\n", a, b ,a+b);
    printf("%d - %d = %d\n", a, b ,a-b);
    printf("%d * %d = %d\n", a, b ,a*b);
    printf("%d / %d = %.2f\n", a, b ,((float) a)/b);
    printf("%d mod %d = %d\n", a, b ,a%b);


    return 0;
}