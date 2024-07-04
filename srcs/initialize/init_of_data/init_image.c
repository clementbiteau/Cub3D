#include "cub3d.h"

void    re_init_image(t_img *image)
{
    image->img = NULL;
	image->addr = NULL;
	image->pixel_bits = 0;
	image->size_line = 0;
}