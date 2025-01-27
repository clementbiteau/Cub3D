#include "cub3d.h"

static int	ft_pressed(int pressed, t_data *data)
{
	if (pressed == ESCAPE_KEY)
		exit_game(data);
	if (pressed == W_KEY && data->player.move_y == 1)
		data->player.move_y = 0;
	if (pressed == S_KEY && data->player.move_y == -1)
		data->player.move_y = 0;
	if (pressed == A_KEY && data->player.move_x == -1)
		data->player.move_x += 1;
	if (pressed == D_KEY && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (pressed == LEFT_ARROW_KEY && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (pressed == RIGHT_ARROW_KEY && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}

static int	ft_released(int pressed, t_data *data)
{
	if (pressed == ESCAPE_KEY)
		exit_game(data);
	if (pressed == W_KEY && data->player.move_y == 1)
		data->player.move_y = 0;
	if (pressed == S_KEY && data->player.move_y == -1)
		data->player.move_y = 0;
	if (pressed == A_KEY && data->player.move_x == -1)
		data->player.move_x += 1;
	if (pressed == D_KEY && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (pressed == LEFT_ARROW_KEY && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (pressed == RIGHT_ARROW_KEY && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}

static void wrap_mouse_position(t_data *data, int x, int y)
{
    Display *display;
    Window root;

    if (x >= data->win_width - MOUSE_MOVEMENT)
    {
        x = MOUSE_MOVEMENT;
        display = XOpenDisplay(NULL);
        if (display)
        {
            root = DefaultRootWindow(display);
            XWarpPointer(display, None, root, 0, 0, 0, 0, x, y);
            XCloseDisplay(display);
        }
    }
    else if (x <= MOUSE_MOVEMENT)
    {
        x = data->win_width - MOUSE_MOVEMENT;
        display = XOpenDisplay(NULL);
        if (display)
        {
            root = DefaultRootWindow(display);
            XWarpPointer(display, None, root, 0, 0, 0, 0, x, y);
            XCloseDisplay(display);
        }
    }
}

static int mouse_motion_handler(int x, int y, t_data *data)
{
    static int old_x = WIN_WIDTH / 2;

    wrap_mouse_position(data, x, y);
    if (x == old_x)
        return (0);
    else if (x < old_x)
        data->player.has_moved += rotate_player(data, -1);
    else if (x > old_x)
        data->player.has_moved += rotate_player(data, 1);
    old_x = x;
    return (0);
}

void	await_instructions(t_data *data)
{
	mlx_hook(data->window, ClientMessage, NoEventMask, exit_game, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_pressed, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_released, data);
	mlx_hook(data->window, MotionNotify, PointerMotionMask,
			mouse_motion_handler, data);
}
