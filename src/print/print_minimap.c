/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:11:03 by aule-bre          #+#    #+#             */
/*   Updated: 2025/03/26 17:57:49 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	fill_square(t_data *data, int x, int y, int color)
{
	int i;
	int j;
	
	i = 0;
	while (++i < 40)
	{
		j = 0;
		while (++j < 40)
			mlx_pixel_put(data->mlx, data->win, 40 * x + i, 40 * y + j, color);
	}
}

void	fill_all(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '0')
				fill_square(data, j, i, 12247551);
			else if (data->map[i][j] == '1')
				fill_square(data, j, i, 16757690);
			else if (ft_strrchr("NSEW", data->map[i][j]))
				fill_square(data, j, i, 12255177);
		}
	}
	
}

void	print_minimap(t_data *data)
{
	int	i;
	int len;
	
	i = -1;
	while (++i < data->mapx + 1)
	{
		len = -1;
		while (++len < 40 * data->mapy)
			mlx_pixel_put(data->mlx, data->win, len, i * 40, 5919317);
	}
	i = -1;
	while (++i < data->mapy + 1)
	{
		len = -1;
		while (++len < 40 * data->mapx)
			mlx_pixel_put(data->mlx, data->win, i * 40, len, 5919317);
	}
	fill_all(data);
}
