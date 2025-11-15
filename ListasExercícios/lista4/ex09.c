// Bubble sort em C (com ponteiros)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* alocarVetor(int tam);
void gerarVetor(int *vet, int tam);
void ordenarVetor(int *vet, int tam);
void exibirVetor(int *vet, int tam);

#define RG 100

int main(int argc, char **argv){

    srand(time(NULL));

    if(argc != 2){
        printf("Use: %s <tamanhoVetor>\n", *argv);
        exit(1);
    }

    int tam_vetor = atoi(*(argv+1));
    int *vetor = alocarVetor(tam_vetor);

    gerarVetor(vetor, tam_vetor);
    exibirVetor(vetor, tam_vetor);
    ordenarVetor(vetor, tam_vetor);
    exibirVetor(vetor, tam_vetor);

    free(vetor);

    return 0;
}

int* alocarVetor(int tam){

    int *vet = NULL;

    if(!(vet  = malloc(sizeof(int) * tam))){
        puts("Memória Indisponível.");
        exit(2);
    }

    return vet;
}
void gerarVetor(int *vet, int tam){

    for(int i = 0; i<tam; i++){

        *(vet + i) = rand() % RG;
    }

}

void ordenarVetor(int *vet, int tam){

    int aux, flag;

    for(int i = 0; i<tam-1; i++){

        flag = 1;

        for(int j = 0; j<tam-1-i; j++){
            if(*(vet+j) > *(vet+j+1)){

                aux = *(vet+j);
                *(vet+j) = *(vet+j+1);
                *(vet+j+1) = aux;

                flag = 0;
            }
        }

        if(flag) break;
    }
}

void exibirVetor(int *vet, int tam){

    printf("\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%3d ", *(vet+i));
    }
    printf("\n\n");
}