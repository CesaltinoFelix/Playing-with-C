#include <stdlib.h>
#include <unistd.h>
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

char **ft_split(char *str, int *num_words)
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
        words++;
        while(str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
        i++;
    }

    char **strings = (char**)malloc(sizeof(char *) * (words + 1));
    if(!strings)
        return NULL;

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
            strings[k] = (char *)malloc(sizeof(char) * (i - j)+ 1);
                if(!strings[k])
                {
                    for(int m = 0; m <= k; i++)
                        free(strings[m]);
                    free(strings);
                }
            ft_strncpy(strings[k++], &str[j], i - j);
        }
    }

    strings[k] = NULL;
    *num_words = words;
    return (strings);
}

void ft_free_strings(char **str)
{
    int i;
    i = 0;

    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void ft_rev_wstr(char *str)
{
    int i;
    int num_words;
    char **strings = NULL;
    num_words = 0;
    strings = ft_split(str, &num_words);
    num_words--;
    while(num_words >= 0)
    {
        i = 0;
        while(strings[num_words][i])
        {
            write(1, &strings[num_words][i], 1);
            i++;
        }
        if(!(num_words == 0))
            write(1, " ", 1);
        num_words--;
        
    }
    ft_free_strings(strings);
}

int main(int argc, char **argv)
{
    if(argc == 2)
        ft_rev_wstr(argv[1]);
    write(1, "\n", 1);
    return (0);
}