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

static void free_colorings(t_coloring *textures)
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
    if (data->mapper.fd > 0)
        close(data->mapper.fd);
    if (data->mapper.file)
        free_table((void **)data->mapper.file);
    if (data->map)
        free_table((void **)data->map);
}

int    free_data(t_data *data)
{
    if (data->textures)
        free_table((void **)data->textures);
    if (data->texture_pixels)
        free_table((void **)data->texture_pixels);
    free_colorings(&data->coloring);
    free_map(data);
    return (1);
}