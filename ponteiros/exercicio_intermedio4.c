#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <errno.h>
#include <string.h>

void log_error(const char *message) {
    FILE *log_file = fopen("error_log.txt", "a"); // Abre o arquivo em modo de adição
    if (log_file == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo de log: %s\n", strerror(errno));
        return;
    }
    
    fprintf(log_file, "Erro: %s\n", message);
    fclose(log_file);
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int i;
    int tamanho;
    int *valores = NULL;


    printf("Informe o tamanho do vetor: ");
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
        fprintf(stderr, "Entrada inválida: %s\n", strerror(errno));
        log_error("Entrada inválida para o tamanho do vetor.");
        return 1;
    }

    valores = (int *)malloc(sizeof(int) * tamanho);
    if (valores == NULL) {
        fprintf(stderr, "Erro ao alocar memória: %s\n", strerror(errno));
        log_error("Erro ao alocar memória.");
        return 1;
    }

    for (i = 0; i < tamanho; i++) {
        printf("\nDigite %d* valor: ", i + 1);
        if (scanf("%d", &valores[i]) != 1) {
            fprintf(stderr, "Entrada inválida\n");
            log_error("Entrada inválida ao ler o valor do vetor.");
            free(valores);
            return 1;
        }
    }

    printf("\n\nImprimindo valores...\n");

    for (i = 0; i < tamanho; i++) {
        printf("\n[%d] - %d", i, valores[i]);
        // fprintf(file, "[%d] - %d\n", i, valores[i]); // Escreve os valores no arquivo
    }

    printf("\n");

    free(valores);
    return 0;
}
