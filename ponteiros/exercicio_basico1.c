// 1. Imprimir valor e endereço de uma variável:
//    - Declare uma variável `int` e um ponteiro para `int`.
//    - Atribua o endereço da variável ao ponteiro.
//    - Use o ponteiro para imprimir o valor e o endereço da variável.

#include <stdio.h>


int main(void)
{
    int a = 20;
    int *pA = &a;
    
    printf("&a = %p\na = %d", pA, *pA);

    return 0;
}
