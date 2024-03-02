#include <stdio.h>

int main(){
void calcularSeculo(int *data, int *dia, int *mes, int *ano, int *seculo);
    int data, dia, mes, ano, seculo;
    printf("Digite a data (DDMMAAAA): ");
    scanf("%8d", &data);

    calcularSeculo(&data, &dia, &mes, &ano, &seculo);

    printf("\nA data %02d:%02d:%04d e equivale ao seculo : %d", dia,mes, ano, seculo);
    return 0;
}

void calcularSeculo(int *data, int *dia, int *mes, int *ano, int *seculo){
     *ano = *data % 10000;
     *mes = (*data / 10000) % 100;
     *dia = *data / 1000000;
     *seculo = *ano / 100 + 1;
}



