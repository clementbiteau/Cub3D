#include "cub3d.h"

int raycasting(t_player *player, t_data *data)
{
    t_ray   ray;
    int x;

    x = 0;
    ray = data->ray;
    while (x < data->win_width)
    {
        init_raycating(x, &ray, player);
        set_dda(&ray, player);
        perform_dda(data, &ray);
        raycast_preparation(&ray, data, player);
        coloring(data, &data->textures, &ray, x);
        x++;
    }
    return (0);
}