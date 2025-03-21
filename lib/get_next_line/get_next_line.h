/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asritz <asritz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:16:04 by asritz            #+#    #+#             */
/*   Updated: 2024/07/16 18:31:50 by asritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
ssize_t	ft_strlen_gnl(char *str);
int		ft_strchr_gnl(const char *s, int c);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
char	*ft_strjoin_gnl(char *s1, char *s2);
ssize_t	ft_temp_size_gnl(char *stash);

#endif
