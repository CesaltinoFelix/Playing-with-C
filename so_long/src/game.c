#include "game.h"

void initialize_map(t_data *data)
{   
    int i = 0;
    int j = 0;

    data->height = 0;
    data->width = 0;
    char *map[] = {
        "1111111111111",
        "10010000000C1",
        "10C0011111001",
        "1PC011E00C001",
        "1111111111111",
        NULL
    };

    while (map[data->height] != NULL)
        data->height++;

    while (map[0][data->width] != '\0')
        data->width++;

    data->map = (char **)malloc((data->height) * sizeof(char *));
    if(!data->map)
        return ;
    while(i < data->height)
    {
        data->map[i] = (char *)malloc((data->width) * sizeof(char));
         if(!data->map[i])
            return ;
        
        j = 0;
        while(j < data->width)
        {
            data->map[i][j] = map[i][j];
            j++;
        }
        i++;
    }
}

void count_collectibles_and_get_positions(t_data *data) {
    int y = 0;
    while (y < data->height)
    {
        int x = 0;
        while (x < data->width)
        {
            if (data->map[y][x] == 'C')
                data->remainder_colletible++;
            else if(data->map[y][x] == 'P')
            {
                data->player_x = x;
                data->player_y = y;
            }
            x++;
        }
        y++;
    }
}

void initialize_data(t_data *data)
{
    initialize_map(data);
    data->remainder_colletible = 0;
    data->int_front_exit = 0;
    data->total_moves = 0;
    count_collectibles_and_get_positions(data);

}



void move_player(t_data *data, int new_x, int new_y)
{
    if (new_x < 0 || new_y < 0 || new_y >= 5 || new_x >= 13)
    {
        printf("Move out of bounds\n");
        return;
    }

    if (data->map[new_y][new_x] != '1')
    {
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
            data->map[data->player_y][data->player_x] = '0';

        }
        else
        data->map[data->player_y][data->player_x] = '0';
        data->map[new_y][new_x] = 'P';
        data->player_x = new_x;
        data->player_y = new_y;
       
        render_map(data);
    }
}

int on_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        on_destroy(data);
    else if (keysym == XK_w || keysym == XK_Up)
        move_player(data, data->player_x, data->player_y - 1);
    else if (keysym == XK_s || keysym == XK_Down)
        move_player(data, data->player_x, data->player_y + 1);
    else if (keysym == XK_a || keysym == XK_Left)
        move_player(data, data->player_x - 1, data->player_y);
    else if (keysym == XK_d || keysym == XK_Right)
        move_player(data, data->player_x + 1, data->player_y);
    return (0);
}

