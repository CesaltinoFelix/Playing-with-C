#include "game.h"

int on_destroy(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(0);
    return (0);
}

void end_game(t_data *data)
{
    print_map(data);
    on_destroy(data);
}

void	free_map(t_data *data)
{
	
}