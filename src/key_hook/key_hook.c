/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:59:40 by aule-bre          #+#    #+#             */
/*   Updated: 2025/03/26 18:03:08 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	check_dir(t_data *data, int dir)
{
	t_coo	new;

	if (dir == FORWARD)
	{
		new.x = data->player.x - (int)(8 * cos(data->player_angle));
		new.y = data->player.y - (int)(8 * sin(data->player_angle));
	}
	if (dir == BACKWARD)
	{
		new.x = data->player.x + (int)(8 * cos(data->player_angle));
		new.y = data->player.y + (int)(8 * sin(data->player_angle));
	}
	if (dir == LEFT)
	{
		new.x = data->player.x - (int)(8 * sin(data->player_angle));
		new.y = data->player.y + (int)(8 * cos(data->player_angle));
	}
	if (dir == RIGHT)
	{
		new.x = data->player.x + (int)(8 * sin(data->player_angle));
		new.y = data->player.y - (int)(8 * cos(data->player_angle));
	}
	if (data->map[new.y / 32][new.x / 32] == '1')
		return (false);
	return (true);
}

void	move(t_data *data, int dir)
{
	if (dir == FORWARD)
	{
		data->player.y -= (int)(4 * sin(data->player_angle));
		data->player.x -= (int)(4 * cos(data->player_angle));
	}
	if (dir == BACKWARD)
	{
		data->player.y += (int)(4 * sin(data->player_angle));
		data->player.x += (int)(4 * cos(data->player_angle));
	}
	if (dir == LEFT)
	{
		data->player.y += (int)(4 * cos(data->player_angle));
		data->player.x -= (int)(4 * sin(data->player_angle));
	}
	if (dir == RIGHT)
	{
		data->player.y -= (int)(4 * cos(data->player_angle));
		data->player.x += (int)(4 * sin(data->player_angle));
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65361)
		data->player_angle -= M_PI / 64;
	if (keycode == 65363)
		data->player_angle += M_PI / 64;
	if (keycode == 122 && check_dir(data, FORWARD))
		move(data, FORWARD);
	if (keycode == 115 && check_dir(data, BACKWARD))
		move(data, BACKWARD);
	if (keycode == 100 && check_dir(data, RIGHT))
		move(data, RIGHT);
	if (keycode == 113 && check_dir(data, LEFT))
		move(data, LEFT);
	if (keycode == 65307)
		close_mlx(data);
	print_back(data);
	print_ray(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
