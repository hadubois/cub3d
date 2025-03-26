/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:16:56 by aule-bre          #+#    #+#             */
/*   Updated: 2025/03/26 15:59:55 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	data->width = 40;
	data->height = 40;
	return (true);
}
