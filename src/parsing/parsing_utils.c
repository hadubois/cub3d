/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:12:57 by hadubois          #+#    #+#             */
/*   Updated: 2025/04/16 13:18:54 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_split_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (false);
	while (i < 6)
	{
		if (!map[i])
			return (false);
		i++;
	}
	return (true);
}

char	*get_clean_path(char *messy_path)
{
	if (!messy_path)
		return (NULL);
	while (*messy_path && *messy_path != ' ')
		messy_path++;
	while (*messy_path == ' ')
		messy_path++;
	return (ft_strdup(messy_path));
}

void	fill_keywords(char **map, t_data *data)
{
	while (*map)
	{
		if (ft_strncmp(*map, "NO ", 3) == 0)
			data->no.path = get_clean_path(*map);
		else if (ft_strncmp(*map, "SO ", 3) == 0)
			data->so.path = get_clean_path(*map);
		else if (ft_strncmp(*map, "WE ", 3) == 0)
			data->we.path = get_clean_path(*map);
		else if (ft_strncmp(*map, "EA ", 3) == 0)
			data->ea.path = get_clean_path(*map);
		else if (ft_strncmp(*map, "F ", 2) == 0)
			data->checker_f = fill_rgb((*map) + 2, data->c);
		else if (ft_strncmp(*map, "C ", 2) == 0)
			data->checker_c = fill_rgb((*map) + 2, data->f);
		map++;
	}
}
