#include <stdio.h>

int main(){

    unsigned int num;

    unsigned int binario;

    unsigned int mask = 0x80000000;

    for(num = 1; num<=256; num++){


        printf("%u em octal = %o\n", num, num);
        printf("%u em hexadecimal = %X\n", num, num);
        printf("%u em binário = ", num);

        // Transformando em Binário;
        for(int i = 0; i<32; i++){

            if(num & mask){

                printf("1");

            }

            else{

                if(i>24)

                    printf("0");

            }

            mask >>= 1;
        }

        mask = 0x80000000;
        printf("\n\n");

    }

    return 0;

}