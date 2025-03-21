/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:40:27 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/15 18:14:40 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start)
		str = malloc(sizeof(char));
	else if (slen - start > len)
		str = malloc((len + 1) * sizeof(char));
	else
		str = malloc((slen - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (slen > start && s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
