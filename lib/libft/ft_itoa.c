/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:11:50 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/13 15:11:52 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int n)
{
	int	size;

	size = 0;
	if (!n)
		return (1);
	if (n < 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

unsigned int	ft_new(int n)
{
	if (n > 0)
		return (n);
	if (n == -2147483648)
		return (2147483648);
	else
		return (-n);
}

char	*ft_itoa(int n)
{
	int				size;
	char			*str;
	unsigned int	n2;

	size = ft_size(n);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = 0;
	str[0] = '0';
	n2 = ft_new(n);
	if (n < 0)
		str[0] = '-';
	while (n2)
	{
		str[size - 1] = n2 % 10 + '0';
		n2 /= 10;
		size--;
	}
	return (str);
}
