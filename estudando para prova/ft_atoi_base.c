
#include <stdio.h>

int		check_base(char *base)
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

int		ft_atoi_base(char *str, char *base)
{
	int sign;
	int i;
	int base_len;
	int num;

	num = 0;
	base_len = check_base(base);
	sign = 0;
	if (!base_len)
		return (0);
	while ((*str == '\t' || *str == '\v' || *str == '\f' || *str == '\n' || \
			*str == '\r' || *str == ' ') && *str)
		str++;
	while ((*str == '+' || *str == '-') && *str)
	{
		if (*str++ == '-')
			sign++;
	}
	i = -1;
	while (str[++i] >= base[0] && str[i] <= base[base_len - 1] && str[i])
		num = (num * base_len) + (index_of_base(str[i], base));
	return (num * ((sign % 2 == 1) ? -1 : 1));
}


int main(void)
{
    // Teste com número positivo em base decimal
    printf("Resultado: %d\n", ft_atoi_base("42", "0123456789"));

    // Teste com número negativo em base binária
    printf("Resultado: %d\n", ft_atoi_base("-101010", "01"));

    // Teste com número positivo em base hexadecimal
    printf("Resultado: %d\n", ft_atoi_base("2A", "0123456789ABCDEF"));

    // Teste com número negativo em base octal
    printf("Resultado: %d\n", ft_atoi_base("42", "01234567"));

    // Teste com base inválida (deve retornar 0)
    printf("Resultado: %d\n", ft_atoi_base("42", "+-*/"));

    return 0;
}
