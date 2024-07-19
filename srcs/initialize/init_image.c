#include "cub3d.h"

void    re_init_image(t_img *image)
{
    image->img = NULL;
	image->addr = NULL;
	image->width = 0;
	image->height = 0;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
}

void	init_img(t_data *data, t_img *image, int width, int height)
{
	re_init_image(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
		quit(data, ft_error("mlx", ERROR_MLX, 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	return ;
}