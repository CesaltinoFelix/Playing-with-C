/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:56:34 by cefelix           #+#    #+#             */
/*   Updated: 2024/11/03 19:55:45 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_walls(t_data *data)
{
	int	i;

	if (data->height <= 0 || data->width <= 0)
		return (0);
	i = 0;
	while (i < data->width)
	{
		if (data->map[0][i] != WALL || data->map[data->height - 1][i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < data->height)
	{
		if (data->map[i][0] != WALL || data->map[i][data->width - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	has_required_elements(t_data *data, int *player_count,
		int *exit_count, int *collectible_count)
{
	int	i;
	int	j;

	*player_count = 0;
	*exit_count = 0;
	*collectible_count = 0;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == PLAYER)
				(*player_count)++;
			else if (data->map[i][j] == EXIT)
				(*exit_count)++;
			else if (data->map[i][j] == COLLECTIBLE)
				(*collectible_count)++;
			j++;
		}
		i++;
	}
	return (*player_count == 1 && *exit_count == 1 && *collectible_count >= 1);
}

int	validate_map(t_data *data)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;

	if (!data || !data->map)
		return (0);
	if (!has_walls(data))
	{
		free_map(data);
		ft_printf("Erro: As bordas do mapa não estão rodeadas de paredes.\n");
		return (0);
	}
	if (!has_required_elements(data, &player_count, \
	&exit_count, &collectible_count))
	{
		free_map(data);
		ft_printf("Erro: O mapa deve conter 1 jogador, pelo menos 1 saída e ");
		ft_printf("pelo menos 1 colecionável.\n");
		return (0);
	}
	return (1);
}

int	validate_extension(char *extension)
{
	if (ft_strncmp(extension, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	validate_lines(int fd, t_data *data)
{
	char	bit;
	int		width;

	width = 0;
	while (read(fd, &bit, 1) != 0)
	{
		if (bit == '\n')
		{
			if (width != data->width)
			{
				ft_printf("Error: Verifica o mapa!\n");
				exit(1);
			}
			width = 0;
		}
		else
			width++;
	}
	close(fd);
	return (0);
}
