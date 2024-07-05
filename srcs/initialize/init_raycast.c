#include "cub3d.h"

void    init_raycast(t_ray *ray)
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