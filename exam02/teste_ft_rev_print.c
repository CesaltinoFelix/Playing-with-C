#include<unistd.h>
int ft_str_len(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
char *ft_rev_print (char *str)
{
    int len;
    
    len = ft_str_len(str);
    while (--len >= 0)
        write(1, &str[len], 1);
    write(1, "\n", 1);    
    return (str);
}

int main()
{
    ft_rev_print("dub0 a POIL");
}