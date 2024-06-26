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
    int k;
    int words;

    i = 0;
    k = 0;
    words = 0;

    while(str[i])
    {
        while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        if (str[i])
            words++;      
        while(str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            i++;
    }

    char **strings = (char **)malloc(sizeof(char *) + 1);

    i = 0;
     while(str[i])
    {
        while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        j = i;         
        while(str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            i++;
        if(i > j)
        {
            strings[k] = (char *)malloc(sizeof(char) * (i - j) + 1);
            ft_strncpy(strings[k++], &str[j], i - j);
        }
    }
    strings[k] = NULL;
    return (strings);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i;
        i = 0;
        char **strings = ft_split(argv[1]);
        while(strings[i])
        {
            printf("\n[%d] - %s", i, strings[i]);
            i++;
        }
    }else
    write(1, "Erro!", 5);

    return (0);
}