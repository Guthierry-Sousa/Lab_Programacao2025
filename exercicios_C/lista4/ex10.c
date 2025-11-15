#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* alocarVetor(int tam);
void preencherVetor(int *vet, int tam, int RG);
void exibirVetor(int *vet, int tam);
void frequenciaElementos(int *vet, int *vet_freq, int tam);

int main(int argc, char **argv){

    srand(time(NULL));

    if(argc != 3){

        printf("Use: %s <tamVetor> <numeroMax>\n", *argv);
        exit(1);

    }

    int tam_vetor = atoi(*(argv+1));
    int rg_max = atoi(*(argv+2));

    int *vetor = alocarVetor(tam_vetor);
    preencherVetor(vetor, tam_vetor, rg_max);
    exibirVetor(vetor, tam_vetor);

    printf("\nVetor com a frequência dos elementos: \n");
    int *vetor_freq = alocarVetor(rg_max);
    frequenciaElementos(vetor, vetor_freq, tam_vetor);
    exibirVetor(vetor_freq, rg_max);

    return 0;
}

int* alocarVetor(int tam){

    int *vet = NULL;

    if(!(vet  = calloc(tam, sizeof(int) * tam))){
        puts("Memória Indisponível.");
        exit(2);
    }

    return vet;
}

void preencherVetor(int *vet, int tam, int RG){

    for(int i = 0; i<tam; i++){

        *(vet + i) = rand() % RG;

    }
}

void exibirVetor(int *vet, int tam){

    printf("\n");

    for(int i = 0; i<tam; i++){

        printf("%3d ", *(vet + i));

    }

    printf("\n\n");
}

void frequenciaElementos(int *vet, int *vet_freq, int tam){

    for(int i = 0; i<tam; i++){

        int a = *(vet+i);

        *(vet_freq + a) += 1;

    }

}