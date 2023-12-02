#include <stdio.h>

int main() {
    int data, dia, mes, ano, seculo;

    // Leitura da data no formato DDMMAAAA
    printf("Digite a data no formato DDMMAAAA: ");
    scanf("%8d", &data);

    // Extrai o dia, mês e ano da data
    dia = data / 1000000;
    mes = (data / 10000) % 100;
    ano = data % 10000;

    // Calcula o século
    seculo = ano / 100 + ((mes <= 2) ? 0 : 1);

    // Exibe o resultado
    printf("A data %02d/%02d/%04d corresponde ao século %d.\n", dia, mes, ano, seculo);

    return 0;  // Encerra o programa com código de sucesso
}
