#include "game.h"



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

