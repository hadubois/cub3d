/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asritz <asritz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:08:01 by asritz            #+#    #+#             */
/*   Updated: 2024/01/31 17:54:17 by asritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_nbr(long nbr)
{
	int	length;

	length = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length);
}

int	ft_putnbr_fd_print(int nb, int fd)
{
	long	nbr;
	int		length;

	nbr = nb;
	length = 0;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = nbr * (-1);
		length++;
	}
	length += ft_length_nbr(nbr);
	if (nbr >= 0 && nbr <= 9)
		ft_putchar_fd_print((nbr + 48), fd);
	if (nbr > 9)
	{
		ft_putnbr_fd_print((nbr / 10), fd);
		ft_putnbr_fd_print((nbr % 10), fd);
	}
	return (length);
}
