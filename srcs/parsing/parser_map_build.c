#include "cub3d.h"

static bool check_walls(char **map, int row)
{
	int col = 0;

	if (!map || !map[row])
		return (false);
	while (map[row][col] && is_spaces(map[row][col]))
		col++;
	while (map[row][col])
	{
		if (map[row][col] != '1')
			return (false);
		col++;
	}
	return (true);
}

int check_map_sides(t_mapper *map, char **map_tab)
{
	int row = 0;
	int last_col;

	if (!map || !map_tab)
		return (1);
	if (!check_walls(map_tab, 0))
		return (1);
	row = 1;
	while (row < map->height - 1)
	{
		if (!map_tab[row])
			return (1);

		last_col = strlen(map_tab[row]) - 1;
		if (map_tab[row][0] != '1')
			return (1);
		if (map_tab[row][last_col] != '1')
			return (1);

		row++;
	}
	if (!check_walls(map_tab, row))
		return (1);
	return (0);
}

bool check_map_build(t_mapper *map_info, char **map)
{
	int row;
	int col;
	int width;

	if (!check_walls(map, 0))
		return (false);
	row = 1;
	while (row < map_info->height - 1)
	{
		if (!map[row])
			return (false);
		col = 0;
		width = strlen(map[row]);
		while (map[row][col] && is_spaces(map[row][col]))
			col++;
		if (map[row][col] != '1')
			return (false);
		if (map[row][width - 1] != '1')
			return (false);
		row++;
	}
	if (!check_walls(map, map_info->height - 1))
		return (false);
	return (true);
}
