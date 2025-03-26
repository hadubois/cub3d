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
	if (keycode == 65361 && check_left(data))
		data->player.x--;
	if (keycode == 65363 && check_right(data))
		data->player.x++;
	if (keycode == 65362 && check_up(data))
		data->player.y--;
	if (keycode == 65364 && check_down(data))
		data->player.y++;
	if (keycode == 65307)
		close_mlx(data);
	print_map(data);
	return (0);
}
