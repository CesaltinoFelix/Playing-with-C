#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
    int num1 = 1, num2 = 2;
    TrocaValores(&num1, &num2);

    printf("Num1: %d, Num2: %d", num1, num2);
    return (0);
}
