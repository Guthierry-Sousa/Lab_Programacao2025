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

    if(!(arq = fopen("credit.dat", "w"))){

        perror("Erro ao abrir arquivo.");
        exit(1);

    }

    for(int i = 0; i<100; i++){

        fwrite(&client, sizeof(clientData), 1, arq);

    }
    fclose(arq);
    
    return 0;
}