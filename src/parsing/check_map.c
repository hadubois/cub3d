#include "cube3d.h"

bool	check_values(char **map, char orientation)
{
	int	start;
	int	i;
	int j;

	start = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strrchr(" 01NSEW", map[i][j]))
				return (INVALID_VALUES, false);
			if (ft_strrchr("NSEW", map[i][j]))
			{
				orientation = map[i][j];
				start++;
			}
		}
	}
	if (start == 1)
		return (true);
	return (MULTIPLE_START, false);
}

bool	check_map(t_data *data)
{
	if (check_values(data->map, data->orientation) == false)
		return (false);
	//if (check_borders(map) == false)
	//	return (INVALID_BORDERS, false);
	return (true);
}