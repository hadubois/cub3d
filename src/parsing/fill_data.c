#include "cube3d.h"

bool	fill_rgb(char *line, int *array)
{
	int		len;
	int		i;

	i = 0;
	while (*line && i < 3)
	{
		len = 1;
		while (ft_isdigit(*(line++)))	
			len++;
		array[i] = ft_atoi(line - len);
		line--;
		if (i < 2 && ',' != *(line++))
			return (INVALID_CHAR, false);
		i++;
	}
	if (array[0] < 0 || array[0] > 255 || array[1] < 0 || array[1] > 255 || array[2] < 0 || array[2] > 255)
		return (OUT_OF_SCALE_COLOR, false);
	return (true);
}

int	tab_len(char **map)
{
	int	i;

	i = 0;
	while (map[6 + i])
		i++;
	return (i);
}

bool	fill_map(char *map_content, t_data *data)
{
	char	**map;
	int		i;
	char	**map_tab;

	map = ft_split(map_content, '\n');
	if (!map)
		return (ERROR_MALLOC, false);
	i = 5;
	map_tab = malloc((tab_len(map) + 1) * sizeof(char *));
	if (!map_tab)
		return (free_tab((void **)map), ERROR_MALLOC, false);
	while (map[++i])
		map_tab[i - 6] = ft_strdup(map[i]);
	map_tab[i - 6] = NULL;
	data->map = map_tab;
	free_tab((void **)map);
	if (!data->map[0])
		return (false);
	return (true);
}

bool	fill_identifiers(char *map_content, t_data *data)
{
	char	**map;
	bool	checker_f;
	bool	checker_c;

	map = ft_split(map_content, '\n');
	if (!map)
		return (ERROR_MALLOC, false);
	if (map[0] && ft_strncmp(map[0], "NO ", 3) == 0)
		data->no = ft_strdup(&map[0][3]);
	if (map[1] && ft_strncmp(map[1], "SO ", 3) == 0)
		data->so = ft_strdup(&map[1][3]);
	if (map[2] && ft_strncmp(map[2], "WE ", 3) == 0)
		data->we = ft_strdup(&map[2][3]);
	if (map[3] && ft_strncmp(map[3], "EA ", 3) == 0)
		data->ea = ft_strdup(&map[3][3]);
	if (map[4] && ft_strncmp(map[4], "F ", 2) == 0)
		checker_f = fill_rgb(&map[4][2], data->f);
	if (map[5] && ft_strncmp(map[5], "C ", 2) == 0)
		checker_c = fill_rgb(&map[5][2], data->c);
	free_tab((void **)map);
	if (!data->no || !data->so || !data->we || !data->ea)
		return (WRONG_IDENTIFIER, false);
	else if (!checker_f || !checker_c)
		return (false);
	return (true);
}

bool	fill_data(char *map_content, t_data *data)
{
	if (fill_identifiers(map_content, data) == false)
		return (free(map_content), false);
	if (fill_map(map_content, data) == false)
		return (free(map_content), EMPTY_MAP, false);
	return (free(map_content), true);
}