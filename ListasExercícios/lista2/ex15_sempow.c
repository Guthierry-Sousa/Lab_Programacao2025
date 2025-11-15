#include <stdio.h>


int main(){

    int x;

    int base = 3;

    int result = 1;

    for(x = 0; x<=7; x++){
        if(x>0){
            result *= 3;
        }
        printf("3^%d = %d\n", x, result);

    }

    return 0;
}