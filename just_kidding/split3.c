#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


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

char **ft_split(char *src)
{
     int i;
    int j;
    int k;
    int words;

    i = 0;
    k = 0;
    words = 0;

    while(src[i])
    {
        while(src[i] && (src[i] == ' ' || src[i] == '\t' || src[i] == '\n'))
            i++;
        words++;
        while(src[i] && (src[i] != ' ' && src[i] != '\t' && src[i] != '\n'))
            i++;
    }
    char **strings = (char **)malloc(sizeof(char *) * (words +  1));
    if(!strings)
        return NULL;
    i = 0;
    while(src[i])
    {
        while(src[i] && (src[i] == ' ' || src[i] == '\n' || src[i] == '\t'))
            i++;
        j = i;
        while(src[i] && (src[i] != ' ' && src[i] != '\t' && src[i] != '\n'))
        i++;
        if(i > j)
        {
            strings[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
            if(!strings[k])
                return NULL;
            ft_strncpy(strings[k++], &src[j], i - j);
        }
    }    
    return (strings);
}

int main(int argc, char **argv)
{
    if(argc == 2){
    int i;
    char **strings = NULL;
    i = 0;

    strings = ft_split(argv[1]);
    while(strings[i])
    {
        printf("[%i] - %s\n", i, strings[i]);
        i++;
    }
    }else
    printf("Erro: Digite o parametro de entrada!");
}