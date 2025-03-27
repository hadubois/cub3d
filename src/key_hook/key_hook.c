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

void	move(t_data *data, int dir)
{
	if (dir == FORWARD)
	{
		data->player.y -= (int)(10 * sin(data->player_angle));
		data->player.x -= (int)(10 * cos(data->player_angle));
	}
	if (dir == BACKWARD)
	{
		data->player.y += (int)(10 * sin(data->player_angle));
		data->player.x += (int)(10 * cos(data->player_angle));
	}
	if (dir == LEFT)
	{
		data->player.y += (int)(10 * cos(data->player_angle));
		data->player.x -= (int)(10 * sin(data->player_angle));
	}
	if (dir == RIGHT)
	{
		data->player.y -= (int)(10 * cos(data->player_angle));
		data->player.x += (int)(10 * sin(data->player_angle));
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65361)
		data->player_angle -= M_PI / 16;
	else if (keycode == 65363)
		data->player_angle += M_PI / 16;
	else if (keycode == 122)
		move(data, FORWARD);
	else if (keycode == 115)
		move(data, BACKWARD);
	else if (keycode == 100)
		move(data, RIGHT);
	else if (keycode == 113)
		move(data, LEFT);
	else if (keycode == 65307)
		close_mlx(data);
	print_minimap(data);
	return (0);
}
