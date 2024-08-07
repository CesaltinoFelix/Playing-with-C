#include <stdio.h>

int main()
{

    // char nome[] = {"Cesaltino"};
    char nome[] = "Celson";
    printf("Nome: %s\n", nome);
    int tamanho = 0;
    // for (int i = 0; nome[i] != '\0'; i++)
    // {
    //     tamanho++;
    // }

    while(nome[tamanho] != '\0'){
        tamanho++;
    }

    printf("Tamanho = %d", tamanho);
    return 0;
}