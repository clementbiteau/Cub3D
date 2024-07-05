#include "cub3d.h"

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->window = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	data->map = NULL;
	data->texture_pixels = NULL;
	data->textures = NULL;
	init_player(&data->player);
	init_texinfo(&data->coloring);
	init_mapper(&data->mapper);
	init_img_clean(&data->minimap);
	init_raycast(&data->ray);
}
