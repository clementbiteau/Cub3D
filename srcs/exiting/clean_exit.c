#include "cub3d.h"

int clean_exit(t_data *data, int exit_code)
{
    if (!data)
        exit(exit_code);
    if (data->window && data->mlx)
        mlx_destroy_window(data->mlx, data->window);
    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        mlx_loop_end(data->mlx);
        free(daata->mlx);
    }
    free_data(data);
    exit(exit_code);
}

int exit_game(t_data *data)
{
    clean_exit(data, 0);
    return (0);
}