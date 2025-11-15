#include <stdio.h>

int main(){

    int num;

    puts("Entre com um número: ");
    scanf("%d", &num);

    printf("Sucessor = %d | Antecessor = %d\n", num + 1, num - 1);

    return 0;
}