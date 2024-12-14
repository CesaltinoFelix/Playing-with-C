/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:29 by cefelix           #+#    #+#             */
/*   Updated: 2024/11/01 10:57:17 by cefelix          ###   ########.fr       */
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

void	flood_fill(char **matriz, int x, int y, int *found)
{
	if (matriz[x][y] == 'P')
	{
		*found = 1;
		return ;
	}
	if (matriz[x][y] == '1' || matriz[x][y] == 'V')
		return ;
	matriz[x][y] = 'V';
	flood_fill(matriz, x + 1, y, found);
	flood_fill(matriz, x - 1, y, found);
	flood_fill(matriz, x, y + 1, found);
	flood_fill(matriz, x, y - 1, found);
}

int	check_flood_fill(char **map_copy, char target, t_data *data)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (map_copy[i][j] == target)
			{
				found = 0;
				flood_fill(map_copy, i, j, &found);
				if (found == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_path_valid(char **map, char target, t_data *data)
{
	char	**map_copy;
	int		is_valid;

	map_copy = copy_map(map, data->height, data->width);
	if (!map_copy)
		return (0);
	is_valid = check_flood_fill(map_copy, target, data);
	free_map_copy(map_copy, data->height);
	return (is_valid);
}
