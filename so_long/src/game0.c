/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:19:06 by cefelix           #+#    #+#             */
/*   Updated: 2024/11/01 10:57:30 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_data *data, char *map_path)
{
	data->height = 0;
	data->width = 0;
	if (open(map_path, O_RDONLY) > 0 && \
	validate_extension(&map_path[ft_strlen(map_path) - 4]))
	{
		display(open(map_path, O_RDONLY), data);
		validate_lines(open(map_path, O_RDONLY), data);
		create_map(open(map_path, O_RDONLY), data);
		if (!validate_map(data))
		{
			ft_printf("Mapa não é válido.\n");
			exit(1);
		}
		is_playable(data);
	}
	else
	{
		ft_printf("Error: Invalid file.\n");
		exit(1);
	}
}

void	is_playable(t_data *data)
{
	if (!is_path_valid(data->map, 'C', data) || \
	!is_path_valid(data->map, 'E', data))
	{
		free_map(data);
		ft_printf("Mapa inválido\n");
		exit(1);
	}
}

void	create_map(int fd, t_data *data)
{
	int	i;

	i = 0;
	data->map = (char **)malloc((data->height) * sizeof(char *));
	if (!data->map)
		return ;
	while (i < data->height)
	{
		data->map[i] = (char *)malloc((data->width) * sizeof(char));
		if (!data->map[i])
			return ;
		i++;
	}
	fill_map(data, fd);
	close(fd);
}

void	fill_map(t_data *data, int fd)
{
	int	i;
	int	j;
	int	bit;

	i = -1;
	j = 0;
	bit = 0;
	while (++i < data->height)
	{
		j = 0;
		while (read(fd, &bit, 1) > 0)
		{
			if (bit == '\n')
				break ;
			if (bit != '0' && bit != 'E' && bit != 'C' && \
			bit != 'P' && bit != '1')
			{
				free_map(data);
				ft_printf("Há algum objeto inválido no mapa: '%c'\n", bit);
				exit(1);
			}
			data->map[i][j] = bit;
			j++;
		}
	}
}
