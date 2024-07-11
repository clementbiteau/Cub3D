#include "cub3d.h"

static void set_dda_x(t_ray *ray, t_player *player)
{
    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->dist_to_wall_x = (player->pos_x - ray->map_x) * ray->dist_on_delta_x;
    }
    else
    {
        ray->step_x = 1;
        ray->dist_to_wall_x = (player->pos_x + 1.0 - ray->map_x) * ray->dist_on_delta_x;
    }
}

static void set_dda_y(t_ray *ray, t_player *player)
{
    if (ray->ray_dir_x < 0)
    {
        ray->step_y = -1;
        ray->dist_to_wall_y = (player->pos_y - ray->map_y) * ray->dist_on_delta_y;
    }
    else
    {
        ray->step_y = 1;
        ray->dist_to_wall_y = (player->pos_y + 1.0 - ray->map_y) * ray->dist_on_delta_y;
    }
}

static void set_dda(t_ray *ray, t_player *player)
{
    set_dda_x(ray, player);
    set_dda_y(ray, player);
}

static void do_dda_step(t_ray *ray)
{

}