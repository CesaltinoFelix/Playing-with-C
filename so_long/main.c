#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int main(void)
{
	char *map[] = {
		"1111111111111",
		"10010000000C1",
		"10C0011111001",
		"1P0011E00C001",
		"1111111111111"
	};
	t_data data;
	int w = 50;
	int *pw = &w;
	int h = 50;
	int *ph = &h; 
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 32*13, 32*5, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	int i = 0;
	int y = 0;
	void *img_ptr ;
	(void)map;
	while(i < 5)
	{	
		int j = 0;
		int x = 0;
		while(j < 13)
		{

			if(map[i][j] == '1')
			{
			img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/parede.xpm", pw, ph);
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, x, y);
			}
			else if(map[i][j] == '0')
			{
			img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/piso.xpm", pw, ph);
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, x, y);
			}
			else if(map[i][j] == 'P')
			{
			img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/6.xpm", pw, ph);
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, x, y);
			}
			else if(map[i][j] == 'C')
			{
			img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/Money.xpm", pw, ph);
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, x, y);
			}
			else if(map[i][j] == 'E')
			{
			img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/g1.xpm", pw, ph);
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, x, y);
			}
			x = x + 32;
			j++;
		}
		y = y + 32;

		i++;
	}

	// void *img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/Parede.xpm", pw, ph);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, x, 50);
	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	
	return (0);
}
