#include <stdio.h>


int main(void){

    void mostrarNovoTexto(const char *texto);
    const char texto[100];
    const char *ponteiroTexto = &texto;

    printf("Digite o texto: ");
    gets(texto);

    mostrarNovoTexto(ponteiroTexto);
    return 0;
}

void mostrarNovoTexto(const char *texto){

    while (*texto)
    {
        if(*texto == ' ') printf("%c", '-');
        else printf("%c", *texto);    
        texto++;
    }
    
}