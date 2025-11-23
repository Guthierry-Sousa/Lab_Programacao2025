// Geometria Computacional: Distância entre pontos e centróide

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 50
#define RG 10

struct Pontos
{
    double x[N];
    double y[N];

};

struct Centroide{

    double x_c;
    double y_c;
};

void calcularDistancia(struct Pontos *,int, int);
void calcularCentroide(double *, double *, int, struct Centroide *);
void preencherVetorPontos(double *, int);
void exibirPontos(double *, double *, int);

int main(){

    srand(time(NULL));

    struct Pontos pontos;
    preencherVetorPontos(pontos.x, N);
    preencherVetorPontos(pontos.y, N);

    exibirPontos(pontos.x, pontos.y, N);

    int indice1, indice2;

    printf("Informe o índice do 1 - Ponto: \n");
    scanf("%d", &indice1);

    printf("Informe o índice do 2 - Ponto: \n");
    scanf("%d", &indice2);

    if (indice1 < 0 || indice1 >= N || indice2 < 0 || indice2 >= N) {

        printf("Índice inválido!\n");
        return 1;

    }

    calcularDistancia(&pontos,indice1, indice2);

    struct Centroide centroide;
    calcularCentroide(pontos.x, pontos.y, N, &centroide);

    printf("\n\nCentroide = (%.2lf , %.2lf)\n\n", centroide.x_c, centroide.y_c);

    return 0;
}

void calcularDistancia(struct Pontos *p, int i, int j) {

    double dx = p->x[j] - p->x[i];
    double dy = p->y[j] - p->y[i];
    double distancia = sqrt(dx*dx + dy*dy);

    printf("\nDistância entre (%.2lf , %.2lf) e (%.2lf , %.2lf) = %.2lf\n",
           p->x[i], p->y[i], p->x[j], p->y[j], distancia);
}

void calcularCentroide(double *vetx, double *vety, int tam, struct Centroide *centroide){

    double x = 0, y = 0;

    for(int i = 0; i<tam; i++){

        x += *(vetx+i);
        y += *(vety+i);

    }

    centroide->x_c = x/tam;
    centroide->y_c = y/tam;

}

void preencherVetorPontos(double *vet, int tam){

    for(int i = 0; i<tam; i++){

        *(vet+i) = ((double)rand() / RAND_MAX) * RG;

    }
}

void exibirPontos(double *vetx, double *vety, int tam){

    for(int i = 0; i<tam; i++){

        printf("Ponto %d : (%.2lf , %.2lf)\n", i, *(vetx + i), *(vety + i));

    }

    printf("\n\n");
}