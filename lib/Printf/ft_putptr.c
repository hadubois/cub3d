/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asritz <asritz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:45:39 by asritz            #+#    #+#             */
/*   Updated: 2024/01/31 16:52:21 by asritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_ptr(unsigned long int nbr)
{
	int	length;

	length = 0;
	if (nbr == 0)
		return (1);
	else
	{
		while (nbr > 0)
		{
			nbr = nbr / 16;
			length++;
		}
	}
	return (length);
}

static int	ft_puthexa(unsigned long int nbr)
{
	int	length;

	length = ft_length_ptr(nbr);
	if (nbr >= 16)
	{
		ft_puthexa(nbr / 16);
		ft_puthexa(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd_print((nbr + '0'), 1);
		else
			ft_putchar_fd_print((nbr - 10 + 'a'), 1);
	}
	return (length);
}

int	ft_putptr(void *ptr)
{
	unsigned long int	addrs;
	int					length;

	length = 0;
	addrs = (unsigned long int)ptr;
	if (!addrs || addrs == 0 || ptr == NULL || !ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	length += ft_putstr_fd_print("0x", 1);
	length += ft_puthexa(addrs);
	return (length);
}
