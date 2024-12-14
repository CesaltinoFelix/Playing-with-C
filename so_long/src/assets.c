/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:24:14 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/31 14:28:27 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upload_assets(t_data *data)
{
	int	width;
	int	height;

	width = DEFAULT_ASSET_WIDTH;
	height = DEFAULT_ASSET_HEIGHT;
	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/wall.xpm", &width, &height);
	data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/floor.xpm", &width, &height);
	data->player_right_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/player_right.xpm", &width, &height);
	data->player_left_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/player_left.xpm", &width, &height);
	data->player_front_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/player_front.xpm", &width, &height);
	data->collectible_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/collectible.xpm", &width, &height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/exit.xpm", &width, &height);
	verify_upload(data);
}

void	verify_upload(t_data *data)
{
	if (!data->wall_img || !data->floor_img || \
	!data->player_right_img || !data->player_left_img || \
	!data->player_front_img || !data->collectible_img || \
	!data->exit_img)
	{
		ft_printf("Erro ao carregar imagens\n");
		on_destroy(data);
	}
}
