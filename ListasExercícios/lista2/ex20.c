#include <stdio.h>

int main(){

    long int fat = 1;

    for(int i = 1; i<=10; i++){

        for(int j = 1; j<=i; j++){

            if(i%2!=0){

                fat*=j;

            }
        }

        if(i%2!=0)
            printf("%ld! = %ld\n", i, fat);

        fat = 1; 

    } 

    return 0;
}