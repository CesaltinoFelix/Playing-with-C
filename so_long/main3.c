#include "mlx/mlx.h"
#include <stdlib.h>

typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
} t_data;

int main(void)
{
    t_data data;

    // Inicializa a MiniLibX
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);

    // Cria uma nova janela
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Exibir String");
    if (!data.win_ptr)
        return (free(data.mlx_ptr), 1);

    // Define a cor do texto (branco, por exemplo)
    int color = 0xFFD603;

    // Exibe a string "Olá, MiniLibX!" na posição (50, 50) da janela
    mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 50, color, "Olá, MiniLibX!");
	color = 0xFF0000;
    mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 50, color, " E Olá, Cesaltino Felix!");
    // Mantém a janela aberta até que o usuário a feche
    mlx_loop(data.mlx_ptr);

    return (0);
}
