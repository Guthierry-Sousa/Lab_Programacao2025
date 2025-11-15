#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMNS 4
#define ROWNS 4

#define RG 100

int main(){

    int matrix[ROWNS][COLUMNS];
    srand(time(NULL));

    for(int i = 0; i<ROWNS; i++){
        for(int j = 0; j<COLUMNS; j++){

            matrix[i][j] = rand() % RG; //[0,99]
        }
    }

    int num, cont = 0;

    puts("Informe um número entre no intervalo [0,99]: ");
    scanf("%d", &num);

    for(int i = 0; i<ROWNS; i++){

        for(int j = 0; j<COLUMNS; j++){

            if(num == matrix[i][j]){
                cont ++;
            }  
        }
    }

    for(int i = 0; i<ROWNS; i++){
        for(int j = 0; j<COLUMNS; j++){

            printf("%d ,", matrix[i][j]);
        }
        printf("\n");

    }
    
    printf("Número (%d) - aparece %d vezes na matriz!\n", num, cont);

    return 0;
}