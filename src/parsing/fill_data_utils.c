/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:12:57 by hadubois          #+#    #+#             */
/*   Updated: 2025/04/18 14:25:22 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*strjoin_wrapper(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	if (!tmp)
		return (NULL);
	return (tmp);
}

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

bool	find_str(const char *big, const char *little)
{
	int	i;
	int	j;

	if (!big || !little)
		return (false);
	if (*little == 0)
	{
		printf("check O.K\n");
		return (true);
	}
	i = 0;
	while (big[i])
	{
		j = 0;
		if (big[i] == little[0])
		{
			while (big[i + j] == little[j] && little[j])
				j++;
			if (!little[j])
				return (true);
		}
		i++;
	}
	return (false);
}
