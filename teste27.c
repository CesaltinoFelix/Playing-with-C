#include <stdio.h>

void ft_sort_int_tab(int *tab, int size)
{

    int temp, i = 0;
    while (i < (size/2))
    {
                temp = tab[i];
                tab[i] = tab[size - (i + 1)];
                tab[size - (i + 1)] = temp;
        i++;
    }
}

int main(void)
{
    int i;
    int tab[] = {10, 3, 1, 6, 2};
    int size;

    size = 5;
    ft_sort_int_tab(tab, size);
    for (i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
}