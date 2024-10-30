#include "so_long.h"

void initialize_map(t_data *data, char *map_path)
{       	
    data->height = 0;
    data->width = 0;

if (open(map_path, O_RDONLY) > 0 && validate_extension(&map_path[strlen(map_path) - 4]))
    {
        display(open(map_path, O_RDONLY), data);
        validate_lines(open(map_path, O_RDONLY), data);
        create_map(open(map_path, O_RDONLY), data);

    if (!validate_map(data)) 
    {
        printf("Mapa não é válido.\n");
        exit(1);
    }
    }
}
void create_map(int fd, t_data *data)
{
    int i = 0;
    int j = 0;
    int bit = 0;

    data->map = (char **)malloc((data->height) * sizeof(char *));
    if(!data->map)
        return ;
   
    while(i < data->height)
    {
        data->map[i] = (char *)malloc((data->width) * sizeof(char));
        if(!data->map[i])
            return ;
        i++;
    }

    i = 0;
    while(i < data->height)
    {
        j = 0;
            while (read(fd, &bit, 1) > 0) {
            if(bit == '\n')
                break;
            if (bit != '0' && bit != 'E' && bit != 'C' && bit != 'P' && bit != '1')
            {
                free_map(data);
                printf("Há algum objeto inválido no mapa: '%c'\n", bit);
                exit(1);
            }
            data->map[i][j] = bit;
            j++;
        }
        i++;
    }
    close(fd);
}

void	display(int fd, t_data *data)
{
	char	bit;
	int		width;
	int		height;
	int		fline;

	width = 0;
	height = 0;
	fline = 0;
	while (read(fd, &bit, 1) != 0)
	{
		if (bit != '\n')
		{
			if (fline == 0)
				width++;
		}
		else
		{
			height++;
			fline = 1;
		}
	}
	data->width = width;
	data->height = height;
	close(fd);
}

void move_player(t_data *data, int new_x, int new_y)
{
    if (new_x < 0 || new_y < 0 || new_y >= data->height || new_x >= data->width)
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
                on_destroy(data);
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
    {
        data->player_view_direction = RIGHT;
        move_player(data, data->player_x, data->player_y - 1);
    }
    else if (keysym == XK_s || keysym == XK_Down)
    {
        data->player_view_direction = FRONT;
        move_player(data, data->player_x, data->player_y + 1);
    }
    else if (keysym == XK_a || keysym == XK_Left)
    {
        data->player_view_direction = LEFT;
        move_player(data, data->player_x - 1, data->player_y);

    }
    else if (keysym == XK_d || keysym == XK_Right)
    {
        data->player_view_direction = RIGHT;
        move_player(data, data->player_x + 1, data->player_y);
    }
    return (0);
}

