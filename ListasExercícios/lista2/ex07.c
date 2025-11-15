#include <stdio.h>

int main(){

    float a, b;

    puts("Informe dois números: ");
    scanf("%f%f", &a, &b);

    while(b==0){

        puts("Não é possível divisão por 0.");
        puts("Tente novamente.");

        puts("Informe dois números: ");
        scanf("%f%f", &a, &b);
    }

    printf("%.2f / %.2f = %.2f\n", a ,b ,a/b);

    return 0;
}