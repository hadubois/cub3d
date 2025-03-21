/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:23:36 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/15 16:58:47 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr1;
	const char	*ptr2;

	if (!dest && !src)
		return (NULL);
	ptr1 = dest;
	ptr2 = src;
	while (n--)
		*(ptr1++) = *(ptr2++);
	return (dest);
}
