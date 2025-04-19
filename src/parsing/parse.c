/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:16:56 by aule-bre          #+#    #+#             */
/*   Updated: 2025/04/19 11:58:14 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_map_format(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len > 4)
		if (ft_strncmp(&map_file[len - 4], ".cub", 5) == 0)
			return (true);
	return (printf(ERROR T _INVALID_EXTENSION), false);
}

static int	open_file(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (printf(ERROR T "%s\n", strerror(errno)), -1);
	return (fd);
}

bool	parse(char *map_file, t_data *data)
{
	int		fd;
	char	*map_content;

	if (check_map_format(map_file) == false)
		return (printf(L "check_map_format()\n"), false);
	fd = open_file(map_file);
	if (fd == -1)
		return (printf(L "open_file()\n"), false);
	map_content = get_file_content(fd);
	if (!map_content)
		return (false);
	if (fill_data(map_content, data) == false)
		return (free_data(data), false);
	if (check_map(data) == false)
		return (free_data(data), false);
	data->width = 64;
	data->height = 64;
	return (true);
}
