// Álgebra Linear: Soma, subtração e produto escalar de vetores 3D

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct{

    int x;
    int y;
    int z;

}Vetor;

void somarVetores(Vetor ,Vetor);
void subtrairVetores(Vetor ,Vetor);
int calcularProdutoEscalar(Vetor, Vetor);
double calcularModulo(Vetor);
void calcularAnguloEntreVetores(Vetor, Vetor);

int main(){

    Vetor vetor1 = {1,0,0};
    Vetor vetor2 = {0,0,1};

    somarVetores(vetor1,vetor2);
    subtrairVetores(vetor1,vetor2);

    int prod_interno = calcularProdutoEscalar(vetor1,vetor2);
    printf("\n<(%d, %d, %d) , (%d, %d, %d)> = %d\n", vetor1.x, vetor1.y, vetor1.z, vetor2.x, vetor2.y, vetor2.z, prod_interno);

    double modulo1 = calcularModulo(vetor1);
    printf("\n||(%d, %d, %d)|| = %.2lf\n", vetor1.x, vetor1.y, vetor1.x, modulo1);

    double modulo2 = calcularModulo(vetor2);
    printf("\n||(%d, %d, %d)|| = %.2lf\n", vetor2.x, vetor2.y, vetor2.x, modulo2);

    calcularAnguloEntreVetores(vetor1, vetor2);

    return 0;
}

void somarVetores(Vetor vet1 ,Vetor vet2){

    int x_i = vet1.x + vet2.x;
    int y_i = vet1.y + vet2.y;
    int z_i = vet1.z + vet2.z;

    printf("\n(%d, %d, %d) + (%d, %d, %d) = (%d, %d, %d)\n", vet1.x, vet1.y, vet1.z, vet2.x, vet2.y, vet2.z, x_i, y_i, z_i);

}

void subtrairVetores(Vetor vet1 ,Vetor vet2){

    int x_i = vet1.x - vet2.x;
    int y_i = vet1.y - vet2.y;
    int z_i = vet1.z - vet2.z;

    printf("\n(%d, %d, %d) - (%d, %d, %d) = (%d, %d, %d)\n", vet1.x, vet1.y, vet1.z, vet2.x, vet2.y, vet2.z, x_i, y_i, z_i);
}

int calcularProdutoEscalar(Vetor vet1, Vetor vet2){

    int prod_escalar = (vet1.x * vet2.x ) + (vet1.y * vet2.y) + (vet1.z * vet2.z);

    return prod_escalar;

}

double calcularModulo(Vetor vet1){

    double modulo = sqrt(calcularProdutoEscalar(vet1, vet1));

    return modulo;

}

void calcularAnguloEntreVetores(Vetor vet1, Vetor vet2){

    int prod_int = calcularProdutoEscalar(vet1, vet2);

    double mod1 = calcularModulo(vet1);
    double mod2 = calcularModulo(vet2);

    double angulo_rad = acos(prod_int/(mod1*mod2));

    double angulo_graus = (angulo_rad * 180)/PI;

    printf("\nÂngulo entre (%d, %d, %d) e (%d, %d, %d) = %.2lf graus.\n", vet1.x, vet1.y, vet1.z, vet2.x, vet2.y, vet2.z, angulo_graus);
}