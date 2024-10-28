// src/main.c

#include "game.h"

// Função principal do programa
int main(void)
{
    t_data data; // Cria a estrutura de dados do jogo
    initialize_data(&data);
    data.player_x = 1; // Define a posição inicial x do jogador
    data.player_y = 3; // Define a posição inicial y do jogador

    int width, height; 
    data.mlx_ptr = mlx_init(); // Inicializa a conexão com o MLX
    if (!data.mlx_ptr)
        return (1); // Retorna 1 em caso de falha na inicialização

    // Cria uma nova janela com dimensões baseadas no tamanho do mapa
    data.win_ptr = mlx_new_window(data.mlx_ptr, 32 * 13, 32 * 5, "hi, Cesaltino Felix :)");
    if (!data.win_ptr)
        return (free(data.mlx_ptr), 1); // Retorna em caso de falha na criação da janela

    // Carrega as imagens e verifica se foram carregadas corretamente
    data.wall_img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/wall.xpm", &width, &height);
    data.floor_img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/floor.xpm", &width, &height);
    data.player_img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/player.xpm", &width, &height);
    data.collectible_img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/collectible.xpm", &width, &height);
    data.exit_img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/exit.xpm", &width, &height);

    // Verifica se todas as imagens foram carregadas corretamente
    if (!data.wall_img || !data.floor_img || !data.player_img || !data.collectible_img || !data.exit_img)
    {
        fprintf(stderr, "Erro ao carregar imagens\n"); // Mensagem de erro
        on_destroy(&data); // Libera recursos e sai do programa
    }

    // Configura hooks para eventos de teclado e fechamento da janela
    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
    mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

    render_map(&data); // Renderiza o mapa inicial na janela
    mlx_loop(data.mlx_ptr); // Inicia o loop do MLX

    return (0); // Finaliza o programa
}
