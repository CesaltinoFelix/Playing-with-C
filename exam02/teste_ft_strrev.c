#include<stdio.h>
#include<unistd.h>
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
char    *ft_strrev(char *str)
{
    int i;
    int len;
    char temp;
    len = ft_strlen(str);
    i = 0;
    len--;
   while (len > i)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
  
    return (str);
}


int main() {
    char str[] = "celson";
    ft_strrev(str);
    write(1, str, ft_strlen(str));
    return 0;
}