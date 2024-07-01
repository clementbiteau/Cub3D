#include "cub3d.h"

int    ft_error(char *why, char *str, int exit_code)
{
    ft_putstr_fd("CUB3D - Error", 2)
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
