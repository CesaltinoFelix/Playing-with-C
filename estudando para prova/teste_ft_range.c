#include <stdlib.h>
#include<stdio.h>
#include<unistd.h>

int		*ft_range(int min, int max)
{
    int i;
    int *values;
    if (min >= max)
        return (0);
    int tamanho = max - min;
    i = 0;
    values = (int *)malloc(tamanho * sizeof(int) + 1);
    while (min + (++i) < max)
        values[i - 1] = min + i;
    values[min + i] = '\0';
    return (values);
}

int main()
{
    int i = -1;
    int *values = ft_range(19, 31);
    while (values[++i] != '\0'){
        printf("%d\n",values[i]);

    }
    
}