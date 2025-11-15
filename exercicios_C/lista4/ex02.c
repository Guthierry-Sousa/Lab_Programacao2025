#include <stdio.h>
#include <stdlib.h>

void swapNormal(int *number1, int *number2);
void swapXor(int *number1, int *number2);

int main(){

    int a;
    int b;

    puts("Informe um valor (1): ");
    scanf("%d", &a);
    puts("Informe um valor (2): ");
    scanf("%d", &b);

    printf("\nInício - a = %d | b = %d\n", a, b);

    swapXor(&a, &b);

    printf("\nFinal - a = %d | b = %d\n", a, b);
    
    return 0;
}

void swap(int *number1, int *number2){

    int aux = *number1;
    *number1 = *number2;
    *number2 = aux;

}

void swapXor(int *number1, int *number2){

    *number1 = *number1 ^ *number2;
    *number2 = *number1 ^ *number2;
    *number1 = *number1 ^ *number2;

}