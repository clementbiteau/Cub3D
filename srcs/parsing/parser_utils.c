#include "cub3d.h"

// int	check_textures_validity(t_data *data, t_coloring *textures)
// {
// 	if (!textures->north || !textures->south || !textures->west
// 		|| !textures->east)
// 		return (ft_error(data->mapper.path, ERROR_TEXTURE, 1));
// 	if (!textures->floor || !textures->ceiling)
// 		return (ft_error(data->mapper.path, ERROR_COLOR, 1));
// 	if (check_file(textures->north, false) == 1
// 		|| check_file(textures->south, false) == 1
// 		|| check_file(textures->west, false) == 1
// 		|| check_file(textures->east, false) == 1
// 		|| check_valid_rgb(textures->floor) == 1
// 		|| check_valid_rgb(textures->ceiling) == 1)
// 		return (1);
// 	textures->floor_in_hexa = convert_rgb_to_hex(textures->floor);
// 	textures->ceiling_in_hexa = convert_rgb_to_hex(textures->ceiling);
// 	return (0);
// }

