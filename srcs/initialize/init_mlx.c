#include "cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		quit(data, ft_error("mlx", ERROR_NO_MLX, 1));
	data->window = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->window)
		quit(data, ft_error("mlx", ERROR_MLX_AFF, 1));
	return ;
}