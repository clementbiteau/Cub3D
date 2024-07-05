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

void set_image_pixel(t_img *img, int x, int y, int color)
{
    char *dst;

    if (x >= 0 && x < img->width && y >= 0 && y < img->height)
    {
        dst = (char *)img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}
