#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int *ft_range(int min, int max)
{
    int i = 0;
    int *values;
    if (min >= max)
    return (0);
    values = (int *)malloc(sizeof(int) * (max - min));
    while (min + 1 < max)
        {
            values[i] = min + 1;
            min++;
            i++;
        }
    return (values);
}

int main()
{
    int i = 0;
    int *values = ft_range(0, 10);
    while (values[i])
    {
        printf("%d\n", values[i]);
        i++;
    }
}
