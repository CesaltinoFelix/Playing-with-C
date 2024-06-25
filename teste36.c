#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char *nome = NULL;  // Inicialmente, o ponteiro está apontando para NULL
    size_t tamanho = 0; // Tamanho inicial do nome
    char c;

    printf("Digite um nome (ou 'fim' para sair): ");

    // Lê caracteres até encontrar uma quebra de linha ou EOF
    while ((c = getchar()) != '\n' && c != EOF) {
        // Aumenta o tamanho do nome em 1 para o próximo caractere
        tamanho++;
        // Realoca memória para o nome com o novo tamanho
        char *temp = (char *)realloc(nome, (tamanho + 1) * sizeof(char));
        if (temp == NULL) {
            printf("Erro ao realocar memória.\n");
            free(nome); // Libera a memória previamente alocada
            return 1;   // Termina o programa com código de erro
        }
        nome = temp;  // Atualiza o ponteiro para o novo endereço realocado
        // Adiciona o caractere lido ao nome
        nome[tamanho - 1] = (char)c;
        nome[tamanho] = '\0'; // Adiciona o caractere nulo ao final da string
    }

    printf("O nome e: %s\n", nome);

    free(nome); // Libera a memória alocada para o nome

    return 0;
}

