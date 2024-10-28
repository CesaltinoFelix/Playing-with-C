// src/render.c

#include "game.h"

void render_map(t_data *data) {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 13; x++) {
            void *img_ptr = NULL;
            if (data->map[y][x] == '1')
                img_ptr = data->wall_img;
            else if (data->map[y][x] == '0')
                img_ptr = data->floor_img;
            else if (data->map[y][x] == 'P')
                img_ptr = data->player_img;
            else if (data->map[y][x] == 'C')
                img_ptr = data->collectible_img;
            else if (data->map[y][x] == 'E')
                img_ptr = data->exit_img;

            if (img_ptr)
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, x * 32, y * 32);
        }
    }
}
