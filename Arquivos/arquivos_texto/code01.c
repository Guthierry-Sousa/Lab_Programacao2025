#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

typedef struct 
{
    char nome[N];
    int idade;
    char sexo;

} Pessoa;

void cadastrarPessoa(Pessoa *, Pessoa *, int*, int, int const);
void exibirPessoas(Pessoa *, int const);
void salvarDados(Pessoa *, int const);
void lerArquivo(Pessoa *, int const);

int main(int argc, char **argv){

    int quant = 0;

    if(argc != 2){
        printf("Use: %s <tamanhoVetor>\n", *argv);
        exit(1);
    }

    int tam = atoi(*(argv+1));

    Pessoa *vetor = malloc(sizeof(Pessoa) * tam);

    if(vetor == NULL){

        printf("Memória Indisponível\n");
        exit(2);

    }

    int opition;

    do{

        printf("\n=============== Menu ===============\n");

        printf("\n\n1 - Cadastrar Pessoa\n");
        printf("2 - Exibir Pessoas\n");
        printf("3 - Salvar Arquivo\n");
        printf("4 - Ler Arquivo\n");
        printf("0 - Sair\n\n");

        scanf("%d", &opition);

        switch (opition)
        {
        
        case 1:

            Pessoa p;

            cadastrarPessoa(&p, vetor, &quant, N, tam);

            break;

        case 2:
            
            exibirPessoas(vetor, quant);

            break;
        
        case 3:

            salvarDados(vetor, quant);

            break;

        case 4:

            lerArquivo(vetor, quant);
            break;
        
        case 0:

            printf("\nPrograma Finalizado\n");

            break;

        default:

            printf("\nOpção Inválida\n");

            break;
        }


    }while (opition != 0 );

    free(vetor);

    return 0;
}

void cadastrarPessoa(Pessoa *personPtr, Pessoa *vet , int *quantidade, int n, int const tamanho){

    if(*quantidade < tamanho){

        getchar();

        printf("\nInforme o nome: \n");
        fgets(personPtr->nome,  n , stdin);

        personPtr->nome[strcspn(personPtr->nome, "\n")] = '\0';

        printf("\nInforme sua idade: \n");
        scanf("%d", &personPtr->idade);

        printf("\nInforme seu sexo (m ou f): \n");
        scanf(" %c", &personPtr->sexo);

        vet[*quantidade] = *personPtr;

        (*quantidade)++;

    }
    else{
        printf("\nVetor Totalmente Preenchido!\n");
    }
    
}

void exibirPessoas(Pessoa *vet, int const quantidade){

    if(quantidade>0){

        printf("\n--- Pessoas Cadastradas ---\n");
        printf("%-30s %-5s %-5s\n", "Nome", "Idade", "Sexo");

        for(int i = 0; i<quantidade; i++){

            printf("%-30s %-5d %-5c\n", vet[i].nome, vet[i].idade, vet[i].sexo);

        }

    }
    else{
        printf("\n\nNenhuma Pessoa foi cadastrada!\n\n");
    }
}

void salvarDados(Pessoa *vet, int const quantidade){

    FILE *arq = fopen("dados.txt", "w");

    if(!arq){
        printf("\nNão foi possível criar um arquivo!\n");
        exit(3);
    }

    if(quantidade > 0){

        fprintf(arq, "%-30s %-5s %-5s\n", "Nome", "Idade", "Sexo");

        for(int i = 0; i<quantidade; i++){

            fprintf(arq, "%-30s %-5d %-5c\n", vet[i].nome, vet[i].idade, vet[i].sexo);

        }

        printf("\nDados Salvos.\n");
    }

    else{
        printf("\nSem dados para serem salvos\n");
    }

    fclose(arq);

}

void lerArquivo(Pessoa *vet, int const quantidade){

    FILE *arq = fopen("dados.txt", "r");

    if(!arq){
        printf("\nNão foi possível criar um arquivo!\n");
        exit(3);
    }

    char linha[100];

    // Ignora a primeira linha (cabeçalho)
    fgets(linha, sizeof(linha), arq);

    printf("%-30s %-5s %-5s\n", "Nome", "Idade", "Sexo");

    for (int i = 0; i < quantidade; i++)
    {
        
        if(fgets(linha, sizeof(linha), arq)) {

            // Lê o nome completo, idade e sexo
            
            sscanf(linha, "%30[^\t] %d %c", vet[i].nome, &vet[i].idade, &vet[i].sexo);

            printf("%-30s %-5d %-5c\n", vet[i].nome, vet[i].idade, vet[i].sexo);
        }

    }
    
    fclose(arq);
    
}