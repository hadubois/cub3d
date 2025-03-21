/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asritz <asritz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:15:01 by asritz            #+#    #+#             */
/*   Updated: 2024/07/16 18:25:54 by asritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

ssize_t	ft_strlen_gnl(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr_gnl(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	if ((char)c == '\0')
		return (1);
	return (0);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	void				*s;
	size_t				totalsize;
	unsigned char		*ptr;

	totalsize = (nmemb * size);
	if (nmemb && size > (size_t) - 1 / nmemb)
		return (NULL);
	s = malloc(nmemb * size);
	if (s == NULL)
		return (NULL);
	ptr = (unsigned char *)s;
	while (totalsize > 0)
	{
		*ptr = 0;
		ptr++;
		totalsize--;
	}
	return (s);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1len;
	size_t	s2len;
	char	*str;

	if (!s1 || !s2)
		return (free (s1), NULL);
	i = 0;
	j = 0;
	s1len = ft_strlen_gnl(s1);
	s2len = ft_strlen_gnl(s2);
	str = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && i < s1len + s2len)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

ssize_t	ft_temp_size_gnl(char *stash)
{
	ssize_t	i;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		i++;
	}
	if (stash[i] == '\0')
		return (ft_strlen_gnl(stash) - i);
	else
		return (ft_strlen_gnl(stash) - i - 1);
}
