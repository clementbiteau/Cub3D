#include "cub3d.h"

static void set_tiles_for_minimap(t_img *img, int x, int y, int tile_size, int color)
{
    int i;
    int j;

    i = 0;
    while (i < tile_size)
    {
        j = 0;
        while (j < tile_size)
        {
            set_image_pixel(img, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

static void build_minimap_contour(t_minimap *mini, int x, int y)
{
    char    tile;
    int     color;

    tile = mini->map[y][x];
    if (tile == 'P')
        color = MINI_MAP_PLAYER;
    else if (tile == '1')
        color = MINI_MAP_WALL;
    else if (tile == '0')
        color = MINI_MAP_FLOOR;
    else
        color = MINI_MAP_SPACE;
    set_tiles_for_minimap(&mini->img, x * mini->tile_size, y * mini->tile_size, mini->tile_size, color);
}

static void build_minimap_borders(t_minimap *mini, int color)
{
    int size;
    int x;
    int y;

    size = MINI_MAP_PIXEL_SIZE + mini->tile_size;
    y = 0;
    while (y < size)
    {
        x = 0;
        while (x <= size)
        {
            if (x < 5 || x > size - 5 || y < 5 || y > size - 5)
                set_image_pixel(&mini->img, x, y , color);
            x++;
        }
        y++;
    }
}

static void minimap_builder(t_minimap *minimap)
{
    int y;
    int x;

    y = 0;
    while (y < minimap->tile_size)
    {
        if (!minimap->map[y])
            break;
        x = 0;
        while (x < minimap->tile_size)
        {
            if (!minimap->map[y][x])
                break;
            build_minimap_contour(minimap, x, y);
            x++;
        }
        y++;
    }
    build_minimap_borders(minimap, MINI_MAP_BORDERS);
}

void make_minimap(t_data *data, t_minimap *minimap)
{
    int img_size;
    
    img_size = MINI_MAP_PIXEL_SIZE + minimap->tile_size;

    init_img(data, &data->minimap, img_size, img_size);
    minimap_builder(minimap);
    mlx_put_image_to_window(data->mlx, data->window, data->minimap.img, minimap->tile_size, data->win_height - (MINI_MAP_PIXEL_SIZE + (minimap->tile_size * 2)));
    mlx_destroy_image(data->mlx, data->minimap.img);
}
