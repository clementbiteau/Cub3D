#include "cub3d.h"

void init_coloring(t_coloring *shades)
{
    shades->north = NULL;
    shades->south = NULL;
    shades->west = NULL;
    shades->east = NULL;
    shades->floor = 0; 
    shades->ceiling = 0;
    shades->floor_in_hexa = 0x0;
    shades->ceiling_in_hexa = 0x0;
    shades->size = 0;  
    shades->index = 0; 
    shades->step = 0.0;
    shades->pos = 0.0;
    shades->x = 0;
    shades->y = 0;
}
