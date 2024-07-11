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

static void update_ray_position(t_ray *ray)
{
    if (ray->dist_to_wall_x < ray->dist_to_wall_y)
    {
        ray->dist_to_wall_x += ray->dist_on_delta_x;
        ray->map_x += ray->step_x;
        ray->vert_or_horiz = 0; // Vertical wall hit
    }
    else
    {
        ray->dist_to_wall_y += ray->dist_on_delta_y;
        ray->map_y += ray->step_y;
        ray->vert_or_horiz = 1; // Horizontal wall hit
    }
}

static int check_hit(t_data *data, t_ray *ray)
{
    if (ray->map_y < 0.25 || ray->map_x < 0.25 ||
        ray->map_y > data->mapper.height - 0.25 ||
        ray->map_x > data->mapper.width - 1.25)
        return 1;
    else if (data->mapper.file[ray->map_y][ray->map_x] > '0')
        return 1;
    return 0;
}

static void do_digital_differential_analyser(t_data *data, t_ray *ray)
{
    while (ray->wall_hit == 0)
    {
        update_ray_position(ray);
        ray->wall_hit = check_hit(data, ray);
    }
}

