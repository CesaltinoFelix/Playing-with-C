// 6. Passagem de array para função:
//    - Crie uma função que receba um ponteiro para um array de `int` e o tamanho do array, e imprima os elementos do array.


#include <stdio.h>

void imprimir(int *pArray, int tamanho)
{
    int i;

    i = -1;
    pArray--;
    while(++i < tamanho)
        printf("[%i] - %d/n", i, (*(++pArray)));
}

int main(void)
{
    int array[] = {1, 2, 3, 5, 8, 9};
    int tamanho;

    tamanho = sizeof(array) / sizeof(*array);
    imprimir(array, tamanho);

    return (0);
}