#include "cub3d.h"

void    init_ray(t_ray *ray)
{
    ray->camera_x = 0;
    ray->ray_dir_x = 0;
    ray->ray_dir_y = 0;
    ray->map_x = 0;
    ray->map_y = 0;
    ray->side_dist_x = 0;
    ray->side_dist_y = 0;
    ray->delta_dist_x = 0;
    ray->delta_dist_y = 0;
    ray->perp_wall_dist = 0;
    ray->step_x = 0;
    ray->step_y = 0;
    ray->wall_hit = 0;
    ray->vert_or_horiz = 0;
}

void    init_raycasting(int x, t_ray *ray, t_player *player)
{
    init_ray(ray);
    ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}