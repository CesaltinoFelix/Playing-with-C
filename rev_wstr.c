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

char **ft_split(char *str, int *size)
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
        while(str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
            i++;
        words++;
        while(str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            i++;
    }

    char **strings = (char **)malloc(sizeof(char *) * (words + 1));

    if(!strings)
        return (NULL);
    
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
            if(!strings[k])
                return (NULL);
                
           ft_strncpy(strings[k++], &str[j], i - j); 
        }   
    }

    strings[k] = NULL;
    *size = words;
    return (strings);
}

void ft_rev_wstr(char *str)
{
    int size;
    int i;
    char **strings = NULL;

    size = 0;
    strings = ft_split(str, &size);
    size--;
    while (size >= 0)
    {
        i = 0;
        while(strings[size][i] != '\0')
        {
            write(1, &strings[size][i], 1);
            i++;
        }
        if(size != 0)
        write(1, " ", 1);
        size--;
    }
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        ft_rev_wstr(argv[1]);
    }else
        write(1, '\n', 1);
}