#include "cub3d.h"

/**
 * Calculating the axis height is essential in our program.
 * Keep in mind the greatest limit of DDA -> all walls are perpendicular to the floor.
 * Meaning that unfortunately we cannot move on the "z" axis. But no matter.
 * We still need the height of the axis or stripe being studied in comparison to
 * the normalized window axis to successfully output the correct color or the correct pixel.
 * 
 * For this, we need to calculate the axis height.
*/

