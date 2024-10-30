#include "so_long.h"

void initialize_data(t_data *data, char *map)
{
    initialize_map(data, map);
    data->remainder_colletible = 0;
    data->int_front_exit = 0;
    data->total_moves = 0;
    data->player_view_direction = RIGHT;
    count_collectibles_and_get_positions(data);

}
void count_collectibles_and_get_positions(t_data *data) {
    int y = 0;
    while (y < data->height)
    {
        int x = 0;
        while (x < data->width)
        {
            if (data->map[y][x] == 'C')
                data->remainder_colletible++;
            else if(data->map[y][x] == 'P')
            {
                data->player_x = x;
                data->player_y = y;
            }
            x++;
        }
        y++;
    }
}

void print_map(t_data *data)
{
    for (int y = 0; y < data->height; y++)
    {
	for (int i = 0; i < data->width; i++)
	{
        printf("%c", data->map[y][i]);
	}
	printf("\n");
    }
}