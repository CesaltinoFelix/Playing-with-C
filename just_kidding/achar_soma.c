#include <stdio.h>

int main() {
    int n, i;
    float soma = 0;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("O n deve ser um numero inteiro nao negativo!");
    } else {
        for (i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                soma = soma - (2.0 * i) / (2.0 * i + 1);
            } else {
                soma = soma + (2.0 * i) / (2.0 * i + 1);
            }
        }
    }

    printf("\nA soma e: %f", soma);

    return 0;
}
