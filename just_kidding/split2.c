#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_strncpy(char *dest, char *src, int n)
{
    int	i;

    i = 0;
    while(i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char **ft_split(char *str)
{
	int	i;
	int	j;
	int	k;
	int words;

	i = 0;
	k = 0;
	words = 0;

	while(str[i])
	{
	while(str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		i++;
	if(str[i])
		words++;
	while(str[i] && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'))
		i++;
	}
	char **strings = (char **)malloc(sizeof(char *) * (words + 1));
	i = 0;
	while(str[i])
	{
		while(str[i]  && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
			i++;
		j = i;
		while(str[i] && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'))
			i++;
	
	
		if(i > j){
			strings[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(strings[k++], &str[j], i - j);
		}
	}
	strings[k] = NULL;
	return (strings);
}

int main(int argc, char **argv)
{
    int	i;

    i = 0;
    if(argc == 2){
        char **strings = ft_split(argv[1]);
		while(strings[i])
		{
			printf("[%i] - %s\n",i, strings[i] );
			i++;
		}
    }else
    printf("Erro!");

    return (0);
}