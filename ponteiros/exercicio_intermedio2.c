// 5. Função que retorna um ponteiro:
//    - Crie uma função que receba um array de `int` e seu tamanho, e retorne um ponteiro para o maior elemento.

#include <stdio.h>

int *maior_valor(int *pArray, int tamanho)
{
    int i;
    int y;
    int *maior = NULL;

    i = 0;
    maior = &pArray[0];
    while(i < tamanho)
    {
        y = 0;
        while(y < tamanho)
        {
            if(*maior < pArray[y])
                maior = &pArray[y];
            y++;
        }
        i++;
    }
    return (maior);
}

int main(void)
{
    int array[] = {1, 10, 2, 31, 7, 5, 9};
    int tamanho;
    int *maior = NULL;

    tamanho = sizeof(array) / sizeof(array[0]);
    maior = maior_valor(array, tamanho);
    printf("&array = %d\nMaior valor = %d\n&MAior_valor = %d", array,  *maior, maior);
    return (0);
}