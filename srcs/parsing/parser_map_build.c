#include "cub3d.h"

static bool check_walls(char **map, int row)
{
    int j;

    j = 0;
    if (!map || !map[row] || map[row][j])
        return (false);
    while (is_spaces(map[row][j]))
        j++;
    while (map[row][j])
    {
        if (map[row][j] != '1')
            return (false);
        j++;
    }
    return (true);
}

bool    check_map_build(t_mapinfo *map_info, char **map)
{
    int i;
    int j;
    int width;

    if (check_walls(map, 0) == false)
        return (false);
    i = 1;
    while (i < map_info->height - 1)
    {
        j = 0;
        width = ft_strlen(map[i]);
        while (is_spaces(map[i][j]))
            j++;
        if (map[i][j] != '1')
            return (false);
        if (map[i][width -1] != '1')
            return (false);
        i++;
    }
    if (!check_walls(map, map_info->height - 1))
        return (false);
    return (true);
}