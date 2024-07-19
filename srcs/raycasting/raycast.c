#include "cub3d.h"

static void	calculate_wall_height(t_ray *ray, t_data *data, t_player *player)
{
	if (ray->vert_or_horiz == 0)
		ray->wall_dist = (ray->dist_to_wall_y - ray->dist_on_delta_x);
	else
		ray->wall_dist = (ray->dist_to_wall_y - ray->dist_on_delta_y);
	ray->wall_height = (int)(data->win_height / ray->wall_dist);
	ray->cast_start = -(ray->wall_height) / 2 + data->win_height / 2;
	if (ray->cast_start < 0)
		ray->cast_start = 0;
	ray->cast_end = ray->wall_height / 2 + data->win_height / 2;
	if (ray->cast_end >= data->win_height)
		ray->cast_end = data->win_height - 1;
	if (ray->vert_or_horiz == 0)
		ray->dist_to_wall_x = player->pos_y + ray->wall_dist * ray->ray_dir_y;
	else
		ray->dist_to_wall_x = player->pos_x + ray->wall_dist * ray->ray_dir_x;
	ray->dist_to_wall_x -= floor(ray->dist_to_wall_x);
}

int raycasting(t_player *player, t_data *data)
{
    t_ray   ray;
    int x;

    x = 0;
    ray = data->ray;
    while (x < data->win_width)
    {
        init_raycasting(x, &ray, player);
        set_dda(&ray, player);
        do_dda(data, &ray);
		calculate_wall_height(&ray, data, player);
		update_texture_pixels(data, &data->coloring, &ray, x);
        x++;
    }
    return (0);
}