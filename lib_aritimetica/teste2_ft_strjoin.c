#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int ft_len(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
char *ft_strjoin(int size, char **str, char *sep)
{
    char *result;
    int i = 0;
    int sep_len = ft_len(sep);
    int total_len_str;
    while (i++ < size)
        total_len_str += ft_len(str[i]);
    
    result = (char *)malloc(sizeof(char) * (total_len_str + sep_len * (size - 1)) + 1);
    // ft_strcpy(size, str, );
    return (result);
}

int main()
{
    int **str;
    str = (char **)malloc(sizeof(char *) * 3);
    str[0] = (char *)malloc(sizeof(char) * 5 + 1);
    str[1] = (char *)malloc(sizeof(char) * 7 + 1);
    str[2] = (char *)malloc(sizeof(char) * 12 + 1);
    str[0] = "Ola,";
    str[1] = "eu sou";
    str[2] = "o cesaltino";
    char sep[] = " ";
    char *result = ft_strjoin(3, str, sep);
    printf("%s$", result);
}