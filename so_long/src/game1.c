/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:19:45 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/31 14:30:16 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	move_player(t_data *data, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || \
	new_y >= data->height || new_x >= data->width)
		return ;
	if (data->map[new_y][new_x] != '1')
	{
		update_total_move(data);
		update_player_position(data, new_x, new_y);
		render_map(data);
	}
}

void	update_player_position(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] == 'C')
		data->remainder_colletible--;
	if (data->int_front_exit)
	{
		data->map[data->player_y][data->player_x] = 'E';
		data->int_front_exit = 0;
	}
	else if (data->map[new_y][new_x] == 'E')
	{
		if (data->remainder_colletible == 0)
			on_destroy(data);
		data->int_front_exit = 1;
		data->map[data->player_y][data->player_x] = '0';
	}
	else
		data->map[data->player_y][data->player_x] = '0';
	data->map[new_y][new_x] = 'P';
	data->player_x = new_x;
	data->player_y = new_y;
}

void	update_total_move(t_data *data)
{
	data->total_moves++;
	ft_printf("Total moves: %d\n", data->total_moves);
}

int	on_keypress(int keysym, t_data *data)
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
