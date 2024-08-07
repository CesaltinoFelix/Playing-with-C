#include<stdio.h>
int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;

    while(s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0' ))
        i++;
    if(s1[i + 1] == '\0' && s2[i + 1] == '\0')
        return (1);
    else return (0);
}

int main(void)
{
    char a[] = {'a', 'b', 'c'};
    char b[] = {'a', 'b', 'c'};

   int c = ft_strcmp(a, b);
   printf("Resultado: %d", c);
    return (0);
}

