#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
char *ft_strncpy(char *dest, char *src, int n)
{
    int i;

    i = 0;
    while(i < n && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char    **ft_split(char *str)
{
    int i;
    int j;
    int words;

    i = 0;
    words = 0;
    while(str[i])
    {
        while(str[i] && str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        words++;
        while(str[i] && str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
            i++;
    }

    printf("\n\n\npalavras: %d", words);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_split(argv[1]);
    }

    write(1, "Erro!", 5);
    return (0);
}