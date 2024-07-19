#include "cub3d.h"

void init_coloring(t_coloring *coloring)
{
    coloring->north = NULL;
    coloring->south = NULL;
    coloring->east = NULL;
    coloring->west = NULL;
    coloring->floor = 0; 
    coloring->ceiling = 0;
    coloring->floor_in_hexa = 0x0;
    coloring->ceiling_in_hexa = 0x0;
    coloring->size = 0;  
    coloring->index = 0; 
    coloring->step = 0.0;
    coloring->pos = 0.0;
    coloring->x = 0;
    coloring->y = 0;
}
