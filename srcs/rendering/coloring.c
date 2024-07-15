#include "cub3d.h"

static void color_by_dir(t_data *data, t_ray *ray)
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

