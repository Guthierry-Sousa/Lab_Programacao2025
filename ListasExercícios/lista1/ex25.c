#include <stdio.h>
#include <math.h>

int main(){
    double x1,y1;

    double x2,y2;

    double distancia;

    puts("Digite as coordenadas (x,y) do ponto 1:");
    scanf("%lf%lf", &x1, &y1);

    puts("Digite as coordenadas (x,y) do ponto 2:");
    scanf("%lf%lf", &x2, &y2);

    distancia = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

    printf("Distância = %.2f cm", distancia);

    return 0;
}