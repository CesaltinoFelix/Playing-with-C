// src/render.c

#include "so_long.h"

void render_map(t_data *data) {
    for (int y = 0; y < data->height; y++) {
        for (int x = 0; x < data->width; x++) {
            void *img_ptr = NULL;
            if (data->map[y][x] == WALL)
                img_ptr = data->wall_img;
            else if (data->map[y][x] == EMPTY)
                img_ptr = data->floor_img;
            else if (data->map[y][x] == PLAYER)
            {
                if(data->player_view_direction == FRONT)
                img_ptr = data->player_front_img;
                else if(data->player_view_direction == RIGHT)
                img_ptr = data->player_right_img;
                else if(data->player_view_direction == LEFT)
                img_ptr = data->player_left_img;
                else
                img_ptr = data->player_right_img;
            }
            else if (data->map[y][x] == COLLECTIBLE)
                img_ptr = data->collectible_img;
            else if (data->map[y][x] == EXIT)
                img_ptr = data->exit_img;
                
            if (img_ptr)
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, x * 32, y * 32);
        }
    }
}
