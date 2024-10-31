/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:22:35 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/31 11:56:11 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_data *data)
{
	int		y;
	int		x;
	void	*img_ptr;

	y = 0;
	img_ptr = NULL;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			img_ptr = get_right_img(data, y, x);
			if (img_ptr)
				mlx_put_image_to_window(data->mlx_ptr, \
			data->win_ptr, img_ptr, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	*get_right_img(t_data *data, int y, int x)
{
	if (data->map[y][x] == WALL)
		return (data->wall_img);
	else if (data->map[y][x] == EMPTY)
		return (data->floor_img);
	else if (data->map[y][x] == PLAYER)
	{
		if (data->player_view_direction == FRONT)
			return (data->player_front_img);
		else if (data->player_view_direction == RIGHT)
			return (data->player_right_img);
		else if (data->player_view_direction == LEFT)
			return (data->player_left_img);
		else
			return (data->player_right_img);
	}
	else if (data->map[y][x] == COLLECTIBLE)
		return (data->collectible_img);
	else if (data->map[y][x] == EXIT)
		return (data->exit_img);
	return (NULL);
}
