#include <stdio.h>

int main(){

    float valor_hora, percent_desconto, salario_b, salario_l;

    int hrs_trabalhadas;

    // Entrada de dados

    puts("Informe o valor da hora: ");
    scanf("%f", &valor_hora);

    puts("Informe a quantidade de horas trabalhadas: ");
    scanf("%d", &hrs_trabalhadas);

    puts("Informe o percentual de desconto do INSS: ");
    scanf("%f", &percent_desconto);

    //Processamento dos Cálculos

    salario_b = valor_hora * hrs_trabalhadas;

    salario_l = salario_b - (salario_b * (percent_desconto/100));

    // Saída de dados

    printf("Salário Bruto = R$%.2f\n", salario_b);

    printf("Percentual do INSS = %.2f%%\n", percent_desconto);
    
    printf("Salário Líquido = R$%.2f\n", salario_l);

    return 0;
}