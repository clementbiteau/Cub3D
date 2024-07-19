#include "cub3d.h"

void init_coloring(t_coloring *coloring)
{
    coloring->north = NULL;
    coloring->south = NULL;
    coloring->east = NULL;
    coloring->west = NULL;
    coloring->floor = 0; 
    coloring->ceiling = 0;
    coloring->floor_in_hexa = 0x0;
    coloring->ceiling_in_hexa = 0x0;
    coloring->size = 0;  
    coloring->index = 0; 
    coloring->step = 0.0;
    coloring->pos = 0.0;
    coloring->x = 0;
    coloring->y = 0;
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		quit(data, ft_error(NULL, ERROR_ALLOC, 1));
	data->textures[NORTH] = xpm_to_img(data, data->coloring.north);
	data->textures[SOUTH] = xpm_to_img(data, data->coloring.south);
	data->textures[EAST] = xpm_to_img(data, data->coloring.east);
	data->textures[WEST] = xpm_to_img(data, data->coloring.west);
}
