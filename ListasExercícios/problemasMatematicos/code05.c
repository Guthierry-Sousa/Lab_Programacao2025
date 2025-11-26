// Estatística e Computação: Média, variância e desvio padrão

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define RG 10
#define QTD_NOTAS 5

typedef struct{

    char nome[40];
    double notas[QTD_NOTAS];
    double media;
    double variancia;
    double desvioPadrao;

}Alunos;

void preencherNotas(Alunos *, int const);
void exibirDados(Alunos *, int const);
void calcularMedia(Alunos *, int const);
void calcularVariancia(Alunos *, int const);
void calcularDesvioPadrao(Alunos *, int const);
void maiorMedia(Alunos *, int const);
void maiorDesvioPadrao(Alunos *, int const);

int main(int argc, char **argv){

    if(argc != 2){
        printf("Use: %s <qtdAlunos>\n", *argv);
        exit(1);
    }

    int qtdAlunos = atoi(*(argv+1));
    if(qtdAlunos <= 0){
        printf("Quantidade Inválida de alunos\n");
        exit(2);
    }

    // Alocação de memória
    Alunos *alunos = NULL;

    alunos = malloc(sizeof(Alunos) * qtdAlunos);

    if(alunos == NULL){
        printf("\nNão foi possível alocar memória.\n");
        exit(3);
    }

    // Chamada das funções para calculo
    srand(time(NULL));
    preencherNotas(alunos, qtdAlunos);
    calcularMedia(alunos,qtdAlunos);
    calcularVariancia(alunos, qtdAlunos);
    calcularDesvioPadrao(alunos, qtdAlunos);

    // Exibição de Dados
    exibirDados(alunos, qtdAlunos);
    printf("\n\n");
    maiorMedia(alunos, qtdAlunos);
    maiorDesvioPadrao(alunos, qtdAlunos);
    // Liberação de memória
    free(alunos);

    printf("\n\nPrograma Finalizado.\n\n");

    return 0;
}

void preencherNotas(Alunos *a, int const qtd){

    for(int i = 0; i<qtd; i++){

        printf("\nInforme o nome do aluno %d: \n", i+1);
        fgets(a[i].nome, 40, stdin);

        a[i].nome[strcspn(a[i].nome, "\n")] = '\0';

        for(int j = 0; j < QTD_NOTAS; j++){

            a[i].notas[j] = RG * (rand() /(double) RAND_MAX);
        }

        printf("\nNotas aluno %d preenchidas.\n", i+1);

    }

    printf("\n\nPreenchimento de notas finalizado.\n\n");

}

void exibirDados(Alunos *a, int const qtd){

    for(int i = 0; i<qtd; i++){

        printf("\n\nAluno %d: \n", i+1);
        printf("Nome: %s", a[i].nome);

        for(int j = 0; j < QTD_NOTAS; j++){

            printf(" | Nota %d = %.2lf |", j+1, a[i].notas[j]);

        }
        printf("\nMédia = %.2lf | Variância = %.2lf | Desvio Padrão = %.2lf", a[i].media, a[i].variancia, a[i].desvioPadrao);

    }

    printf("\n\nExibição de notas finalizado.\n\n");

}

void calcularMedia(Alunos *a, int const qtd){

    for(int i = 0; i < qtd; i++){

        double somatorio = 0;

        for(int j = 0 ; j < QTD_NOTAS; j++){

            somatorio += a[i].notas[j];

        }

        a[i].media = somatorio/QTD_NOTAS;

    }

    printf("\n\nMédias calculadas.\n\n");

}

void calcularVariancia(Alunos *a, int const qtd){

    for(int i = 0; i < qtd; i++){

        double somatorio = 0;

        for(int j = 0 ; j < QTD_NOTAS; j++){

            somatorio += pow(a[i].notas[j] - a[i].media, 2.0);

        }

        a[i].variancia = somatorio/QTD_NOTAS;

    }

    printf("\n\nVariância Calculada.\n\n");

}

void calcularDesvioPadrao(Alunos *a, int const qtd){

    for(int i = 0; i < qtd; i++){

        a[i].desvioPadrao = sqrt(a[i].variancia);

    }

    printf("\n\nDesvio Padrão Calculado.\n\n");

}

void maiorMedia(Alunos *a, int const qtd){

    Alunos alunoMaiorMedia = a[0];

    for(int i = 1; i < qtd ; i++){

        if(a[i].media > alunoMaiorMedia.media){
            alunoMaiorMedia = a[i];
        }

    }

    printf("\n === Maior Média === \n");
    printf("\nAluno: %s | Média = %.2lf\n", alunoMaiorMedia.nome, alunoMaiorMedia.media);

}
void maiorDesvioPadrao(Alunos *a, int const qtd){

    Alunos alunoMaiorDP = a[0];

    for(int i = 1; i < qtd; i++){

        if(a[i].desvioPadrao > alunoMaiorDP.desvioPadrao){
            alunoMaiorDP = a[i];
        }

    }

    printf("\n === Maior Desvio Padrão === \n");
    printf("\nAluno: %s | Desvio Padrão = %.2lf\n", alunoMaiorDP.nome, alunoMaiorDP.desvioPadrao);

}