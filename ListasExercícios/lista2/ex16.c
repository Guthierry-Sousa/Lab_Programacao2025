#include <stdio.h>

int main(){

    int i = 0;

    int somatorio_3 = 0;

    int somatorio_5 = 0;

    for(i; i<=200 ; i++){

        if(i>=0 && i<=100){
            if(i%3==0){
                somatorio_3+=i;
            }
        }
        if(i>100 && i<=200){
            if(i%5==0){
                somatorio_5+=i;
            }
        }
    }

    printf("Somatório dos números no intervalo [0,100] divisíveis por 3: %d\n", somatorio_3);
    printf("Somatório dos números no intervalo ]100,200] divisíveis por 5: %d\n", somatorio_5);

    return 0;
}