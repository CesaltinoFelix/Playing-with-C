#include "so_long.h"

int on_destroy(t_data *data)
{
    free_assets(data);
    free_map(data);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    data->mlx_ptr = NULL;

    exit(0);
    return (0);
}

void free_map(t_data *data)
{
    int i = 0;

    while (i < data->height) {
        free(data->map[i]);
        i++;
    }

    free(data->map);
    data->map = NULL;
}

void free_assets(t_data *data)
{
    mlx_destroy_image(data->mlx_ptr, data->floor_img);
    mlx_destroy_image(data->mlx_ptr, data->collectible_img);
    mlx_destroy_image(data->mlx_ptr, data->exit_img);
    mlx_destroy_image(data->mlx_ptr, data->player_right_img);
    mlx_destroy_image(data->mlx_ptr, data->player_left_img);
    mlx_destroy_image(data->mlx_ptr, data->player_front_img);
    mlx_destroy_image(data->mlx_ptr, data->wall_img);
}
