#include <stdio.h>
#include <string.h>
    struct Pessoa{
        char nome[50];
        int idade;
        char genero;
    };
int main(){

    struct Pessoa pessoa[20];
    for (size_t i = 0; i < 20; i++)
    {
         pessoa[i].idade = 100;
    pessoa[i].genero = 'M';
    strcpy(pessoa[i].nome,"Cesaltino Felix");
    }
    

    printf("\nNome: %s , idade : %d, Genero: %c", pessoa[0].nome, pessoa[0].idade, pessoa[0].genero);
    return 0;
}
