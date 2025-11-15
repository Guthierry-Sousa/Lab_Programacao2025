#include <stdio.h>

int main(){

    int temp_celsius;
    float temp_f;

    puts("Entre com a temperatura em graus celsius: ");
    scanf("%d", &temp_celsius);

    temp_f =  ((float)(9 * temp_celsius )+ 160)/5  ;

    printf("Temperatura em graus Fahrenheit: %.1f\n", temp_f);

    return 0;
}
