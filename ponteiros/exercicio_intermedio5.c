// 8. Cópia de strings usando ponteiros:
//    - Crie uma função que copie o conteúdo de uma string para outra usando ponteiros.
#include <stdio.h>
#include <stdlib.h>

int str_len(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
char *copia(char *dest, char *src)
{
    int i = 0;
    int tamanho = str_len(src);
    dest = (char *)malloc(sizeof(char) * tamanho + 1);
    while(i < tamanho)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
int main(void)
{
    char *frase = "Ola, eu sou o cesaltino felix!";
    char *pcopia = NULL; 

    pcopia = copia(pcopia, frase);

    printf("Frase: %s", pcopia);
    free(pcopia);
}