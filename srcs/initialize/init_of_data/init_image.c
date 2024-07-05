#include "cub3d.h"

void    re_init_image(t_img *image)
{
    image->img = NULL;
	image->addr = NULL;
	image->width = 0;
	image->height = 0;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
}