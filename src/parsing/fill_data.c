/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:16:39 by aule-bre          #+#    #+#             */
/*   Updated: 2025/04/16 12:21:30 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	fill_rgb(char *line, int *array)
{
	int	len;
	int	i;

	while (*line == ' ')
		line++;
	i = 0;
	while (*line && i < 3)
	{
		len = 1;
		while (ft_isdigit(*(line++)))
			len++;
		array[i] = ft_atoi(line - len);
		line--;
		if (i < 2 && ',' != *(line++))
			return (false);
		i++;
	}
	if (*line)
		return (false);
	if (array[0] < 0 || array[0] > 255 || array[1] < 0 || array[1] > 255
		|| array[2] < 0 || array[2] > 255)
		return (false);
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
		return (printf(ERROR ERROR_MALLOC), false);
	i = 5;
	map_tab = malloc((tab_len(map) + 1) * sizeof(char *));
	if (!map_tab)
		return (free_tab((void **)map), printf(ERROR ERROR_MALLOC), false);
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

	map = ft_split(map_content, '\n');
	if (!check_split_map(map))
		return (printf(ERROR ERROR_MALLOC), false);
	fill_keywords(map, data);
	free_tab((void **)map);
	if (!data->no.path || !data->so.path || !data->we.path || !data->ea.path)
		return (printf(ERROR WRONG_IDENTIFIER), false);
	else if (!data->checker_f || !data->checker_c)
		return (printf(ERROR INVALID_ELT_ID), false);
	return (true);
}

bool	fill_data(char *map_content, t_data *data)
{
	if (fill_identifiers(map_content, data) == false)
		return (free(map_content), false);
	if (fill_map(map_content, data) == false)
		return (free(map_content), printf(ERROR EMPTY_MAP), false);
	data->floor = (data->f[0] << 16) | (data->f[1] << 8) | data->f[2];
	data->ceiling = (data->c[0] << 16) | (data->c[1] << 8) | data->c[2];
	return (free(map_content), true);
}
