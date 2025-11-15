#include <stdio.h>

int main(){

    int segund = 0, minutos = 0, horas = 0;

    // Entrada de Dados
    puts("Informe uma quantidade de tempos em segundos:");
    scanf("%d", &segund);

    // Processamento
    if(segund >= 60){

        minutos = segund/60;

        segund -= (60*minutos);

    }

    if(minutos >= 60){

        horas = minutos/60;

        minutos -= (60*horas);
    }

    //Saída de dados
    printf("%d hora(s), %d minuto(s) e %d segundo(s)\n", horas, minutos, segund);

    return 0;
}