#include <stdio.h>
#include <string.h>
int main(){

    char texto[100];

    gets(texto);

    char *pTexto = &texto;

    int tamanho = strlen(texto);
    for(int i = 0; i < tamanho;i++){
        if(*pTexto == ' ') printf("-");
        else printf("%c", *pTexto);

        pTexto++;
    }
    return 0;
}
