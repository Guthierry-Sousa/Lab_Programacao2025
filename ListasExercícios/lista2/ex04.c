#include <stdio.h>

int main(){

    int alt_jose = 150; //2 cm por ano

    int alt_pedro = 110; //3 cm por ano

    int qtd_anos = 0;

    for(alt_jose, alt_pedro; alt_pedro<=alt_jose; alt_jose+=2, alt_pedro+=3){

        qtd_anos++;

    }

    printf("Pedro será maior que José em %d anos\n", qtd_anos);

    return 0;
}