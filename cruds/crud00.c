#include <stdio.h>
#include <stdlib.h>

typedef struct _livro
{
    char titulo[50];
    int paginas;
    double preco;
} Livro;

void print

int main(void)
{
    Livro livro = {.titulo = "A era do gelo", .paginas = 200, .preco = 1999.99};

    printf("INFORMACOES DO LIVRO:\n");
    printf("-----------------------\n");
    printf("Titulo: %s\nPaginas: %d\nPreco: %.2lf\n", livro.titulo, livro.paginas, livro.preco);

}