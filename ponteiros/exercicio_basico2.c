// 2. Troca de valores usando ponteiros:
//    - Crie uma função que receba dois ponteiros para `int` e troque os valores apontados.

#include <stdio.h>

void troca(int *pA, int *pB )
{
    int aux = *pA;
    *pA = *pB;
    *pB = aux;
}

int main(void)
{
    int a;
    int b;

    a = 2;
    b = 3;

    printf("a = %d\nb = %d\n\n", a, b);

    troca(&a, &b);
    
    printf("a = %d\nb = %d", a, b);

    return 0;
}
