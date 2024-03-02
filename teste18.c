#include <stdio.h>

int main()
{
    int degraus;

    printf("Digite o numero de degraus: ");
    scanf("%d", &degraus);
    printf("\n");
    for (size_t i = 0; i <= degraus; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}