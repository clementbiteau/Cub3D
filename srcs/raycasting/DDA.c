#include "cub3d.h"

/**
 * The DDA (Digital Differential Analyzer) is a common and productive algorithm
 * that is was used for 3D games like Wolfenstein 3D.
 * It virtualy draws a line (a segment) between 2 distinct points.
 * The starting point is the player's position of the axis x,y,
 * and will calculate therefore the distance between those 2 points.
 * The calculation of such goes through the line storing the number of
 * vertical and horizontal lines crossed when the segment is being cast.
 * This segment is called -> a RAY -> RAYCASTING.
 * 
 * This DDA makes a 2D plane render a 3D print because it evaluates in some sorts
 * the empty distance to the next wall.
 * In our game, the player is the starting point.
 * Within his vision, the player will see walls at a distance.
 * The further the wall or object, the smaller they will be represented
 * and thus rendering a more realistic in-depth vision.
*/

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
        ray->vert_or_horiz = 0;
    }
    else
    {
        ray->dist_to_wall_y += ray->dist_on_delta_y;
        ray->map_y += ray->step_y;
        ray->vert_or_horiz = 1;
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

void perform_dda(t_data *data, t_ray *ray)
{
    while (ray->wall_hit == 0)
    {
        update_ray_position(ray);
        ray->wall_hit = check_hit(data, ray);
    }
}
