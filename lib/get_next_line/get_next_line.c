/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asritz <asritz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:16:17 by asritz            #+#    #+#             */
/*   Updated: 2024/07/16 18:32:33 by asritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Lit le fichier et cree la stash
char	*ft_read_and_stash(int fd, char *stash, char *buf, ssize_t read_size)
{
	char	*temp;

	if (!buf)
		return (NULL);
	read_size = 1;
	while (read_size > 0 && !ft_strchr_gnl(buf, 10))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (free(buf), free(stash), NULL);
		if (read_size == 0)
			break ;
		buf[read_size] = '\0';
		if (!stash)
			stash = ft_calloc_gnl(1, 1);
		temp = ft_strjoin_gnl(stash, buf);
		if (!temp)
		{
			free(stash);
			stash = NULL;
			return (free(buf), NULL);
		}
		stash = temp;
	}
	return (free(buf), stash);
}

//  Ajoute la stash a la line et cree la line
char	*ft_create_line(char **stash, ssize_t l)
{
	ssize_t	temp_size;
	ssize_t	line_size;
	char	*line;

	temp_size = ft_temp_size_gnl(*stash);
	line_size = ft_strlen_gnl(*stash) - temp_size;
	if (!(*stash)[0])
		return (free(*stash), NULL);
	line = malloc(sizeof(char) * line_size + 1);
	if (!line)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	while (l < line_size)
	{
		line[l] = (*stash)[l];
		l++;
	}
	line[l] = '\0';
	return (line);
}

// Recupere le debut de la ligne suivante
char	*ft_temp(char **stash)
{
	char	*temp;
	ssize_t	temp_size;
	ssize_t	j;
	ssize_t	i;

	temp_size = ft_temp_size_gnl(*stash);
	j = ft_strlen_gnl(*stash) - temp_size;
	i = 0;
	temp = malloc(sizeof(char) * temp_size + 1);
	if (!temp)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	while ((*stash)[j] != '\0')
	{
		temp[i] = (*stash)[j];
		j++;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

// Creation de la nouvelle stash si il y a temp
char	*ft_new_stash(char **stash)
{
	char	*temp;
	ssize_t	temp_size;
	ssize_t	j;
	ssize_t	i;

	temp_size = ft_temp_size_gnl(*stash);
	j = ft_strlen_gnl(*stash) - temp_size;
	i = 0;
	if (temp_size <= 0)
		return (free(*stash), NULL);
	temp = malloc(sizeof(char) * temp_size + 1);
	if (!temp)
		return (free(*stash), NULL);
	while ((*stash)[j] != '\0')
		temp[i++] = (*stash)[j++];
	temp[i] = '\0';
	free (*stash);
	*stash = malloc(sizeof(char) * temp_size + 1);
	if (!stash)
		return (free(*stash), NULL);
	i = -1;
	while (temp[++i] != '\0')
		(*stash)[i] = temp[i];
	(*stash)[i] = '\0';
	return (free(temp), *stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		*buf;
	ssize_t		l;
	ssize_t		read_size;

	read_size = 1;
	if (read(fd, NULL, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	buf = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	stash[fd] = ft_read_and_stash(fd, stash[fd], buf, read_size);
	if (!stash[fd])
		return (NULL);
	l = 0;
	line = ft_create_line(&stash[fd], l);
	if (!line)
		return (NULL);
	if (line)
		stash[fd] = ft_new_stash(&stash[fd]);
	return (line);
}
