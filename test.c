#include <stdio.h>
#include <stdlib.h>

void difine_value(int *valores)
{
	int i = -1;
	while(++i < 5)
		valores[i] = i;
}
void print_value(int *valores)
{
	int i = -1;
	printf("&valores = %p\n", &valores);
	while(valores[++i])
		printf("valores = %p | *value %d", valores, *valores);
}

int main(void)
{
	int *valores = NULL;

	valores = (int *)malloc(sizeof(int) * 5);

	difine_value(valores);
	print_value(valores);
	free(valores);
}
