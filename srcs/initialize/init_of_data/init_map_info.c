#include "cub3d.h"

void	init_mapper(t_mapper *mapper)
{
	mapper->fd = 0;
	mapper->line_count = 0;
	mapper->path = NULL;
	mapper->file = NULL;
	mapper->height = 0;
	mapper->width = 0;
	mapper->index_end_of_map = 0;
}