#ifndef CUB3D_H
# define CUB3D_H

# include "colors.h"
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>


# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define MOVEMENT_SPEED 0.1
# define ROTATION_SPEED 0.05

# define MOUSE_MOVEMENT 10

# define ERROR_START "./cub3d -> <map> (map file must be .cub)"
# define ERROR_INPUT_ARGS "Wrong Arguments Input"
# define ERROR_INPUT_CUB "Must provide a valid .cub file"
# define ERROR_INPUT_XPM "Must provide a valid .xpm file"

# define ERROR_MAP_GARNISH "Wrong Map Elements -> map defined by: 10NSEW"
# define ERROR_MAP_PLAYER "Wrong Number of Players -> only 1 is allowed"

# define ERROR_NO_MLX "MinilibX was unable to open a window."
# define ERROR_MLX_AFF "MinilibX was unable to give a printout."

typedef unsigned long	t_ulong;

enum    e_output
{
    SUCCESS = 0,
    FAILURE = 1,
    ERR = 2,
    BREAK = 3,
    CONTINUE = 4
};

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_coloring
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	floor_in_hexa;
	unsigned long	ceiling_in_hexa;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_coloring;

typedef struct s_mapper
{
	int			fd;
	int			height;
	int			width;
	int			line_count;
	char		*path;
	char		**file;
	int			last_index;
}	t_mapper;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	int			win_height;
	int			win_width;
	t_mapper	mapper;
	char		**map;
	t_player	player;
	t_ray		ray;
	int			**texture_pixels;
	int			**textures;
	t_coloring	coloring;
	t_img		minimap;
}	t_data;

// parsing args
int check_input(char *input);
int check_input(char *input);
bool    check_map_build(t_mapper *map_info, char **map);

// INIT
void    re_init_image(t_img *image);
void	init_mapper(t_mapper *mapper);
void init_player_in_field(t_data *data);
void	init_player(t_player *player);
void	init_ray(t_ray *ray);
void	init_data(t_data *data);
void	init_mlx(t_data *data);

// movement manager
int    check_move(t_data *data, double next_x, double next_y);
int	moving(t_data *data);
void	listen_for_input(t_data *data);

// UTILS
bool    is_spaces(char c);
bool    only_digit(char *str);

// EXIT
void    free_table(void **tab);
int    free_data(t_data *data);
int    ft_error(char *why, char *str, int exit_code);
int exit_game(t_data *data);
int quit(t_data *data, int exit_code);

// raycasting
// rendering

#endif