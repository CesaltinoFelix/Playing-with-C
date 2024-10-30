#include "so_long.h"

int main(int argc, char *argv[])
{
    t_data data;
    (void)argc;
    initialize_data(&data, argv[1]);
   

    int width, height; 
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);

    data.win_ptr = mlx_new_window(data.mlx_ptr, 32 * data.width, 32 * data.height, "So_long");
    if (!data.win_ptr)
        return (free(data.mlx_ptr), 1);

    data.wall_img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/wall.xpm", &width, &height);
    data.floor_img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/floor.xpm", &width, &height);
    data.player_right_img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/player_right.xpm", &width, &height);
    data.player_left_img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/player_left.xpm", &width, &height);
    data.player_front_img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/player_front.xpm", &width, &height);
    data.collectible_img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/collectible.xpm", &width, &height);
    data.exit_img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/exit.xpm", &width, &height);

    if (!data.wall_img || !data.floor_img || !data.player_right_img || !data.player_left_img || !data.player_front_img || !data.collectible_img || !data.exit_img)
    {
        fprintf(stderr, "Erro ao carregar imagens\n");
        //LIPAR BEM O VAZAMENTO DE MEMORIA QUANDO AS IMAGENS NAO SAO CARREGADAS COM SUCESSO
        on_destroy(&data);
    }

    mlx_hook(data.win_ptr, 2, 1L << 0, &on_keypress, &data);
    mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

    render_map(&data);
    mlx_loop(data.mlx_ptr);

    return (0);
}
