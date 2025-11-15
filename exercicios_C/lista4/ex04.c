#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* alocarVetor(int tam);
void preencherVetor(int *vet, int tam);
void exibirVetor(int *vet, int tam);

// Argc - quantidade elementos.
// Argv - vetor de vetores(strings).

#define RG 50

int main(int argc, char **argv){
    srand(time(NULL));

    if(argc != 2){
        printf("Use: %s <tamanhoVetor>\n", *argv);
        exit(1);
    }

    int tam_vetor = atoi(*(argv+1));
    int *vetor = alocarVetor(tam_vetor);

    preencherVetor(vetor, tam_vetor);
    exibirVetor(vetor, tam_vetor);

    free(vetor);

    return 0;
}

int* alocarVetor(int tam){

    int *vet = NULL;

    if(!(vet = malloc(sizeof(int) * tam))){
        puts("Memória Indisponível.");
        exit(2);
    }
    
    return vet;

}
void preencherVetor(int *vet, int tam){

    for (int i = 0; i < tam; i++)
    {
        *(vet+i) = rand() % RG;
    }
    
}
void exibirVetor(int *vet, int tam){
    for (int i = 0; i < tam; i++)
    {
        printf("\nvetor[%d] = %d || Endereço: %p\n", i, *(vet+i), vet+i);
    }
}


