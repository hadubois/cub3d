/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:16:45 by hadubois          #+#    #+#             */
/*   Updated: 2025/04/19 11:56:18 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*extract_elements(int fd, char *res)
{
	int		nb_elt;
	char	*line;
	char	*tmp;

	nb_elt = 0;
	line = get_next_line(fd);
	if (!line)
		return (printf(ERROR T _FATAL), NULL);
	while (line && nb_elt < 6)
	{
		if (ft_strncmp(line, "\n", 2) != 0)
		{
			tmp = line;
			line = ft_strtrim(line, " \n");
			free(tmp);
			line = strjoin_wrapper(line, "\n");
			res = strjoin_wrapper(res, line);
			nb_elt++;
		}
		free(line);
		if (nb_elt < 6)
			line = get_next_line(fd);
	}
	return (res);
}

static char	*skip_nl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && ft_strncmp(line, "\n", 2) == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static char	*extract_map(int fd)
{
	char	*line;
	char	*map;

	map = NULL;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		map = strjoin_wrapper(map, line);
		if (!map)
			return (NULL);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}

static bool	ignore_nl_from_bottom_and_find_str(char *big, char *little)
{
	int	i;
	int	j;

	if (!big || !little || *little == 0 || *big == 0)
		return (false);
	i = ft_strlen(big) - 1;
	while (i >= 0 && big[i] == '\n')
		i--;
	while (i >= 0)
	{
		if (big[i] == '\n')
		{
			j = ft_strlen(little) - 1;
			while (j >= 0 && little[j] == big[i])
			{
				j--;
				i--;
			}
			if (j < 0)
				return (true);
		}
		i--;
	}
	return (false);
}

char	*get_file_content(int fd)
{
	char	*res;
	char	*tmp;

	res = NULL;
	res = extract_elements(fd, res);
	if (!res)
		return (close(fd), printf(L "extract_elements()\n"), NULL);
	tmp = skip_nl(fd);
	res = strjoin_wrapper(res, tmp);
	free(tmp);
	if (!res)
		return (close(fd), printf(ERROR T _FATAL L "skip_nl()\n"), NULL);
	tmp = extract_map(fd);
	res = strjoin_wrapper(res, tmp);
	free(tmp);
	if (!res)
		return (close(fd), printf(ERROR T _FATAL L "extract_map()\n"), NULL);
	if (ignore_nl_from_bottom_and_find_str(res, "\n\n"))
		return (close(fd), free(res), printf(ERROR L _MAP_NOT_CLOSED), NULL);
	close(fd);
	return (res);
}
