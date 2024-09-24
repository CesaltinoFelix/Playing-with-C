#include <stdio.h>

int main() {
    float num1 = 3.14159;
    double num2 = 3.14159265359;

    printf("Float: %.6f\n", num1); // Imprime com 6 casas decimais
    printf("Double: %.15f\n", num2); // Imprime com 15 casas decimais

    return 0;
}