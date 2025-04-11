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

void	init_img(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, SC_WID, SC_HEI);
	data->img.img_pix = mlx_get_data_addr(data->img.img, &data->img.bpp, 
		&data->img.size_line, &data->img.endian);
}

void	init_texture(t_data *data)
{
	data->no.img = mlx_xpm_file_to_image(data->mlx, data->no.path,
		&data->width, &data->height);
	data->no.img_pix = mlx_get_data_addr(data->no.img, &data->no.bpp, 
		&data->no.size_line, &data->no.endian);
	data->so.img = mlx_xpm_file_to_image(data->mlx, data->so.path,
		&data->width, &data->height);
	data->so.img_pix = mlx_get_data_addr(data->so.img, &data->so.bpp, 
		&data->so.size_line, &data->so.endian);
	data->ea.img = mlx_xpm_file_to_image(data->mlx, data->ea.path,
		&data->width, &data->height);
	data->ea.img_pix = mlx_get_data_addr(data->ea.img, &data->ea.bpp, 
		&data->ea.size_line, &data->ea.endian);
	data->we.img = mlx_xpm_file_to_image(data->mlx, data->we.path,
		&data->width, &data->height);
	data->we.img_pix = mlx_get_data_addr(data->we.img, &data->we.bpp, 
		&data->we.size_line, &data->we.endian);
}


bool	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (MLX_FAIL, false);
	data->win = mlx_new_window(data->mlx, SC_WID, SC_HEI, "cube3d aule-bre");
	init_img(data);
	init_texture(data);
	if (!data->win)
		return (MLX_FAIL, false);
	if (!data->no.img || !data->so.img || !data->ea.img || !data->we.img)
		return (MLX_IMG_FAIL, false);
	return (true);
}
