#include <stdio.h>

int main(){

    int celsius = 10;

    float fahrenheit;

    for(celsius; celsius<=100; celsius+=10){

        fahrenheit = (celsius * 1.8) + 32;

        printf("%d graus celsius   =\t", celsius);
        printf("%.2f graus fahrenheit\n", fahrenheit);
    }

    return 0;
}