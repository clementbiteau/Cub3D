#include "cub3d.h"

void    free_table(void **tab)
{
    size_t  i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    if (tab)
    {
        free(tab);
        tab = NULL;
    }
}

static void free_textures(t_texture_info *textures)
{
    if (textures->north)
        free(textures->north);
    if (textures->south)
        free(textures->south);
    if (textures->east)
        free(textures->east);
    if (textures->west)
        free(textures->west);
    if (textures->ceiling)
        free(textures->ceiling);
    if (textures->floor)
        free(textures->floor);
}

static void free_map(t_data *data)
{
    
}

void    free_data(t_data *data)
{

}