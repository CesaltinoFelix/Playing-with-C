/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:02:42 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/31 14:30:28 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 1)
		return (ft_printf("Error: ./so_long <map_path/*.ber>"), 1);
	initialize_data(&data, argv[1]);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 32 * data.width, \
	32 * data.height, "So_long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	upload_assets(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, \
	StructureNotifyMask, &on_destroy, &data);
	render_map(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
