// include/game.h

#ifndef GAME_H
#define GAME_H

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <unistd.h>
#include <string.h>

typedef struct s_data
{
    void *mlx_ptr;            
    void *win_ptr;            
    char map[5][14];          
    int player_x;             
    int player_y;             
    void *wall_img;           
    void *floor_img;          
    void *player_img;         
    void *collectible_img;    
    void *exit_img;           
    int total_collectible_get;
    int remainder_colletible;
    int int_front_exit;
    int total_moves;
} t_data;

void initialize_data(t_data *data);
void render_map(t_data *data);
int on_keypress(int keysym, t_data *data);
int on_destroy(t_data *data);
void move_player(t_data *data, int new_x, int new_y);
int count_collectibles(t_data *data);

#endif // GAME_H
