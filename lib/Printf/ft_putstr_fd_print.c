/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asritz <asritz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:08:17 by asritz            #+#    #+#             */
/*   Updated: 2024/01/26 16:46:16 by asritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlength(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr_fd_print(char *str, int fd)
{
	if (!str)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	if (str)
		write(fd, str, ft_strlength(str));
	return (ft_strlength(str));
}
