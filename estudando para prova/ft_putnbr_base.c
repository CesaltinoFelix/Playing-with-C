#include <unistd.h>
#include <stdio.h>
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
        if (base[i] == '+' || base[i] == '-')
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

void ft_putnbr_base(int nbr, char *base)
{
    unsigned int size;
    unsigned int nb;

    size = check_base(base);
    if (size == 0)
        return;
    if (nbr < 0)
    {
        ft_putchar('-');
        nb = nbr * -1;
    }
    else
        nb = nbr;

    if (nb >= size){

        ft_putnbr_base(nb / size, base);
    }
    ft_putchar(base[nb % size]);
}

int main(void)
{
    // Teste com Numero positivo em base decimal
    printf("Numero 42 em base decimal: ");
    ft_putnbr_base(42, "0123456789");
    printf("\n");

    // Teste com Numero positivo em base binária
    printf("Numero 42 em base binária: ");
    ft_putnbr_base(-42, "01");
    printf("\n");

    // Teste com Numero negativo em base hexadecimal
    printf("Numero -42 em base hexadecimal: ");
    ft_putnbr_base(42, "0123456789ABCDEF");
    printf("\n");

    // Teste com Numero positivo em base octal
    printf("Numero 42 em base octal: ");
    ft_putnbr_base(42, "poneyvif");
    printf("\n");

    return 0;
}
