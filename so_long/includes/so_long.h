/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:04:16 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/31 14:46:41 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <fcntl.h>

# define WALL '1'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define EMPTY '0'

# define FRONT 'F'
# define LEFT 'L'
# define RIGHT 'R'
# define BACK 'B'

# define DEFAULT_ASSET_WIDTH 32
# define DEFAULT_ASSET_HEIGHT 32

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		player_x;
	int		player_y;
	void	*wall_img;
	void	*floor_img;
	void	*player_right_img;
	void	*player_left_img;
	void	*player_front_img;
	void	*collectible_img;
	char	player_view_direction;
	void	*exit_img;
	int		total_collectible_get;
	int		remainder_colletible;
	int		int_front_exit;
	int		total_moves;
	int		height;
	int		width;
}	t_data;

void	initialize_data(t_data *data, char *map);
void	render_map(t_data *data);
int		on_keypress(int keysym, t_data *data);
int		on_destroy(t_data *data);
void	display(int fd, t_data *data);
void	print_map(t_data *data);
void	move_player(t_data *data, int new_x, int new_y);
void	count_collectibles_and_get_positions(t_data *data);
void	free_map(t_data *data);
void	free_assets(t_data *data);
int		validate_extension(char *extension);
void	create_map(int fd, t_data *data);
int		validate_map(t_data *data);
int		validate_lines(int fd, t_data *data);
void	initialize_map(t_data *data, char *map_path);
void	upload_assets(t_data *data);
void	fill_map(t_data *data, int fd);
void	verify_upload(t_data *data);
void	update_total_move(t_data *data);
void	update_player_position(t_data *data, int new_x, int new_y);
void	*get_right_img(t_data *data, int y, int x);

#endif // SO_LONG_H
