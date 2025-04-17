/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:16:47 by aule-bre          #+#    #+#             */
/*   Updated: 2025/04/18 19:39:16 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*gnl_no_newline(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (ft_strncmp(line, "\n", 2) == 0)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_map(int fd)
{
	char	*line;
	char	*map_content;
	char	*new_map_content;

	line = gnl_no_newline(fd);
	if (!line)
		return (close(fd), printf(ERROR EMPTY_MAP_FILE), NULL);
	map_content = NULL;
	while (line)
	{
		new_map_content = ft_strjoin(map_content, line);
		free(map_content);
		if (!new_map_content)
			return (close(fd), printf(ERROR ERROR_MALLOC), NULL);
		map_content = new_map_content;
		free(line);
		line = gnl_no_newline(fd);
	}
	close(fd);
	return (map_content);
}

char	*skip_nl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && ft_strncmp(line, "\n", 2) == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

/*
char	*xxget_map(int fd)
{
	while (line && ft_strncmp(line, "\n", 2) == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		tmp = res;
		res = ft_strjoin(res, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (find_str(res, "\n\n"))
		return (printf(ERROR INVALID_BORDERS), free(res), NULL);
	return (res);
}
*/

char	*get_elements(int fd)
{
	int		nb_elt;
	char	*line;
	char	*res;
	char	*tmp;

	res = NULL;
	nb_elt = 0;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), printf(ERROR EMPTY_MAP_FILE), NULL);
	while(line && nb_elt < 6)
	{
		if (ft_strncmp(line, "\n", 2) != 0)
		{
				tmp = line;
				line = ft_strtrim(line, " ");
				free(tmp);
				tmp = res;
				res = ft_strjoin(res, line);
				free(tmp);
				nb_elt++;
		} free(line); if (nb_elt < 6) line = get_next_line(fd); }
	return (res);
}

char	*check_and_get_elts(int fd)
{
	char	*res;

	res = get_elements(fd);
	if (res)
		printf(C"[%s]\n"RST, res);
	res = get_next_line(fd);
	res = ft_strjoin(res, skip_nl(fd));
	if (res)
		printf(Y"[%s]"RST, res);
//	res = get_the_map()
	close (fd);
	return (res);
}

char	*open_map(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (printf(ERROR ERROR_OPEN), NULL);
<<<<<<< HEAD
	return (check_and_get_elts(fd));
=======
	return (get_file_content(fd));
>>>>>>> 7f36821 (update: parsing: try to handle nl in map)
}

bool	check_map_format(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len > 4)
		if (ft_strncmp(&map_file[len - 4], ".cub", 5) == 0)
			return (true);
	return (false);
}

/*
 * =====[ work in progress ]=====
 */
char	*extract_elements(int fd)
{
	int		nb_elt;
	char	*line;
	char	*res;
	char	*tmp;

	res = NULL;
	nb_elt = 0;
	line = get_next_line(fd);
	if (!line)
		return (printf(ERROR EELT), NULL);
	while(line && nb_elt < 6)
	{
		if (ft_strncmp(line, "\n", 2) != 0)
		{
				tmp = line;
				line = ft_strtrim(line, " ");
				free(tmp);
				tmp = res;
				res = ft_strjoin(res, line);
				free(tmp);
				nb_elt++;
		}
		free(line);
		if (nb_elt < 6)
			line = get_next_line(fd);
	}
	return (res);
}

char	*skip_nl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && ft_strncmp(line, "\n", 2) == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (NULL);
}


int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*extract_map(int fd)
{
	char	*line;
	char	*tmp;
	char	*map;

	map = NULL;
	line = get_next_line(fd);
	if (!line)
		return (printf(ERROR EEXTRACT), NULL);
	while (line)
	{
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}

bool	ignore_nl_from_bottom_and_find_str(char *big, char *little)
{
	int	i;
	int	j;

	(void)j;
	(void)little;
	i = ft_strlen(big);
	while (i >= 0 && big[i] == '\n')
		i--;
	while (i >= 0)
	{
		if (big[i] == '\n')
		{
			j = ft_strlen(little) - 1;
			while(j >= 0 && little[j] == big[i])
			{
				j--;
				i--;
			}
			if (j == 0)
				return (true);
		}
		i--;
	}
	return (false);
}

char	*get_file_content(int fd)
{
	char	*res;
	char	*tmp;

	res = extract_elements(fd);
	if (!res)
		return (close(fd), NULL);
	tmp = res;
	res = ft_strjoin(res, skip_nl(fd));
	free(tmp);
	if (!res)
		return (close(fd), NULL);
	tmp = res;
	res = ft_strjoin(res, extract_map(fd));
	free(tmp);
	if (ignore_nl_from_bottom_and_find_str(res, "\n\n"))
		return(close(fd), printf(ERROR INVALID_BORDERS), NULL);
	close(fd);
	return (res);
}
