#include <stdio.h>
#include <string.h>
struct livro{
    char nome[50];
    char autor[50];
    int ano;
};

void infoLivro(struct livro l){
    printf("\nNome: %s, ano: %d, autor: %s", l.nome, l.ano, l.autor);
}
int main(){

    struct livro l;
    strcpy(l.nome, "O novo mundo");
    strcpy(l.autor, "Cesaltino Felix");
    l.ano = 2000;

    infoLivro(l);
    return 0;
}