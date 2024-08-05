#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while(s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

int main()
{
    char *src = "ola, eu sou o celson";
    char dest[100];

    ft_strcpy(dest, src);

    printf("\n\n\n %s", dest);

}