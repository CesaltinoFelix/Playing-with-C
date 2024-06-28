#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{

}

int main(void)
{

    int *tab = {1, 3, 5, 2, 2, 4};
    int size;
    size = 6;
    // sort_int_tab(tab, size);

    int i;
    i = 0;
    while(i < size)
    {
        printf("%i ", tab[i]);
        i++;
    }
}