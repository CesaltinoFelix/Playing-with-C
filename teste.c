#include <stdlib.h>
#include <unistd.h>

void ft_putstr(char *str)
{
    while(*str)
        write(1, str++, 1);
}

void rev_wstr(char *str)
{
    int i=0, j=0, k=0, len=0;
    while (str[i])
    {
        if ((str[i] >= 33 && str[i] <= 126) && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
            len++;
        i++;
    }
    char** new_str = (char **)malloc(sizeof(char *) * (len + 1));
    for (int m = 0; m < len; m++)
    {
        new_str[m] = (char *)malloc(sizeof(char) * 256);
    }
    new_str[len] = NULL;
    while (str[i])
    {
        if (str[i] >= 33 && str[i] <= 126)
        {
            new_str[j][k] = str[i];
            k++;
        }
        if ((str[i] >= 33 && str[i] <= 126) && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
        (void)"";
    }
    
}
//testando o programa
int main(int argc, char *argv[])
{
    if(argc == 2)
        rev_wstr(argv[1]);
    write(1, "\n", 1);
    return 0;
}
