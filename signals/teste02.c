#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	is(char c, int base)
{
	const char *digits = "0123456789abcdef";
	const char *digits_upper = "0123456789ABCDEF";
	int i = 0;

	while (i < base)
	{
		if (digits[i] == c || digits_upper[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int n = 0;
	int s = 1;
	int val;

	while (str[i] == 32 || str[i] == 9)
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && (val = is(str[i], str_base)) != -1)
	{
		n = n * str_base + val;
		i++;
	}
	return (n * s);
}

char *convert_to_bits(char c)
{

	int i;
	int j;
	i = 8;
	j = 0;
	char *array_bits;
	unsigned char bit;
	
	array_bits = (char *)malloc(sizeof(char) * 8 + 1);
	while (i--)
	{
		bit = (c >> i & 1) ? '1' : '0';
		array_bits[j] = bit;
		j++;

	}
	
	return (array_bits);
}

int main(void)
{
	
	char *frase = "Ola eu sou o Cesaltino😀!";
	
	int i = 0;
	
	while(frase[i])
	{
		
	char *bits = convert_to_bits(frase[i]);
	int letra = ft_atoi_base(bits, 2); // Corrigido para a representação binária de 'a'	
	free(bits);
	printf("%c", letra); // Deve imprimir a letra pela representação decimal
	i++;
	}
}

