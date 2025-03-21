/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:40:16 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/15 18:20:02 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_set(const char *set, char c)
{
	int	k;

	k = 0;
	while (set[k])
	{
		if (c == set[k])
			return (1);
		k++;
	}
	return (0);
}

int	ft_abs(int i, int j)
{
	if (i - j > 0)
		return (1);
	return (j - i + 2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;
	int		k;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (in_set(set, s1[i]))
		i++;
	while (in_set(set, s1[j]))
		j--;
	str = malloc(ft_abs(i, j) * sizeof(char));
	if (!str)
		return (NULL);
	k = 0;
	while (k + i <= j)
	{
		str[k] = s1[k + i];
		k++;
	}
	str[k] = 0;
	return (str);
}
