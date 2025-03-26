/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:16:15 by aule-bre          #+#    #+#             */
/*   Updated: 2025/03/26 17:24:58 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	check_values(char **map, char orientation)
{
	int	start;
	int	i;
	int	j;

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

bool	check_around(char **map, int i, int j)
{
	int	len;

	len = -1;
	while (map[len + 1])
		len++;
	if (i == 0 || i == len)
		return (false);
	if (j == 0 | map[i][j + 1] == '\0')
		return (false);
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || map[i][j - 1] == ' '
		|| map[i][j + 1] == ' ')
		return (false);
	if (map[i - 1][j - 1] == ' ' || map[i + 1][j + 1] == ' ' || map[i - 1][j
		- 1] == ' ' || map[i + 1][j + 1] == ' ')
		return (false);
	return (true);
}

bool	check_borders(char **map, t_data *data)
{
	int	i;
	int	j;
	int jmax;

	i = -1;
	jmax = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strrchr("0NSEW", map[i][j]))
			{
				if (check_around(map, i, j) == false)
					return (false);
			}
		}
		if (j > jmax)
			jmax = j;
	}
	data->mapx = i;
	data->mapy = jmax;
	return (true);
}

bool	check_map(t_data *data)
{
	if (check_values(data->map, data->orientation) == false)
		return (false);
	if (check_borders(data->map, data) == false)
		return (INVALID_BORDERS, false);
	return (true);
}
