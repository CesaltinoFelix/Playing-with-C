#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int check_base(char *base)
{
    int i;
    int j;

    i = 0;
    while (base[i])
    {
        j = i + 1;

        if (base[i] == '-' || base[i] == '+')
            return (0);
        while (base[j])
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    if (i < 2)
        return (0);
    return (i);
}

void ft_putnbr_base(int n, char *base)
{
    int size;

    size = check_base(base);
    if (size == 0)
        return ;
    if (n < 0)
    {
        write(1, "-", 1);
        n *= -1;
    }

    if (n >= 10)
        ft_putnbr_base(n / size, base);
    ft_putchar(base[n % size]);
}

int main()
{
    ft_putnbr_base(42, "01");
}