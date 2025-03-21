/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:36:32 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/15 18:24:25 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			cpt++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cpt);
}

void	ncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

char	**ft_free(char **str, int j)
{
	int	i;

	i = 0;
	while (i <= j)
		free(str[i++]);
	free(str);
	return (NULL);
}

char	**array_create(char const *s, char c, char **str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i + len] != c && s[i + len])
			len++;
		if (len)
		{
			str[j] = malloc((len + 1) * sizeof(char));
			if (!str[j])
				return (ft_free(str, j));
			ncpy(str[j], &s[i], len);
			str[j++][len] = 0;
			i += len;
		}
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = array_create(s, c, str);
	return (str);
}
