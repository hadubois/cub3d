/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_face.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:48:38 by aule-bre          #+#    #+#             */
/*   Updated: 2025/04/13 11:49:20 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

unsigned int	get_color(int x, int y, t_img img)
{
	int	offset;

	if (x >= 64 || y >= 64 || x < 0 || y < 0)
		return (0);
	offset = (y * img.size_line) + ((img.bpp / 8) * x);
	return (*(unsigned int *)(img.img_pix + offset));
}

void	print_line_east(t_data *data, t_ray ray, float r, t_img face)
{
	int	len;
	int	max;
	int	min;

	min = SC_HEI / 2 - SC_HEI / r * 22;
	max = SC_HEI / 2 + SC_HEI / r * 22;
	len = -1;
	while (++len + min < max)
		my_pixel_put(ray.i, len + min, data, get_color(ray.ray.y * 2 % 64, len
				* 64 / (max - min), face));
}

void	print_line_north(t_data *data, t_ray ray, float r, t_img face)
{
	int	len;
	int	max;
	int	min;

	min = SC_HEI / 2 - SC_HEI / r * 22;
	max = SC_HEI / 2 + SC_HEI / r * 22;
	len = -1;
	while (++len + min < max)
		my_pixel_put(ray.i, len + min, data, get_color(ray.ray.x * 2 % 64, len
				* 64 / (max - min), face));
}

void	print_line_west(t_data *data, t_ray ray, float r, t_img face)
{
	int	len;
	int	max;
	int	min;

	min = SC_HEI / 2 - SC_HEI / r * 22;
	max = SC_HEI / 2 + SC_HEI / r * 22;
	len = -1;
	while (++len + min < max)
		my_pixel_put(ray.i, len + min, data, get_color(63 - ray.ray.y * 2 % 64,
				len * 64 / (max - min), face));
}

void	print_line_south(t_data *data, t_ray ray, float r, t_img face)
{
	int	len;
	int	max;
	int	min;

	min = SC_HEI / 2 - SC_HEI / r * 22;
	max = SC_HEI / 2 + SC_HEI / r * 22;
	len = -1;
	while (++len + min < max)
		my_pixel_put(ray.i, len + min, data, get_color(63 - ray.ray.x * 2 % 64,
				len * 64 / (max - min), face));
}
