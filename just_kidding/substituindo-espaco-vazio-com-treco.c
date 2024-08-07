#include <stdio.h>
#include <string.h>
int main(){

    char texto[100];

    printf("Digite o texto: ");
    gets(texto);

    int tamanho = strlen(texto);

    printf("\n");
    for(int i = 0; i < tamanho; i++)
    {
        if(texto[i] == ' ') printf("%c", '-');
        else printf("%c", texto[i]);
    }
    
    return 0;
}