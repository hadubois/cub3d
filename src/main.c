/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:17:02 by aule-bre          #+#    #+#             */
/*   Updated: 2025/03/24 15:18:31 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (WRONG_NUMBER_ARG, 1);
	ft_bzero(&data, sizeof(t_data));
	if (parse(av[1], &data) == false)
		return (1);
	free_data(&data);
	return (0);
}
