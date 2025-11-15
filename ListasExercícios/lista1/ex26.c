#include <stdio.h>
#include <math.h>

int main(){

    float num_1, num_2, num_3;

    float media_aritmetica, media_geo; 

    puts("Informe 3 números:");
    scanf("%f%f%f",&num_1, &num_2, &num_3);

    media_aritmetica = (num_1+num_2+num_3)/3;

    media_geo = pow((num_1 * num_2 * num_3), ((float)1/3));

    printf("Média aritmética = %.2f\n", media_aritmetica);

    printf("Média Geométrica = %.4f\n", media_geo);

    return 0;
}