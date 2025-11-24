// Esse programa lê um arquivo de acesso aleatório sequencialmente, atualiza dados já gravados no arquivo, cria novos dados para o arquivo e exclui dados que previamente existiam no arquivo.

#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int numConta;
    char nome[15];
    char sobrenome[15];
    double saldo;

} clientData;

void criarArquivo(const clientData*);
void cadastrarClientes(clientData*);
void lerArquivo(clientData*);
void atualizarDados(clientData *);
void excluirDados(clientData *);

int main(){

    clientData client = {0, "", "", 0.0};
    int op;

    // Criar arquivo
    criarArquivo(&client);

    printf("\n === Escolha uma opção === \n");
    printf("\n\n1 - Cadastrar Clientes\n");
    printf("2 - Exibir Clientes\n");
    printf("3 - Atualizar Dados\n");
    printf("4 - Excluir Dados\n");
    printf("0 - Sair\n\n");

    scanf("%d", &op);

    while(op != 0){
        switch (op)
        {
        case 1:
            cadastrarClientes(&client);
            break;

        case 2:
            lerArquivo(&client);
            break;

        case 3:
            atualizarDados(&client);
            break;

        case 4:
            excluirDados(&client);
            break;
        
        default:

            printf("\nOpção Inválida\n");

            break;
        }
    printf("\n\n1 - Cadastrar Clientes\n");
    printf("2 - Exibir Clientes\n");
    printf("3 - Atualizar Dados\n");
    printf("4 - Excluir Dados\n");
    printf("0 - Sair\n\n");
    printf("\nInforme uma opção:\n");
    scanf("%d", &op);
    }

    return 0;
}
void criarArquivo(const clientData *client){

    FILE *arq = NULL;

    if(!(arq = fopen("clientsCredit.dat", "wb"))){
        perror("Não foi possível criar arquivo!");
        exit(1);
    }

    for(int i = 0; i<100; i++){

        fwrite(client, sizeof(clientData), 1, arq);

    }

    fclose(arq);

}

void cadastrarClientes(clientData *client){

    FILE *arq = NULL;
    clientData client_aux;

    if(!(arq = fopen("clientsCredit.dat", "rb+"))){
        perror("Não foi possível abrir o arquivo!");
        exit(2);
    }

    printf("\nInforme o número da conta (1 a 100, 0 para encerrar cadastro): \n");
    scanf("%d", &client->numConta);

    while(client->numConta != 0){

        /* Verifica se já existe */
        rewind(arq);

        int existe = 0;

        while(fread(&client_aux, sizeof(clientData), 1, arq) == 1){
            if(client->numConta == client_aux.numConta){
                existe = 1;
                break;
            }
        }

        if(existe){
            printf("\nUsuário já cadastrado com este número!\n");
        }
        else{

            printf("Informe nome, sobrenome e saldo: ");
            fscanf(stdin, "%s %s %lf",
                   client->nome,
                   client->sobrenome,
                   &client->saldo);

            fseek(arq, (client->numConta - 1) * sizeof(clientData), SEEK_SET);
            fwrite(client, sizeof(clientData), 1, arq);
        }

        printf("\nInforme o número da conta (1 a 100, 0 para encerrar cadastro): \n");
        scanf("%d", &client->numConta);
    }

    printf("\n\nCadastro Finalizado!\n\n");

    fclose(arq);
}

void lerArquivo(clientData* client){

    int cont = 0;

    FILE *arq = NULL;

    if(!(arq = fopen("clientsCredit.dat", "rb"))){
        perror("Não foi possível abrir o arquivo!");
        exit(3);
    }

    printf("%-10s%-15s%-15s%-10s\n", "Conta", "Nome", "Sobrenome", "Saldo");

    while(!feof(arq)){

        fread(client, sizeof(clientData), 1, arq);

        if(client->numConta != 0){
            printf("%-10d%-15s%-15s%-10.2lf\n", client->numConta, client->nome, client->sobrenome, client->saldo);
            cont++;
        }

    }

    if(cont == 0){
        printf("\n\nNUNHUMA CONTA CADASTRADA NO MOMENTO\n\n");
    }

    fclose(arq);

}

void atualizarDados(clientData *client){

    FILE *arq = NULL;

    if(!(arq = fopen("clientsCredit.dat", "rb+"))){
        perror("Não foi possível abrir o arquivo!");
        exit(3);
    }

    printf("\n\n === Atualizar dados === \n\n");
    printf("\nInforme o número da conta do cliente (0 para encerrar atualização): \n");
    scanf("%d", &client->numConta);

    while(client->numConta != 0){

        printf("Informe nome, sobrenome e saldo: ");
        fscanf(stdin, "%s%s%lf", client->nome, client->sobrenome, &client->saldo);

        fseek(arq, (client->numConta - 1) * sizeof(clientData), SEEK_SET);

        fwrite(client, sizeof(clientData), 1 , arq);

        printf("Atualização realizada.");

        printf("\nInforme o número da conta do cliente (0 para encerrar atualização): \n");
        scanf("%d", &client->numConta);   

    }

    printf("\n\nAtualização Finalizada!\n\n");
    fclose(arq);

}

void excluirDados(clientData *client){
    FILE *arq = NULL;

    if(!(arq = fopen("clientsCredit.dat", "rb+"))){
        perror("Não foi possível abrir o arquivo!");
        exit(4);
    }

    printf("\n\n === Excluir dados === \n\n");
    printf("\nInforme o número da conta do cliente (0 para encerrar exclusão): \n");
    scanf("%d", &client->numConta);

    while(client->numConta != 0){

        fseek(arq, (client->numConta - 1) * sizeof(clientData), SEEK_SET);

        *client = (clientData){0, "", "", 0.0};

        fwrite(client, sizeof(clientData), 1 , arq);

        printf("Exclusão realizada.");

        printf("\nInforme o número da conta do cliente (0 para encerrar exclusão): \n");
        scanf("%d", &client->numConta);   

    }

    printf("\n\nExclusão Finalizada!\n\n");

    fclose(arq);

}