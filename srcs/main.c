#include "cub3d.h"

static void print_window_of_controls(void)
{
    printf(GREEN "\tW" RESET ": step forward\t");
	printf(RED "\tS" RESET ": step backward\n");
	printf(CYAN "\tA" RESET ": step to the left\t");
	printf(YELLOW "\tD" RESET ": step to the right\n");
	printf(BLUE "\t<" RESET ": rotate to left\t");
	printf(PURPLE "\t>" RESET ": rotate to right\n");
    printf(WHITE "\tMouse" RESET ": rotate view\n");
    printf("\n");
}

static void initializer(t_data *data)
{
    init_mlx(data);
	init_textures(data);
	init_minimap(&data->minimap, data->map, MINI_MAP_TSIZE);
}

static int	cub3d_start(t_data *data, char **av)
{
	init_data(data);
	if (parse_args(data, av) != 0)
		return (1);
    print_window_of_controls();
	initializer(data);
	return (0);
}

int main(int ac, char **av)
{
    t_data  *data;
    if (ac != 2)
		return (err_msg("Usage: ", ERROR_START, 1));
	data = malloc(sizeof(t_data));
	if (!data)
        return (ft_error("Memory allocation failed", ERROR_START, 1));
	cub3d_start(data, av);
	render_images(data);
	await_instructions(data);
	mlx_loop_hook(data->mlx, render, &data);
	mlx_loop(data->mlx);
	free(data);
	return (0);
}