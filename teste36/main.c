#include <stdio.h>
#include "funcoes.h"
// #include <stdlib.h>

int main(){
    int num1 = 1;
    int num2 = 2;

    printf("Num1: %d, Num2: %d", num1, num2);
    trocarValores(&num1, &num2);
    printf("Num1: %d, Num2: %d", num1, num2);
    return (0);
}
