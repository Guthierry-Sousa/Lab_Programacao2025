#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int numConta;
    char sobrenome[15];
    char nome[10];
    double saldo;

}clientData;

int main(){

    clientData client = {0, "", "", 0.0};

    FILE *arq = NULL;

    if(!(arq = fopen("credit.dat", "rb+"))){

        perror("Erro ao abrir arquivo.");
        exit(1);

    }

    printf("Informe número da conta (1 a 100, 0 para encerrar): ");
    scanf("%d", &client.numConta);

    while(client.numConta != 0){

        printf("Informe nome, sobrenome e saldo:\n");
        fscanf(stdin, "%s%s%lf", client.nome, client.sobrenome, &client.saldo);

        fseek(arq, (client.numConta - 1) * sizeof(clientData), SEEK_SET);

        fwrite(&client, sizeof(clientData), 1, arq);

        printf("Informe número da conta (1 a 100, 0 para encerrar): ");
        scanf("%d", &client.numConta);

    }

    fclose(arq);

    return 0;
}