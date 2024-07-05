#include "cub3d.h"

void init_minimap(t_minimap *minimap, char **map, int tile_size)
{
    minimap->map = map;
    minimap->tile_size = tile_size;
    minimap->size = 0;
    while (map[minimap->size])
        minimap->size++;
}
