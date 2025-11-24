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

    printf("%-10s%-16s%-11s%10s\n", "Conta", "Nome", "Sobrenome", "Saldo");

    while(!feof(arq)){

        fread(&client, sizeof(clientData), 1, arq);
        
        if(client.numConta != 0){
            printf("%-10d%-16s%-11s%10.2f\n", client.numConta, client.nome, client.sobrenome, client.saldo);
        }

    }

    fclose(arq);

    return 0;
}