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

static int check_position_is_valid(t_data *data, char **map_tab)
{
	int i;
	int j;
    
    i = (int)data->player.pos_y;
    j = (int)data->player.pos_x;

	if (strlen(map_tab[i - 1]) <= (size_t)j
		|| strlen(map_tab[i + 1]) <= (size_t)j
		|| is_spaces(map_tab[i][j - 1])
		|| is_spaces(map_tab[i][j + 1])
		|| is_spaces(map_tab[i - 1][j])
		|| is_spaces(map_tab[i + 1][j]))
		return 1;
	return (0);
}

static int check_player_position(t_data *data, char **map_tab)
{
	int i;;
	int j;

    i = 0;
	if (data->player.dir == '0')
		return ft_error(data->mapper.path, ERROR_PLAYER_DIRECTION, 1);
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (strchr("NSEW", map_tab[i][j]))
			{
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				map_tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (check_position_is_valid(data, map_tab) == 1)
		return ft_error(data->mapper.path, ERROR_PLAYER_PLACE, 1);
	return (0);
}

static int check_map_is_at_the_end(t_mapper *map)
{
	int i;
	int j;

    i = map->last_index;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (!is_spaces(map->file[i][j]))
				return 1;
			j++;
		}
		i++;
	}
	return (0);
}

int check_map_validity(t_data *data, char **map_tab)
{
	if (!data->map)
		return ft_error(data->mapper.path, ERROR_NO_MAP, 1);
	if (check_map_sides(&data->mapper, map_tab) == 1)
		return ft_error(data->mapper.path, ERROR_NO_WALLS, 1);
	if (data->mapper.height < 3)
		return ft_error(data->mapper.path, ERROR_MAP_SMALL, 1);
	if (check_map_garnish(data, map_tab) == 1)
		return 1;
	if (check_player_position(data, map_tab) == 1)
		return 1;
	if (check_map_is_at_the_end(&data->mapper) == 1)
		return ft_error(data->mapper.path, ERROR_MAP_CHAR_END, 1);
	return (0);
}
