/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:36:43 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/15 17:25:21 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!c)
	{
		while (*str)
			str++;
		return (str);
	}
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}
