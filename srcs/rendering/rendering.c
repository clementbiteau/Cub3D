#include "cub3d.h"

static void set_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
    if (data->texture_pixels[y][x] > 0)
        set_image_pixel(image, x, y, data->texture_pixels[y][x]);
    else if (y < data->win_height / 2)
        set_image_pixel(image, x, y, data->coloring.ceiling_in_hexa);
    else if (y < data->win_height - 1)
        set_image_pixel(image, x, y, data->coloring.floor_in_hexa);
}

static void render_frame(t_data *data)
{
    t_img   *image;
    int x;
    int y;

    image->img = NULL;
    init_img(data, &image, data->win_width, data->win_height);
    y = 0;
    while (y < data->win_height)
    {
        x = 0;
        while (x < data->win_width)
        {
            set_frame_image_pixel(data, &image, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->window, image->img, 0, 0);
    mlx_destroy_image(data->mlx, image->img);
}

static void render_raycast(t_data *data)
{
    init_texture_pixels(data);
    init_ray(&data->ray);
    raycasting(&data->player, data);
    render_frame(data);
}

static void    render_image(t_data *data)
{
    render_raycast(data);
    render_minimap(data);
}

int render(t_data *data)
{
    data->player.has_moved += player_is_moving(data);
    if (data->player.has_moved == 0)
        return (0);
    render_image(data);
    return (0);
}
