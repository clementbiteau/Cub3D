#include "cub3d.h"

static void pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = (char *)img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

static void render_frame(t_player *player, t_data *mlx, t_coloring *color)
{

}