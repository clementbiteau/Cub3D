#ifndef CUB3D_H
# define CUB3D_H

# include "colors.h"
# include "../libft/includes/libft.h"
# include "mlx.h"
#include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define ESCAPE_KEY 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_SIZE 30

# define MOVEMENT_SPEED 0.1
# define ROTATION_SPEED 0.05

# define MOUSE_MOVEMENT 10

# define MINI_MAP_PLAYER 0xFF0000
# define MINI_MAP_WALL 0x00FF00
# define MINI_MAP_FLOOR 0x0000FF
# define MINI_MAP_SPACE 0xFFFFFF
# define MINI_MAP_PIXEL_SIZE 100
# define MINI_MAP_BORDERS 0x000000
# define MINI_MAP_TSIZE 10

# define ERROR_START "./cub3d -> <map> (map file must be .cub)"
# define ERROR_INPUT_ARGS "Wrong Arguments Input"
# define ERROR_INPUT_CUB "Must provide a valid .cub file"
# define ERROR_INPUT_XPM "Must provide a valid .xpm file"

# define ERROR_MAP_GARNISH "Wrong Map Elements -> map defined by: 10NSEW"
# define ERROR_MAP_PLAYER "Wrong Number of Players -> only 1 is allowed"
# define ERROR_PLAYER_PLACE "Player is not placed correctly."
# define ERROR_PLAYER_DIRECTION "Player is not facing valid direction."
# define ERROR_NO_MAP "No map found."
# define ERROR_NO_WALLS "No walls your player can escape."
# define ERROR_MAP_SMALL "Map is too small cannot be played."
# define ERROR_MAP_CHAR_END "Map has unclear character at end of file."

# define ERROR_NO_MLX "MinilibX was unable to open a window."
# define ERROR_MLX_AFF "MinilibX was unable to give a printout."

enum e_coloring_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
    void    *img;               // Pointer to the image data
    int     *addr;              // Pointer to the first pixel in the image data
    int     width;              // Width of the image in pixels
    int     height;             // Height of the image in pixels
    int     bits_per_pixel;     // Number of bits per pixel
    int     line_length;        // Length of a line in bytes in memory
    int     endian;             // Endianness of the image data
} t_img;


typedef struct s_coloring
{
    char            *north;         // Path or identifier for textures
	char			*south;
	char			*east;
	char			*west;
    int             *floor;         // Pointer to floor color or texture data
    int             *ceiling;       // Pointer to ceiling color or texture data
    unsigned long   floor_in_hexa;  // Floor color in hexadecimal
    unsigned long   ceiling_in_hexa;// Ceiling color in hexadecimal
    int             size;           // Size parameter, likely related to dimensions or length
    int             index;          // Index for array access or iteration
    double          step;           // Step size for some process
    double          pos;            // Position, likely in a coordinate system
    int             x;              // X coordinate in a plane or grid
    int             y;              // Y coordinate in a plane or grid
} t_coloring;

typedef struct s_mapper
{
    int     fd;             // File descriptor for file operations
    int     height;         // Height or vertical dimension
    int     width;          // Width or horizontal dimension
    int     line_count;     // Number of lines or line-related count
    char    *path;          // Path to a file or resource
    char    **file;         // Pointer to an array of strings of file
    int     last_index;     // Index of the last item or position in an array
} t_mapper;

typedef struct s_player
{
    char    dir;        // Direction the player is facing
    double  pos_x;      // X-coordinate of the player's position
    double  pos_y;      // Y-coordinate of the player's position
    double  dir_x;      // X-component of the player's direction vector
    double  dir_y;      // Y-component of the player's direction vector
    double  plane_x;    // X-component of the player's camera plane
    double  plane_y;    // Y-component of the player's camera plane
    int     has_moved;  // Flag indicating if the player has moved
    int     move_x;     // Movement direction in the x-axis
    int     move_y;     // Movement direction in the y-axis
    int     rotate;     // Flag or value indicating rotation
} t_player;

typedef struct s_ray
{
    double  camera_x;       // X-coordinate of the camera plane
    double  ray_dir_x;      // X-component of the ray direction
    double  ray_dir_y;      // Y-component of the ray direction
    int     map_x;          // X-coordinate of the map grid
    int     map_y;          // Y-coordinate of the map grid
    double  dist_to_wall_x; // Distance to the nearest wall in the x direction
    double  dist_to_wall_y; // Distance to the nearest wall in the y direction
    double  dist_on_delta_x;// Distance until next grid line in the x direction
    double  dist_on_delta_y;// Distance until next grid line in the y direction
    double  perp_wall_dist; // Perpendicular distance to the wall
    double  wall_height;    // Height of the wall segment on the screen
    int     cast_start;     // Start point of casting operation
    int     cast_end;       // End point of casting operation
    int     step_x;         // Step direction in the x-axis
    int     step_y;         // Step direction in the y-axis
    int     wall_hit;       // Flag indicating if a wall was hit
    int     vert_or_horiz;  // Flag indicating vertical or horizontal hit
    int     axis_height;    // Height or length in an axis
} t_ray;

typedef struct s_minimap
{
    t_img   img;       // Pointer to an image structure for the minimap
    char    **map;      // 2D array representing the minimap layout
    int     tile_size;  // Size of each tile in the minimap grid
    int     size;       // Overall size or dimensions of the minimap
} t_minimap;

typedef struct s_data
{
    void        *mlx;               // Pointer to MiniLibX instance
    void        *window;            // Pointer to the game window
    int         win_height;         // Height of the game window
    int         win_width;          // Width of the game window
    int         **texture_pixels;   // Pointer to texture pixel data
    int         **textures;         // Pointer to texture data
    char        **map;              // Pointer to the game map
    t_player    player;
    t_mapper    mapper;
    t_coloring  coloring;
    t_img       minimap;
    t_ray       ray;
} t_data;

// PARSING
int		check_input(char *input);
bool	check_map_build(t_mapper *map_info, char **map);
int check_map_validity(t_data *data, char **map_tab);
int check_map_sides(t_mapper *map, char **map_tab);

// INIT
void    re_init_image(t_img *image);
void	init_mapper(t_mapper *mapper);
void	init_player_in_field(t_data *data);
void	init_player(t_player *player);
void	init_data(t_data *data);
void	init_mlx(t_data *data);
void	init_minimap(t_minimap *minimap, char **map, int tile_size);
void    init_coloring(t_coloring *shades);
void	init_ray(t_ray *ray);
void    init_raycasting(int x, t_ray *ray, t_player *player);

// MOVE
int		check_move(t_data *data, double next_x, double next_y);
int		moving(t_data *data);
void	await_instructions(t_data *data);
int		rotate_player(t_data *data, double rotdir);

// UTILS
bool    is_spaces(char c);
bool    only_digit(char *str);
void	set_image_pixel(t_img *img, int x, int y, int color);

// EXIT
void	free_table(void **tab);
int		free_data(t_data *data);
int		ft_error(char *why, char *str, int exit_code);
int		exit_game(t_data *data);
int		quit(t_data *data, int exit_code);

// RAYCASTING
int raycasting(t_player *player, t_data *data);
void set_dda(t_ray *ray, t_player *player);
void do_dda(t_data *data, t_ray *ray);
void raycast_detailed_cooking(t_ray *ray, t_data *data, t_player *player);

// rendering
int render(t_data *data);

// MINIMAP
void make_minimap(t_data *data, t_minimap *minimap);

#endif