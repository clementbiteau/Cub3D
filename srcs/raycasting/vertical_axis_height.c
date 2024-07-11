#include "cub3d.h"

/**
 * Calculating the axis height is essential in our program.
 * Keep in mind the greatest limit of DDA -> all walls are perpendicular to the floor.
 * Meaning that unfortunately we cannot move on the "z" axis. But no matter.
 * We still need the height of the axis or stripe being studied in comparison to
 * the normalized window axis to successfully output the correct image of perspective.
 * 
 * In simple words : the further the object, the smaller it will appear.
 * the closer we are, the bigger it must appear.
 * This corrects the "Fish Eye Effect".
 * A fish sees a corner of a wall -> it only sees a 2D block.
 * We must create perspective ->
 *          / \
 *         /   \
 *        /     \
 *           î          
 *         PLAYER
*/


/**
 * First, we obviously calculate the distance between the player and the wall it is facing.
 * This is the empty distance between the start of the ray, and the end of the ray.
*/
static double   perpendicular_distance(t_ray *ray)
{
    if (ray->vert_or_horiz == 0)
        return (ray->dist_to_wall_x - ray->dist_on_delta_x);
    else
        return (ray->dist_to_wall_y - ray->dist_on_delta_y);
}

/**
 * Here, we must calculate the height of the wall slice.
 * This will enable us to have the perspective view.
*/

static int  axis_height(double perp_wall_dist, int win_height)
{
    return ((int)(win_height / perp_wall_dist));
}

/**
 * To make the slice, we must find the base point of it.
 * Though, for realism purposes, we must calculate the starting point
 * aligned with the middle of the screen or window in that case.
 * It is to make sure that indeed the slice itself respects the
 * normalization of the axis to the window.
*/

static int calculate_slice_start(int axis_height, int win_height)
{
    int slice_start;
    
    slice_start = -(axis_height) / 2 + win_height / 2;
    if (slice_start < 0)
        return (0);
    return (slice_start);
}

/**
 * We must also know when to stop drawing the end of the slice.
 * Here, we do not substract the axis_height because we need to
 * figure out the length of the line to slice.
*/

static int calculate_slice_end(int axis_height, int win_height)
{
    int slice_end;
    
    slice_end = axis_height / 2 + win_height / 2;
    if (slice_end >= win_height)
        return (win_height - 1);
    return (slice_end);
}

/**
 * Now we must find out if the wall we found is vertical or horizontal
 * compared to the ray.
 * In the event it is vertical ( == 0), we identify the reached wall,
 * on the Y factors.
 * In the event it is horizontal, ( != 0), we identify the reached wall,
 * on the X factors.
 * 
 * ---------    -> horizontal
 * |        | -> vertical
 * |    î   |
 * |    P   |
 * |        |
 * ---------
 * 
 * We use the floor() function in math.h to only leave the precise
 * fractionall part and removes the integer.
 * This part ensures the detailed texture mapping and rendering.
*/

static double how_was_wall_hit(t_ray *ray, t_player *player)
{
    double  wall_x;
    if (ray->vert_or_horiz == 0)
        wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
    else
        wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
    return (wall_x - floor(wall_x));
}

void raycast_detailed_cooking(t_ray *ray, t_data *data, t_player *player)
{
    ray->perp_wall_dist = calculate_perpendicular_distance(ray);
    ray->axis_height = calculate_axis_height(ray->perp_wall_dist, data->win_height);
    ray->cast_start = calculate_slice_start(ray->axis_height, data->win_height);
    ray->cast_end = calculate_slice_end(ray->axis_height, data->win_height);
    ray->wall_height = how_was_wall_hit(ray, player);
}