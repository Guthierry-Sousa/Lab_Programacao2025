#include <stdio.h>

int main(){

    int horas, minutos , segundos;

    puts("Informe as horas: ");
    scanf("%d", &horas);

    puts("Informe os minutos: ");
    scanf("%d", &minutos);

    puts("Informe os segundos: ");
    scanf("%d", &segundos);

    segundos += (horas * 3600) + (minutos * 60);

    printf("Total do tempo em segundos: %d s\n", segundos);

    return 0;
}