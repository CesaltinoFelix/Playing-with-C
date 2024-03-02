#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_total_len(char *strs)
{
    int i = 0;
    while (strs[i] != '\0')
        i++;
    return (i);
}

void ft_strcpy(int size,char *dest, char **src, char *sep)
{
    int i = 0;
    int j;
    int z;
    int k = 0;
    while (i < size)
    {
        j = 0;
        while (src[i][j] != '\0')
        {
            dest[k] = src[i][j];
            j++;
            k++;
        }
        if ((i + 1) != size)
        {
            z = 0;
            while (sep[z] != '\0')
            {
                dest[k] = sep[z];
                k++;
                z++;
            }
            
        }
        i++;
    }
    dest[k] = '\0';
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    char *str_final; 
    int final_len = 0;
    int len_sep;
    int i = 0;
    while (i < size)
    {
        final_len += ft_total_len(strs[i]);
        i++;
    }
    len_sep = ft_total_len(sep);

    str_final = (char *)malloc(sizeof(char) * (final_len + len_sep) + 1);
    ft_strcpy(size, str_final, strs, sep);
    return (str_final);
}

int main()
{
    char **str;
    char *result;
    str = (char **)malloc(sizeof(char *) * 2);
    str[0] = (char *)malloc(sizeof(char) * 7 + 1);
    str[1] = (char *)malloc(sizeof(char) * 6 + 1);
    str[2] = (char *)malloc(sizeof(char) * 14 + 1);
	str[0] = "Hello";
	str[1] = "friend,";
	str[2] = "you are awesome";
    char sep[] = "--";
    result = ft_strjoin(3, str, sep);
    printf("%s$\n", result);

    // Libere a memória alocada
    free(result);
    free(str[0]);
    free(str[1]);
    free(str);

    return 0;
}
