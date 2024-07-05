// 3. Modificar o valor de uma variável através de um ponteiro:
//    - Declare uma variável `int` e um ponteiro para `int`.
//    - Modifique o valor da variável usando o ponteiro.

#include <stdio.h>

int main(void)
{
    int x;
    int *pX = &x;
    
    x = 1;
    printf("x = %d\n", x);
    *pX = 2;
    printf("x = %d\n", x);
    return (0);
}