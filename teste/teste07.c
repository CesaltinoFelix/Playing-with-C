#include <stdio.h>

int main(){

    const int i = 20;
    const int *a = &i;
    const int **b = &a;
    int ***c = &b;
    ***c = 5;


    printf("Valor de i: %d\n", i);
    return 0;
}
