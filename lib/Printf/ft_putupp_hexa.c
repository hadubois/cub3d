/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupp_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asritz <asritz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:39 by asritz            #+#    #+#             */
/*   Updated: 2024/01/26 16:46:57 by asritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_nbr(unsigned long int nbr)
{
	int	length;

	length = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		length++;
	}
	return (length);
}

int	ft_putupp_hexa(unsigned int nbr)
{
	char	*base;
	int		length;

	base = "0123456789ABCDEF";
	length = 0;
	length += ft_length_nbr(nbr);
	if (nbr >= 16)
	{
		ft_putupp_hexa(nbr / 16);
		ft_putupp_hexa(nbr % 16);
	}
	else
		ft_putchar_fd_print(base[nbr], 1);
	return (length);
}
