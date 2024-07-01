#include "cub3d.h"

static int  input_handler(int pressed, t_data *data)
{
    if (pressed == XK_Right)
        data->player.rotate += 1;
    if (pressed == XK_Left)
        data->player.rotate -= 1;
    if (pressed == XK_w)
        data->player.move_y += 1;
    if (pressed == XK_s)
        data->player.move_y -= 1;
    if (pressed == XK_a)
        data->player.move_x -= 1;
    if (pressed == XK_d)
        data->player.move_x += 1;
    if (pressed == XK_Escape)
        exit_game(data);
    return (SUCCESS);
}

static int	ft_pressed(int pressed, t_data *data)
{
	if (pressed == XK_Escape)
		exit_game(data);
	if (pressed == XK_w && data->player.move_y == 1)
		data->player.move_y = 0;
	if (pressed == XK_s && data->player.move_y == -1)
		data->player.move_y = 0;
	if (pressed == XK_a && data->player.move_x == -1)
		data->player.move_x += 1;
	if (pressed == XK_d && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (pressed == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (pressed == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (SUCCESS);
}

static int	ft_released(int pressed, t_data *data)
{
	if (pressed == XK_Escape)
		exit_game(data);
	if (pressed == XK_w && data->player.move_y == 1)
		data->player.move_y = 0;
	if (pressed == XK_s && data->player.move_y == -1)
		data->player.move_y = 0;
	if (pressed == XK_a && data->player.move_x == -1)
		data->player.move_x += 1;
	if (pressed == XK_d && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (pressed == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (pressed == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (SUCCESS);
}

static void wrap_mouse_position(t_data *data, int x, int y)
{
    if (x >= data->win_width - MOUSE_MOVE)
    {
        x = MOUSE_MOVE;
        mlx_mouse_move(data->mlx, data->window, x, y);
    }
    else if (x <= MOUSE_MOVE)
    {
        x = data->win_width - MOUSE_MOVE;
        mlx_mouse_move(data->mlx, data->window, x, y);
    }
}

static int	mouse_motion_handler(int x, int y, t_data *data)
{
	static int	old_x = WIN_WIDTH / 2;

	wrap_mouse_position(data, x, y);
	if (x == old_x)
		return (0);
	else if (x < old_x)
		data->player.has_moved += rotate_player(data, -1);
	else if (x > old_x)
		data->player.has_moved += rotate_player(data, 1);
	old_x = x;
	return (SUCCESS);
}

void	listen_for_input(t_data *data)
{
	mlx_hook(data->window, ClientMessage, NoEventMask, exit_game(), data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_pressed, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_released, data);
}