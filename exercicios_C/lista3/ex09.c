#include <stdio.h>

#define COLUMNS 3
#define ROWNS 3

int main(){

    int matrix[ROWNS][COLUMNS];

    for(int i = 0; i<ROWNS; i++){
        for(int j = 0; j<COLUMNS; j++){

            printf("Informe o elemento(%dx%d) da matriz: \n", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i = 0; i<ROWNS; i++){
        for(int j = 0; j<COLUMNS; j++){

            printf("%d ,", matrix[i][j]);
  
        }
        printf("\n");

    }

    // Elementos da diagonal principal: Aij, i=j

    printf("\nElementos da diagonal principal: \n");

    for(int i = 0; i<ROWNS; i++){
        for(int j = 0; j<COLUMNS; j++){

            if(i==j) printf("matrix[%d][%d] = %d\n", i,j, matrix[i][j]);
  
        }
        

    }


    return 0;
}