// Programa de consulta de cŕedito

#include <stdio.h>

int main(){

    int cont = 0;
    int option;
    int account; // Número da conta
    char name[30]; // Nome do usuário
    double balance; // Saldo (negativo, positivo ou 0)

    FILE *cfPtr;

    if((cfPtr = fopen("clients.dat", "r")) == NULL){

        printf("Arquivo não pode ser lido.");

    }

    else{

        printf("1 - Visualizar Credores\n");
        printf("2 - Visualizar Devores\n");
        printf("3 - Visualizar clientes com saldo zero\n");
        printf("4 - Finalizar Execução\n");

        scanf("%d", &option);

        while(option != 4){

            fscanf(cfPtr, "%d%s%lf", &account, name, &balance);

            switch (option)
            {
                case 1:
                    printf("\n\nClientes Credores\n");
                    printf("\n%-10s%-13s%s\n", "Account", "Name", "Balance");

                    while (!feof(cfPtr))
                    {
                        if(balance > 0){

                            printf("%-10d%-13s%7.2f\n", account, name, balance);
                            cont++;
                            
                        }

                        fscanf(cfPtr, "%d%s%lf", &account, name, &balance);
                    }

                    if(cont == 0){
                        printf("\nNão existem clientes com saldo credor.\n");
                    }
                    
                    break;

                case 2:

                    printf("\n\nClientes Devedores\n");
                    printf("%-10s%-13s%s\n", "Account", "Name", "Balance");

                    while (!feof(cfPtr))
                    {
                        if(balance < 0){

                            printf("%-10d%-13s%7.2f\n", account, name, balance);
                            cont++;
                                
                        }

                        fscanf(cfPtr, "%d%s%lf", &account, name, &balance);
                    }

                    if(cont == 0){
                        printf("\nNão existem clientes com saldo devedor.\n");
                    }
                        
                    break;

                case 3:

                    printf("\n\nClientes com saldo zero\n");
                    printf("%-10s%-13s%s\n", "Account", "Name", "Balance");

                    while (!feof(cfPtr))
                    {
                        if(balance == 0){

                            printf("%-10d%-13s%7.2f\n", account, name, balance);
                            cont++;
                                
                        }

                        fscanf(cfPtr, "%d%s%lf", &account, name, &balance);
                    }

                    if(cont == 0){
                        printf("\nNão existem clientes com saldo zero.\n");
                    }
                        
                    break;
                
                default:

                    printf("\nOpção Inválida - Tente Novamente!\n");

                    break;

            }
            cont = 0;

            rewind(cfPtr);

            printf("\nInforme uma nova opção: ");
            scanf("%d", &option);

        }

    }

    printf("\nPrograma Finalizado!\n");

    return 0;
}