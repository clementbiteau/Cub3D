#include "cub3d.h"

static bool check_file_existance(char *input)
{
    int fd;

    fd = open(input, O_RDONLY);
    if (fd < 0)
        return (false);
    else
    {
        return (true);
        close(fd);
    }
}

static bool is_cub(char *input)
{
    size_t  len;

    len = ft_strlen(input);
    if ((input[len - 1] != 'b') || (input[len - 2] != 'u')
        || (input[len - 3] != 'c') || (input[len - 4] != '.'))
        return (false);
    return (true);
}

static bool is_xpm(char *input)
{
    size_t  len;

    len = ft_strlen(input);
    if ((input[len - 1] != 'm') || (input[len - 2] != 'p')
        || (input[len - 3] != 'x') || (input[len - 4] != '.'))
        return (false);
    return (true);
}

int check_input(char *input)
{
    int fd;

    if (!is_cub(input) || check_file_existance(input))
        return (ft_error(input, ERROR_INPUT_ARGS, 1));
    fd = open(input, O_RDONLY);
    if (fd < 0)
        return (ft_error(input, strerror(errno), 1));
    close(fd);
    if (!is_cub(input))
        return (ft_error(input, ERROR_INPUT_CUB, 1));
    if (!is_xpm(input))
        return (ft_error(input, ERROR_INPUT_XPM, 1));
    return (0);
}
