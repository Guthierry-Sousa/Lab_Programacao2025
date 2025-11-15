#include <stdio.h>
#include <math.h>

int main(){

    double x;

    double result;

    for(x = 0; x<=7; x++){

        result = pow(3.0,x);

        printf("3^%.2lf = %.2lf\n", x, result);

    }

    return 0;
}