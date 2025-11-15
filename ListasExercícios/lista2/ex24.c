#include <stdio.h>
#include <math.h>

int main(){

    int hipotenusa, cat1, cat2;

    double hipotenusa_calculada;

    int cont = 0;
    

    for(cat1 = 1; cat1<=500; cat1++){

        for(cat2 = cat1+1; cat2<=500; cat2++){

            hipotenusa_calculada = sqrt(cat1*cat1 + cat2*cat2);
            hipotenusa = (int)hipotenusa_calculada;

            /* Condições:

            hipotenusa inteira;
            hipotenusa<=500;
            cat1<cat2 (elimina triplas repetidas).

            */

            if(hipotenusa == hipotenusa_calculada && hipotenusa<=500 && cat1<cat2){

                printf("Tripla = (%d, %d, %d) \n", cat1, cat2, hipotenusa);

                cont++;

            }

        }
    }

    printf("Quantidade de Triplas: %d\n", cont);

    return 0;
}
