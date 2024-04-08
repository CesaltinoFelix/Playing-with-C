#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

void ft_strcpy(char *str, char *dest)
{
    int tamanho;
    int i;

    i = 0;
    tamanho = ft_strlen(str);

    while (i < tamanho)
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
}

int ft_count_word(char **words)
{
    int i;
    int j;
    int count;

    count = 0;
    i = -1;
    while (words[++i])
    {
        j = -1;
        while (words[i][++j] != '\0')
        {
        }
        count++;
    }
    return (count);
}

int main(int argc, char **argv)
{

    if (argc >= 2)
    {
        int num_words;
        int tamanho;
        char **nomes;
        int i;
        argv++;
        num_words = ft_count_word(argv);
        nomes = malloc(sizeof(char *) * num_words);
        i = -1;
        while (++i < num_words)
        {
            tamanho = ft_strlen(argv[i]);
            nomes[i] = malloc(sizeof(char) * tamanho + 1);
            ft_strcpy(argv[i], nomes[i]);
        }

        i = -1;
        while (++i < num_words)
            printf("Nome: %s\n", nomes[i]);

        i = -1;
        while (++i < num_words)
            free(nomes[i]);

        free(nomes);
    }
    else
    {
        printf("Digite um nome!");
    }
    return (0);
}