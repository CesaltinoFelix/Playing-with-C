// 9. Incremento de ponteiros:
//    - Declare um array de `int` e use um ponteiro para incrementar e imprimir os valores dos elementos do array.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 0;
    int valores[5] = {1, 3, 4, 5, 7};
    int *pValores = valores;

    int tamanho = sizeof(valores) / sizeof(valores[0]);

    while (i < tamanho)
    {
        pValores[i]++;
        i++;
    }

    i = 0;

    while (i < tamanho)
    {
        printf("[%d] - %d\n", i, pValores[i]);
        i++;
    }
    
       
}