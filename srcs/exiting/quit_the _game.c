#include "cub3d.h"

int quit(t_data *data, int exit_code)
{
    if (!data)
        exit(exit_code);
    if (data->window && data->mlx)
        mlx_destroy_window(data->mlx, data->window);
    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        mlx_loop_end(data->mlx);
        free(data->mlx);
    }
    free_data(data);
    exit(exit_code);
}

int exit_game(t_data *data)
{
    clean_exit(data, 0);
    return (0);
}

int    ft_error(char *why, char *str, int exit_code)
{
    ft_putstr_fd("CUB3D - Error", 2);
    if (why)
    {
        ft_putstr_fd(": ", 2);
        ft_putstr_fd(why, 2);
    }
    if (str)
    {
        ft_putstr_fd(": ", 2);
        ft_putstr_fd(str, 2);
    }
    ft_putstr_fd("\n" RESET, 2);
    return (exit_code);
}