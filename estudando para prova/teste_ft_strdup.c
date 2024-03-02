#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
char *ft_strdup(char *src)
{
    char *str1;
    int i = 0;
    int j = 0;
    while (src[i] != '\0')
        i++;
    str1 = (char *)malloc(i * sizeof(char));

    while (src[j] != '\0')
    {
        str1[j] = src[j];
         j++;
    }
    str1[j] = '\0';
    return (str1);
}
int main(void)
{
    char str[] = "eu sou o cesaltino.";
    char *str1 = ft_strdup(str);
    int i = -1;
    while (str1[++i] != '\0')
    write (1, &str1[i], 1);
    // printf("%s", *str1);
}