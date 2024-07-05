// 4. Manipulação de array usando ponteiros:
//    - Declare um array de `int` e use ponteiros para percorrer e imprimir todos os elementos do array.


#include <stdio.h>

int main(void)
{
    int array[] = {1, 2, 3, 4, 5, 6};
    int *pArray = NULL;
    int tamanhoArray;
    int counter;
    
    tamanhoArray = sizeof(array) / sizeof(array[0]);
    pArray = array;
    counter = 0;

    while(counter < tamanhoArray)
        printf("[%d] - %d\n", counter++, *(pArray++));
    return (0);
}