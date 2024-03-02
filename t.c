#include <stdio.h>

int soma(int num1, int num2)
{
    return num1 + num2;
}

int mult(int num1, int num2)
{
    return num1 * num2;
}


int main()
{   
    int num1 = 4, num2 = 3;
    int result = soma(num1, num2);
    int result2 = mult(num1, num2);
    printf("Resultado = %d\n", result);
    printf("Resultado = %d", result2);
}