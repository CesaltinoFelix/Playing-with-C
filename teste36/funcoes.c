#include "funcoes.h"

void trocarValores(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}