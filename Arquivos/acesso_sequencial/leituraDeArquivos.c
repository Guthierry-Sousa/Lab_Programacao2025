// Leitura de dados de um arquivo sequencial

#include <stdio.h>

int main(){

    int account;
    char name[30];
    double balance;

    FILE *cfPtr;

    if((cfPtr = fopen("clients.dat", "r")) == NULL){
        printf("Arquivo não pode ser aberto.\n");
    }
    else{
        printf("%-10s%-13s%s\n", "Account", "Name", "Balance");
        fscanf(cfPtr, "%d%s%lf", &account, name, &balance);

        //Cuidado com a função feof - só retorna verdadeiro depois de uma tentativa de leitura falhar por causa do fim do arquivo.

        while(!feof(cfPtr)){
            printf("%-10d%-13s%7.2f\n", account, name, balance);
            fscanf(cfPtr, "%d%s%lf", &account, name, &balance);
        }

        fclose(cfPtr);
    }

    return 0;
}