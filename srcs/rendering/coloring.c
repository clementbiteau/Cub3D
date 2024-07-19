#include "cub3d.h"

void	init_texture_pixels(t_data *data)
{
	int	i;

	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(data->win_height + 1,
			sizeof * data->texture_pixels);
	if (!data->texture_pixels)
		clean_exit(data, err_msg(NULL, ERROR_ALLOC, 1));
	i = 0;
	while (i < data->win_height)
	{
		data->texture_pixels[i] = ft_calloc(data->win_width + 1,
				sizeof * data->texture_pixels);
		if (!data->texture_pixels[i])
			clean_exit(data, err_msg(NULL, ERROR_ALLOC, 1));
		i++;
	}
}

static void	get_texture_index(t_data *data, t_ray *ray)
{
	if (ray->vert_or_horiz == 0)
	{
		if (ray->ray_dir_x < 0)
			data->coloring.index = WEST;
		else
			data->coloring.index = EAST;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			data->coloring.index = SOUTH;
		else
			data->coloring.index = NORTH;
	}
}

void	update_texture_pixels(t_data *data, t_coloring *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(data, ray);
	tex->x = (int)(ray->dist_to_wall_x * tex->size);
	if ((ray->vert_or_horiz == 0 && ray->ray_dir_x < 0)
		|| (ray->vert_or_horiz == 1 && ray->ray_dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->wall_height;
	tex->pos = (ray->cast_start - data->win_height / 2
			+ ray->wall_height / 2) * tex->step;
	y = ray->cast_start;
	while (y < ray->cast_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = data->textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->texture_pixels[y][x] = color;
		y++;
	}
}