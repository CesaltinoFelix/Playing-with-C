#include <stdio.h>
#include <string.h>
int main(){

    char palavra[100];

    char *letra = &palavra;

    printf("Digite a palavra: ");
    gets(palavra);

    int tamanho = strlen(palavra);

    for(int i = 0; i < tamanho; i++){

       printf("\nPosicao: %d - Endereco: %p - Valor: %c", i, (void*)letra, *letra);
        letra++;
    }

    return 0;
}
