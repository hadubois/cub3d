#include "cube3d.h"

bool	parse(char *map_file, t_data *data)
{
	char	*map_content;

	if (check_map_format(map_file) == false)
		return (WRONG_MAP_EXT, false);
	map_content = open_map(map_file);
	if (!map_content)
		return (false);
	if (fill_data(map_content, data) == false)
		return (free_data(data), false);
	if (check_map(data) == false)
		return (free_data(data), false);
	return (true);
}