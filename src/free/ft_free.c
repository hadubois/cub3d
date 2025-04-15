/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:17:13 by aule-bre          #+#    #+#             */
/*   Updated: 2025/04/15 11:00:54 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(void **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

void	free_data(t_data *data)
{
	free(data->no.path);
	free(data->so.path);
	free(data->we.path);
	free(data->ea.path);
	free_tab((void **)data->map);
	data = NULL;
}

int	close_mlx(t_data *data)
{
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		if (data->no.img)
			mlx_destroy_image(data->mlx, data->no.img);
		if (data->so.img)
			mlx_destroy_image(data->mlx, data->so.img);
		if (data->we.img)
			mlx_destroy_image(data->mlx, data->we.img);
		if (data->ea.img)
			mlx_destroy_image(data->mlx, data->ea.img);
		if (data->img.img)
			mlx_destroy_image(data->mlx, data->img.img);
	}
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_data(data);
	exit(0);
	return (0);
}

int	close_mlx_error(t_data *data)
{
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		if (data->no.img)
			mlx_destroy_image(data->mlx, data->no.img);
		if (data->so.img)
			mlx_destroy_image(data->mlx, data->so.img);
		if (data->we.img)
			mlx_destroy_image(data->mlx, data->we.img);
		if (data->ea.img)
			mlx_destroy_image(data->mlx, data->ea.img);
		if (data->img.img)
			mlx_destroy_image(data->mlx, data->img.img);
	}
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_data(data);
	exit(1);
	return (0);
}
