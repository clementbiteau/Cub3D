#include "cub3d.h"

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
        // ICI NOUS DEVONS IMPLEMENTER LE COLORING
        x++;
    }
    return (0);
}