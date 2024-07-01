#include "cub3d.h"

static void place_west(t_player *player)
{
    player->dir_x = -1;
    player->dir_y = 0;
    player->plane_x = 0;
    player->plane_y = -0.66;
}

static void place_east(t_player *player)
{
    player->dir_x = 1;
    player->dir_y = 0;
    player->plane_x = 0;
    player->plane_y = 0.66;
}

static void place_south(t_player *player)
{
    player->dir_x = 0;
    player->dir_y = 1;
    player->plane_x = -0.66;
    player->plane_y = 0;
}

static void place_north(t_player *player)
{
    player->dir_x = 0;
    player->dir_y = -1;
    player->plane_x = 0.66;
    player->plane_y = 0;
}

void init_player_in_field(t_data *data)
{
    if (data->player.dir == 'N')
        place_north(&data->player);
    else if (data->player.dir == 'S')
        place_south(&data->player);
    else if (data->player.dir == 'E')
        place_east(&data->player);
    else if (data->player.dir == 'W')
        place_west(&data->player);
}
