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
        if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
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
int		index_of_base(unsigned char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}
int ft_atoi_base(char *str, char *base)
{
    int sinal;
    int resultado;
    int i;
    sinal = 1;
    resultado = 0;
    int j = 0;
    int size = check_base(base);
    while (*str == ' ')
        str++;
    while (str[j])
    {
        if (str[j] == '-')
            sinal *= -1;

        j++;
    }

    i  = -1;
    while (str[++i] >= base[0] && str[i] <= base[size - 1] && str[i])
		resultado = (resultado * size) + (index_of_base(str[i], base));

        return (resultado * sinal);
}

int main()
{

    int r = ft_atoi_base("33", "0123456789");
    printf("restulado:  %d", r);
}