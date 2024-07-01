#include "cub3d.h"

bool    only_digit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (false);
        i++;
    }
    return (true);
}

bool    is_spaces(char c)
{
    if (c != ' ' && c != '\t' && c != '\n'
        && c != '\r' && c != '\v' && c != '\f')
        return (false);
    return (true);
}