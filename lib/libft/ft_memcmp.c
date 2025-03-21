/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:23:30 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/13 15:23:31 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (i < n - 1 && *ptr1 == *ptr2)
	{
		i++;
		ptr1++;
		ptr2++;
	}
	if (*ptr1 == *ptr2)
		return (0);
	else if (*ptr1 < *ptr2)
		return (-1);
	return (1);
}
