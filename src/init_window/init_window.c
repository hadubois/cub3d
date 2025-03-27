/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:40:10 by aule-bre          #+#    #+#             */
/*   Updated: 2025/03/26 17:24:42 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (MLX_FAIL, false);
	data->win = mlx_new_window(data->mlx, 40 * data->map_size.y + 1, 40 * data->map_size.x + 1, "cube3d aule-bre");
	data->no.addr = mlx_xpm_file_to_image(data->mlx, data->no.path,
			&data->width, &data->height);
	data->so.addr = mlx_xpm_file_to_image(data->mlx, data->so.path,
			&data->width, &data->height);
	data->we.addr = mlx_xpm_file_to_image(data->mlx, data->ea.path,
			&data->width, &data->height);
	data->ea.addr = mlx_xpm_file_to_image(data->mlx, data->we.path,
			&data->width, &data->height);
	if (!data->win)
		return (MLX_FAIL, false);
	if (!data->no.addr || !data->so.addr || !data->ea.addr || !data->we.addr)
		return (MLX_IMG_FAIL, false);
	return (true);
}
