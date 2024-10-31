/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:29 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/31 14:51:56 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_data(t_data *data, char *map)
{
	initialize_map(data, map);
	data->remainder_colletible = 0;
	data->int_front_exit = 0;
	data->total_moves = 0;
	data->player_view_direction = RIGHT;
	count_collectibles_and_get_positions(data);
}

void	count_collectibles_and_get_positions(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == 'C')
				data->remainder_colletible++;
			else if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			x++;
		}
		y++;
	}
}
