#include "game.h"


void print_map(t_data *data)
{
    for (int y = 0; y < 5; y++)
    {
	for (int i = 0; i < 13; i++)
	{
        printf("%c", data->map[y][i]);
	}
	printf("\n");
    }
}