/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:29 by cefelix           #+#    #+#             */
/*   Updated: 2024/11/01 10:55:28 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**allocate_map_copy(int height, int width)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(height * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = (char *)malloc((width + 1) * sizeof(char));
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

void	copy_map_content(char **copy, char **original, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			copy[i][j] = original[i][j];
			j++;
		}
		copy[i][width] = '\0';
		i++;
	}
}

char	**copy_map(char **original, int height, int width)
{
	char	**copy;

	copy = allocate_map_copy(height, width);
	if (!copy)
		return (NULL);
	copy_map_content(copy, original, height, width);
	return (copy);
}

void	free_map_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
