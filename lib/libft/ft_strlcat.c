/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:38:29 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/15 17:45:03 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	dlen = 0;
	slen = 0;
	if (!dest && !size)
		return (0);
	while (src[slen])
		slen++;
	while (dest[dlen])
		dlen++;
	if (size <= 0 && src)
		return (slen);
	i = -1;
	if (size > dlen)
	{
		while (++i < size - dlen - 1 && src[i])
			dest[dlen + i] = src[i];
		dest[dlen + i] = 0;
		return (slen + dlen);
	}
	return (size + slen);
}
