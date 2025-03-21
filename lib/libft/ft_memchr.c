/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:23:19 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/13 15:23:22 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c2;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	c2 = (unsigned char)c;
	if (!n)
		return (NULL);
	while (i < n)
	{
		if (*ptr == c2)
			return (ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
