#include <stdio.h>

void ft_sort_int_tab(int *tab, int size)
{

    int temp, i = 0, j = 0;
    while (i < size)
    {
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        j = 0;
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