#include "cub3d.h"

static bool is_not_wall(t_data *data, double x, double y)
{
    return (data->map[(int)y][(int)x] == '0');
}

static bool is_within_bounds(t_data *data, double x, double y)
{
    return (x >= 0.25 && x < data->mapper.width - 0.25 &&
            y >= 0.25 && y < data->mapper.height - 0.25);
}

static bool is_ok_to_move(t_data *data, double x, double y)
{
    return (is_within_bounds(data, x, y) && is_not_wall(data, x, y));
}

int    check_move(t_data *data, double next_x, double next_y)
{
    int movement;

    movement = 0;
    if (is_ok_to_move(data, next_x, data->player.pos_y))
    {
        data->player.pos_x += next_x;
        movement = 1;
    }
    if (is_ok_to_move(data, data->player.pos_x, next_y))
    {
        data->player.pos_y += next_y;
        movement = 1;
    }
    return (movement);
}