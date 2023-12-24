#include <stdio.h>

int ft_strlen(char *str){
    int i = 0;
    while (*str != '\0')
    {
        str++;
        i++;
    }
    return i;
}
int main(){

    char *str;
    int lenght;

    str = "cesaltino";
    lenght = ft_strlen(str);
    printf("Tamanho: %d", lenght);
}