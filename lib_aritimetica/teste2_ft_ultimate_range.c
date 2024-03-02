#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int ft_ultimate_range(int **range, int min, int max)
{
    int i = 0;
    int *array;
    array = (int *)malloc(sizeof(**range) * (max - min));

    while (min + 1 < max)
    {
        array[i] = min + 1;
        min++;
        i++;
    }
    *range = array;

    return (i);
}


int main()
{
    int *arr;
    ft_ultimate_range(&arr, 1, 9);

    int i = -1;
    while (arr[++i])
        printf("%d", arr[i]);
    
}