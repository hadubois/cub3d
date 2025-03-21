/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asritz <asritz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:21:15 by asritz            #+#    #+#             */
/*   Updated: 2024/09/14 18:59:56 by asritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_unbr(unsigned long int nbr)
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

static void	ft_putchar_nbr_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putunbr_fd_print(unsigned int nb, int fd)
{
	unsigned long int	nbr;
	int					length;

	length = 0;
	nbr = nb;
	length += ft_length_unbr(nbr);
	if (nbr > 9)
	{
		ft_putunbr_fd_print((nbr / 10), fd);
		ft_putunbr_fd_print((nbr % 10), fd);
	}
	if (nbr > 0 && nbr <= 9)
		ft_putchar_nbr_fd((nbr + 48), fd);
	if (nbr == 0)
		ft_putchar_nbr_fd('0', fd);
	return (length);
}
