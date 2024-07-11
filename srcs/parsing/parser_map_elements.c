#include "cub3d.h"

static int check_map_garnish(t_data *data, char **map)
{
    int i;
    int j;

    i = 0;
    data->player.dir = '0';
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j])
        {
            while (is_spaces(map[i][j]) == true)
                j++;
            if (!ft_strchr("10NSEW", map[i][j]))
                return (ft_error(data->mapper.path, ERROR_MAP_GARNISH, 1));
            if (ft_strchr("NSEW", map[i][j]) && data->player.dir != '0')
                return (ft_error(data->mapper.path, ERROR_MAP_PLAYER, 1));
            if (ft_strchr("NSEW", map[i][j]) && data->player.dir == '0')
                data->player.dir = '0';
            j++;
        }
        i++;
    }
    return (0);
}



int check_map()
{

}
