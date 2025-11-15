#include <stdio.h>

int main(){

    int dia;

    puts("Informe o número de um dia da semana(1-7)");
    scanf("%d", &dia);

    while(dia!=0){
        switch(dia){
            case 1:
                printf("\n%d - corresponde à Segunda.\n", dia);
                break;
            
            case 2:
                printf("\n%d - corresponde à Terça.\n", dia);
                break;

            case 3:
                printf("\n%d - corresponde à Quarta.\n", dia);
                break;

            case 4:
                printf("\n%d - corresponde à Quinta.\n", dia);
                break;

            case 5:
                printf("\n%d - corresponde à Sexta.\n", dia);
                break;

            case 6:
                printf("\n%d - corresponde à Sábado.\n", dia);
                break;

            case 7:
                printf("\n%d - corresponde à Domingo.\n", dia);
                break;

            default:
                printf("\n%d não corresponde a nenhum dia!!\n", dia);
                break;
        }
        puts("Informe o número de um dia da semana(1-7):");
        scanf("%d", &dia);
    }

    puts("Programa finalizado");

    return 0;
}