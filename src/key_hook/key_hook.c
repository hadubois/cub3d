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

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65361)
		data->player_angle -= M_PI / 16;
	else if (keycode == 65363)
		data->player_angle += M_PI / 16;
	else if (keycode == 122)
		data->player.y -= 10;
	else if (keycode == 115)
		data->player.y += 10;
	else if (keycode == 100)
		data->player.x += 10;
	else if (keycode == 113)
		data->player.x -= 10;
	else if (keycode == 65307)
		close_mlx(data);
	print_minimap(data);
	return (0);
}
