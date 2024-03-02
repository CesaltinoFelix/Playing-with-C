#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int i;
    int *values;
    values = (int *)malloc(sizeof(**range) * (max - min));
    i = 0;
    while (min + 1 < max)
        values[i++] = min++ + 1;

    *range = values;
    return (i);

}

#include <stdio.h>

int main() {
    int *arr;
    int size = ft_ultimate_range(&arr, 3, 8);

    if (size > 0) {
        printf("Array: %d\n", size);
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        free(arr);  // Libera a memória alocada
    } else {
        printf("Intervalo inválido.\n");
    }

    return 0;
}
