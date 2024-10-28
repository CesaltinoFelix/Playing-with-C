#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <unistd.h>
#include <string.h>

// Estrutura de dados principal para armazenar as informações do jogo
typedef struct s_data
{
    void *mlx_ptr;            // Ponteiro para a estrutura do MLX
    void *win_ptr;            // Ponteiro para a janela do MLX
    char map[5][14];          // Mapa do jogo, representado como um array bidimensional
    int player_x;             // Posição x do jogador no mapa
    int player_y;             // Posição y do jogador no mapa
    void *wall_img;           // Imagem da parede
    void *floor_img;          // Imagem do chão
    void *player_img;         // Imagem do jogador
    void *collectible_img;    // Imagem do item colecionável
    void *exit_img;           // Imagem da saída
    int total_collectible_get;
    int remainder_colletible;
    int int_front_exit;
    int total_moves;
} t_data;

// Inicializa o mapa com os valores predefinidos
void initialize_map(t_data *data)
{
    const char map[5][14] = {
        "1111111111111",  // Linha 1 do mapa: paredes
        "10010000000C1",  // Linha 2 do mapa: jogador e item colecionável
        "10C0011111001",  // Linha 3 do mapa: item colecionável
        "1PC011E00C001",  // Linha 4 do mapa: jogador e saída
        "1111111111111"   // Linha 5 do mapa: paredes
    };

    // Copia cada linha do mapa predefinido para a estrutura de dados
    for (int i = 0; i < 5; i++)
    {
        strcpy(data->map[i], map[i]);
    }
}

int count_collectibles(t_data *data) {
    int count = 0;
    int y = 0; // Inicializa a linha
    while (y < 5) { // Enquanto y for menor que 5 (número de linhas)
        int x = 0; // Inicializa a coluna
        while (x < 13) { // Enquanto x for menor que 13 (número de colunas)
            if (data->map[y][x] == 'C') { // Se o caractere for 'C'
                count++; // Incrementa o contador
            }
            x++; // Move para a próxima coluna
        }
        y++; // Move para a próxima linha
    }
    return count; // Retorna o total de coletáveis
}

void initialize_data(t_data *data)
{
    initialize_map(data); // Inicializa o mapa
    data->remainder_colletible = count_collectibles(data);
    data->int_front_exit = 0;
    data->total_moves = 0;

}

// Função chamada ao fechar a janela
int on_destroy(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr); // Destrói a janela
    mlx_destroy_display(data->mlx_ptr);                // Libera o display do MLX
    free(data->mlx_ptr);                               // Libera a memória do MLX
    exit(0);                                           // Encerra o programa
    return (0);
}

// Função que renderiza o mapa
void render_map(t_data *data);

// Função que imprime o mapa no terminal (para depuração)
void print_map(t_data *data)
{
    for (int y = 0; y < 5; y++)
    {
        printf("%s\n", data->map[y]);
    }
}

void end_game(t_data *data)
{
    print_map(data);
    on_destroy(data);
}

// Função que movimenta o jogador
void move_player(t_data *data, int new_x, int new_y)
{
    //print_map(data); // Imprime o mapa atual para depuração
    printf("Trying to move player to %d, %d\n", new_x, new_y); // Mensagem de depuração

    // Verifica se a nova posição está fora dos limites do mapa
    if (new_x < 0 || new_y < 0 || new_y >= 5 || new_x >= 13)
    {
        printf("Move out of bounds\n");
        return; // Se a nova posição estiver fora dos limites, sai da função
    }

    printf("Accessing map at %d, %d: %c\n", new_x, new_y, data->map[new_y][new_x]); // Mensagem de depuração
    
    // Verifica se a nova posição não é uma parede
    if (data->map[new_y][new_x] != '1')
    {
        //printf("player position: %d %d\n", data->player_x, data->player_y);
        data->total_moves++;
        printf("Toatl moves: %d\n", data->total_moves);

        if(data->map[new_y][new_x] == 'C')
            data->remainder_colletible--;

        if(data->int_front_exit)
        {
            data->map[data->player_y][data->player_x] = 'E';
            data->int_front_exit = 0;
        }

        else if(data->map[new_y][new_x] == 'E')
        {
            if(data->remainder_colletible == 0)
                end_game(data);
            data->int_front_exit = 1;
            data->map[data->player_y][data->player_x] = '0'; // Marca a posição antiga do jogador como chão

        }
        else
        data->map[data->player_y][data->player_x] = '0'; // Marca a posição antiga do jogador como chão
        
        data->map[new_y][new_x] = 'P'; // Atualiza a nova posição do jogador
        data->player_x = new_x; // Atualiza a posição x do jogador
        data->player_y = new_y; // Atualiza a posição y do jogador
   
       
        render_map(data); // Renderiza o mapa atualizado
    }
    else
    {
        printf("Move blocked by wall\n"); // Mensagem se a movimentação for bloqueada por uma parede
    }
}

// Função que lida com eventos de teclas pressionadas
int on_keypress(int keysym, t_data *data)
{
    // Verifica qual tecla foi pressionada
    if (keysym == XK_Escape)
    {
        on_destroy(data); // Sai do jogo ao pressionar Esc
    }
    else if (keysym == XK_w) // Movimento para cima
    {
        move_player(data, data->player_x, data->player_y - 1);
    }
    else if (keysym == XK_s) // Movimento para baixo
    {
        move_player(data, data->player_x, data->player_y + 1);
    }
    else if (keysym == XK_a) // Movimento para a esquerda
    {
        move_player(data, data->player_x - 1, data->player_y);
    }
    else if (keysym == XK_d) // Movimento para a direita
    {
        move_player(data, data->player_x + 1, data->player_y);
    }
    return (0);
}

// Função que renderiza o mapa na janela
void render_map(t_data *data)
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 13; x++)
        {
            void *img_ptr = NULL; // Ponteiro para a imagem a ser renderizada
            // Verifica qual parte do mapa está sendo renderizada
            if (data->map[y][x] == '1')
                img_ptr = data->wall_img; // Imagem da parede
            else if (data->map[y][x] == '0')
                img_ptr = data->floor_img; // Imagem do chão
            else if (data->map[y][x] == 'P')
                img_ptr = data->player_img; // Imagem do jogador
            else if (data->map[y][x] == 'C')
                img_ptr = data->collectible_img; // Imagem do item colecionável
            else if (data->map[y][x] == 'E')
                img_ptr = data->exit_img; // Imagem da saída

            // Se houver uma imagem correspondente, renderiza na janela
            if (img_ptr)
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, x * 32, y * 32);
        }
    }
}

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
