/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:39:55 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/15 17:52:18 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	cpt;

	cpt = 0;
	i = 0;
	if (!big && !len)
		return (NULL);
	if (little && !(*little))
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			while (big[i + cpt] == little[cpt] && little[cpt] && i + cpt < len)
				cpt++;
			if (!little[cpt])
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
