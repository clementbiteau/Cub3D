#include "cub3d.h"

static int	forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * MOVEMENT_SPEED;
	new_y = data->player.pos_y + data->player.dir_y * MOVEMENT_SPEED;
	return (check_move(data, new_x, new_y));
}

static int	backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_x * MOVEMENT_SPEED;
	new_y = data->player.pos_y - data->player.dir_y * MOVEMENT_SPEED;
	return (check_move(data, new_x, new_y));
}

static int	left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_y * MOVEMENT_SPEED;
	new_y = data->player.pos_y - data->player.dir_x * MOVEMENT_SPEED;
	return (check_move(data, new_x, new_y));
}

static int	right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_y * MOVEMENT_SPEED;
	new_y = data->player.pos_y + data->player.dir_x * MOVEMENT_SPEED;
	return (check_move(data, new_x, new_y));
}

static int rotate_left_right(t_data *data, double rotspeed)
{
    t_player *p = &data->player;
    double tmp_x;

    tmp_x = p->dir_x;
    p->dir_x = p->dir_x * cos(rotspeed) - p->dir_y * sin(rotspeed);
    p->dir_y = tmp_x * sin(rotspeed) + p->dir_y * cos(rotspeed);

    tmp_x = p->plane_x;
    p->plane_x = p->plane_x * cos(rotspeed) - p->plane_y * sin(rotspeed);
    p->plane_y = tmp_x * sin(rotspeed) + p->plane_y * cos(rotspeed);

    return (1);
}

int rotate_player(t_data *data, double rotdir)
{
    double rotspeed = ROTATION_SPEED * rotdir;
    return (rotate_left_right(data, rotspeed));
}

int	moving(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved += forward(data);
	if (data->player.move_y == -1)
		moved += backward(data);
	if (data->player.move_x == -1)
		moved += left(data);
	if (data->player.move_x == 1)
		moved += right(data);
	if (data->player.rotate != 0)
		moved += rotate_player(data, data->player.rotate);
	return (moved);
}