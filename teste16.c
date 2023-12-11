#include <stdio.h>

void preencheVector(int vector[5]);
void printfVector(int vector[5]);

int main()
{

    int vector[5];

    preencheVector(vector);
    printfVector(vector);

    return 0;
}

void preencheVector(int vector[])
{
    for (size_t i = 0; i < 5; i++)
    {
        printf("Digite o %d valor ", i + 1);
        scanf("%d", &vector[i]);
    }
}
void printfVector(int vector[])
{

    for (size_t i = 0; i < 5; i++)
    {
        printf("Valor %d =  %d \n", i + 1, vector[i]);
    }
}