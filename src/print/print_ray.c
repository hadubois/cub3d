/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:47:18 by aule-bre          #+#    #+#             */
/*   Updated: 2025/04/13 11:47:45 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	print_back(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SC_HEI)
	{
		j = -1;
		while (++j < SC_WID)
		{
			if (i < SC_HEI / 2)
				my_pixel_put(j, i, data, data->floor);
			else
				my_pixel_put(j, i, data, data->ceiling);
		}
	}
}

void	print_nwse(t_ray ray, t_data *data, int r)
{
	if (ray.prev.x > ray.ray.x && (ray.ray.x + 1) % 32 == 0)
		print_line_west(data, ray, r, data->ea);
	else if (ray.prev.y > ray.ray.y && (ray.ray.y + 1) % 32 == 0)
		print_line_north(data, ray, r, data->so);
	else if (ray.prev.x < ray.ray.x && (ray.ray.x) % 32 == 0)
		print_line_east(data, ray, r, data->we);
	else if (ray.prev.y < ray.ray.y && (ray.ray.y) % 32 == 0)
		print_line_south(data, ray, r, data->no);
	if (ray.prev.x > ray.ray.x && (ray.ray.x + 1) % 32 == 0
		&& data->map[ray.ray.y / 32][ray.ray.x / 32 + 1] != '1')
		print_line_west(data, ray, r, data->no);
	else if (ray.prev.y > ray.ray.y && (ray.ray.y + 1) % 32 == 0
		&& data->map[ray.ray.y / 32 + 1][ray.ray.x / 32] != '1')
		print_line_north(data, ray, r, data->so);
	else if (ray.prev.x < ray.ray.x && (ray.ray.x) % 32 == 0
		&& data->map[ray.ray.y / 32][ray.ray.x / 32 - 1] != '1')
		print_line_east(data, ray, r, data->ea);
	else if (ray.prev.y < ray.ray.y && (ray.ray.y) % 32 == 0
		&& data->map[ray.ray.y / 32 - 1][ray.ray.x / 32] != '1')
		print_line_south(data, ray, r, data->we);
}

float	single_ray(t_data *data, t_ray *ray, float fov)
{
	float	r;

	r = 0;
	while (1)
	{
		if (r)
		{
			ray->prev.x = ray->ray.x;
			ray->prev.y = ray->ray.y;
		}
		ray->ray.x = data->player.x - cos(data->player_angle + fov) * r;
		ray->ray.y = data->player.y - sin(data->player_angle + fov) * r;
		if (!((ray->ray.x + 1) % 32 && (ray->ray.y + 1) % 32 && ray->ray.x % 32
				&& ray->ray.y % 32) && (data->map[ray->ray.y / 32][ray->ray.x
				/ 32] == '1'))
			break ;
		r += 1;
	}
	return (r);
}

void	print_ray(t_data *data)
{
	float	r;
	t_ray	ray;
	float	fov;

	fov = -1 * M_PI / 8;
	ray.i = -1;
	while (++ray.i < SC_WID)
	{
		r = single_ray(data, &ray, fov);
		print_nwse(ray, data, r);
		fov += M_PI / 4 / SC_WID;
	}
}
