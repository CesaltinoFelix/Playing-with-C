#include <stdio.h>

void swap(int **n1, int **n2){
    int aux = **n1;
    **n1 = **n2;
    **n2 = aux;

}
int main(){

    int num1 = 1, num2 = 2;

    int *pNum1 = &num1;
    int *pNum2 = &num2;
    swap(&pNum1, &pNum2);

    printf("Num1 :%d, Num2 :%d", num1, num2);
    return 0;
}