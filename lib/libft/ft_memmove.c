/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:23:44 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/15 16:59:34 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr;
	const char	*ptr2;

	if (!dest && !src)
		return (NULL);
	ptr = dest;
	ptr2 = src;
	i = 0;
	if (ptr2 < ptr)
		while (i++ < n)
			ptr[n - i] = ptr2[n - i];
	else
		while (i++ < n)
			*(ptr++) = *(ptr2++);
	return (dest);
}
