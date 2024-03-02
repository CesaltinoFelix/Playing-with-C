//Digite a data no formato DDMMAAAA e diz o seculo correspondente

#include <stdio.h>

int main(){
    void calcularSeculo(int *ano, int *mes, int *dia, int *seculo, int *data);
    int ano, mes, dia, seculo, data;

    printf("Digite a data: ");

    scanf("%8d", &data);

    calcularSeculo(&ano, &mes, &dia, &seculo, &data);

    printf("A data %02d:%02d:%04d , equivale ao seculo : %d",dia, mes, ano, seculo);

    return 0;
}

void calcularSeculo(int *ano, int *mes, int *dia, int *seculo, int *data){

    *ano = *data % 10000;
    *mes = (*data / 10000) % 100;
    *dia =  *data / 1000000;

    *seculo = (*ano % 100) == 0 ? (*ano / 100) : (*ano / 100 + 1);
}




















