#include <stdio.h>

//Fórmula de Leibniz para pi;

int main(){

    float pi = 0;

    int termo;

    puts("Informe em quantos termos vc quer a aproximação: ");
    scanf("%d", &termo);

    for(int i = 0; i<termo; i++){

        if(i%2==0){

            pi += (float) 4/((2*i)+1);

        }

        else{
            pi += (float) -4/((2*i)+1);
        }

    }

    printf("Valor aproximado de pi para %d termo(s) = %.2f\n", termo, pi);

    return 0;
}